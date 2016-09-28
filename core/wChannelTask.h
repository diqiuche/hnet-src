
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#ifndef _W_CHANNEL_TASK_H_
#define _W_CHANNEL_TASK_H_

#include "wCore.h"
#include "wStatus.h"
#include "wTask.h"

namespace hnet {

class wSocket;
class wWorker;

class wChannelTask : public wTask {
public:
    wChannelTask(wSocket *socket, wWorker *worker = NULL);
    
    virtual const char* Name() {
		return "wChannelTask";
    }
    
    DEC_FUNC(ChannelOpen);
    DEC_FUNC(ChannelClose);
    DEC_FUNC(ChannelQuit);
    DEC_FUNC(ChannelTerminate);
    
protected:
    wWorker *mWorker;
};

}	// namespace hnet

#endif