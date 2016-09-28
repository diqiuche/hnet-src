
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#include "wConfig.h"
#include "wMisc.h"
#include "wSlice.h"
#include "tinyxml.h"    //lib tinyxml

namespace hnet {

wConfig::~wConfig() {
    SAFE_DELETE(mProcTitle);
}

// 参数形式 
// ./bin/server -?
// ./bin/server -d
// ./bin/server -h127.0.0.1  
// ./bin/server -h 127.0.0.1
wStatus wConfig::GetOption(int argc, const char *argv[]) {
    for (int i = 1; i < argc; i++) {
        const char* p = argv[i];
        if (*p++ != '-') {
            return mStatus = wStatus::InvalidArgument("wConfig::GetOption", "invalid option");
        }

        while (*p) {
            switch (*p++) {
            case '?':
                mShowHelp = true;  break;
            case 'v':
                mShowVer = true;   break;
            case 'd':
                mDaemon = true;    break;

            // 监听ip
            case 'h':
                if (*p) {
                    mHost = p;
                    goto next;
                }

                p = argv[++i]; // 多一个空格
                if (*p) {
                    mHost = p;
                    goto next;
                }
                return mStatus = wStatus::InvalidArgument("wConfig::GetOption", "option \"-h\" requires ip address");

            case 'p':
                uint64_t val;
                if (*p) {
                    std::string s = std::string(p);
                    if (logging::ConsumeDecimalNumber(&s, &val)) {
                        mPort = static_cast<uint16_t>(val);
                        goto next;
                    }
                }

                p = argv[++i]; // 多一个空格
                if (*p) {
                    std::string s = std::string(p);
                    if (logging::ConsumeDecimalNumber(&s, &val)) {
                        mPort = static_cast<uint16_t>(val);
                        goto next;
                    }
                }
                return mStatus = wStatus::InvalidArgument("wConfig::GetOption", "option \"-p\" requires port number");

            case 's':
                if (*p) {
                    mSignal = p;
                    goto next;
                }

                p = argv[++i]; // 多一个空格
                if (*p) {
                    mSignal = p;
                    goto next;
                }
                return mStatus = wStatus::InvalidArgument("wConfig::GetOption", "option \"-p\" requires signal");
            
            default:
                return mStatus = wStatus::InvalidArgument("wConfig::GetOption", "invalid option");
            }
        }
    next:
        continue;
    }

    return mStatus = InitProcTitle(argc, argv);
}

wStatus wConfig::InitProcTitle(int argc, const char *argv[]) {
    SAFE_NEW(wProcTitle(argc, argv), mProcTitle);
    if (mProcTitle == NULL) {
        return wStatus::IOError("wConfig::InitProcTitle", "new failed");
    }
    return mProcTitle->InitSetproctitle();
}

}   // namespace hnet