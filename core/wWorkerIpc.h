
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#ifndef _W_WORKER_IPC_H_
#define _W_WORKER_IPC_H_

#include <algorithm>
#include <vector>
#include <sys/epoll.h>
#include "wCore.h"
#include "wStatus.h"
#include "wNoncopyable.h"

namespace hnet {

class wTask;
class wWorker;

class wWorkerIpc : public wNoncopyable {
public:
	wWorkerIpc(wWorker *worker);
	~wWorkerIpc();

	wStatus Prepare();
	wStatus Start();
	
	static void ChannelIpc(void* arg);

protected:
    // 事件读写主调函数
    wStatus Recv();

	wStatus InitEpoll();
    wStatus AddTask(wTask* task, int ev = EPOLLIN, int op = EPOLL_CTL_ADD, bool newconn = true);
    wStatus RemoveTask(wTask* task);
    wStatus CleanTask();

    wStatus AddToTaskPool(wTask *task);
    std::vector<wTask*>::iterator RemoveTaskPool(wTask *task);
    wStatus CleanTaskPool();

	wStatus mStatus;
	wWorker *mWorker;
	
	int32_t mEpollFD;
	uint64_t mTimeout;
	
	// task|pool
	wTask *mTask;
	std::vector<wTask*> mTaskPool;
};

}	// namespace hnet

#endif