
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#include "wWorker.h"
#include "wMisc.h"
#include "wSigSet.h"
#include "wMaster.h"
#include "wConfig.h"
#include "wServer.h"
#include "wChannelSocket.h"

namespace hnet {

wWorker::wWorker(std::string title, uint32_t slot, wMaster* master) : mMaster(master), mTitle(title), mPid(-1),
mPriority(0), mRlimitCore(kRlimitCore), mSlot(slot) {
	SAFE_NEW(wChannelSocket(kStConnect), mChannel);
}

wWorker::~wWorker() {
	SAFE_DELETE(mChannel);
}

const wStatus& wWorker::PrepareStart() {
	// 设置当前进程优先级。进程默认优先级为0
	// -20 -> 20 高 -> 低。只有root可提高优先级，即可减少priority值
	if (mSlot < kMaxProcess && mPriority != 0) {
        if (setpriority(PRIO_PROCESS, 0, mPriority) == -1) {
			return mStatus = wStatus::IOError("wWorker::PrepareStart, setpriority() failed", error::Strerror(errno));
        }
    }
	
	// 设置进程的最大文件描述符
    if (mRlimitCore > 0) {
		struct rlimit rlmt;
        rlmt.rlim_cur = static_cast<rlim_t>(mRlimitCore);
        rlmt.rlim_max = static_cast<rlim_t>(mRlimitCore);
        if (setrlimit(RLIMIT_NOFILE, &rlmt) == -1) {
        	wStatus::IOError("wWorker::PrepareStart, setrlimit(RLIMIT_NOFILE) failed", error::Strerror(errno));
        	//return mStatus = wStatus::IOError("wWorker::PrepareStart, setrlimit(RLIMIT_NOFILE) failed", error::Strerror(errno));
        }
    }
	
    // 每个worker进程，只保留自身worker进程的channel[1]与其他所有worker进程的channel[0]描述符
    // [1] [0] [0] ...
    for (uint32_t n = 0; n < kMaxProcess; n++) {
    	// 将其他进程的channel[1]关闭，自己的除外
    	if (n == mSlot || mMaster->Worker(n) == NULL || mMaster->Worker(n)->mPid == -1) {
    		continue;
    	} else if (close(mMaster->Worker(n)->ChannelFD(1)) == -1) {
    		return mStatus = wStatus::IOError("wWorker::PrepareStart, channel close() failed", error::Strerror(errno));
    	}
    }
    // 关闭该进程worker进程的channel[0]描述符
    if (close(mMaster->Worker(mSlot)->ChannelFD(0)) == -1) {
    	return mStatus = wStatus::IOError("wWorker::PrepareStart, channel close() failed", error::Strerror(errno));
    }

	if (!(mStatus = PrepareRun()).Ok()) {
		return mStatus;
	}
	
    // 子进程标题
	if (!(mStatus = mMaster->Server()->Config()->Setproctitle(kWorkerTitle, mTitle.c_str(), false)).Ok()) {
		return mStatus;
	}
	return mStatus.Clear();
}

const wStatus& wWorker::Start() {
	// worker进程中重启所有信号处理器
	wSigSet ss;
	if (!(mStatus = ss.Procmask(SIG_SETMASK)).Ok()) {
		return mStatus;
	}

    if (!(mStatus = Run()).Ok()) {
    	return mStatus;
    }

    // 启动server服务
	return mStatus = mMaster->Server()->WorkerStart();
}

}	// namespace hnet
