
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#ifndef _W_SERVER_H_
#define _W_SERVER_H_

#include <algorithm>
#include <vector>
#include <sys/epoll.h>

#include "wCore.h"
#include "wStatus.h"
#include "wNoncopyable.h"

namespace hnet {

class wTimer;
class wTask;
class wSocket;
class wMaster;

// 服务基础类
class wServer : private wNoncopyable {
public:
	wServer(string name);
	virtual ~wServer();

	// 事件读写主调函数
	void Recv();
	int Send(wTask *pTask, const char *pCmd, int iLen);
	void Broadcast(const char *pCmd, int iLen);
	
	/**
	 * single、worker进程中，准备|启动服务
	 */
	void PrepareSingle(string sIpAddr, unsigned int nPort, string sProtocol = "TCP");
	void SingleStart(bool bDaemon = true);
	
	/**
	 * master-worker用户多进程架构，准备|启动服务。（防止bind失败）
	 *
	 * PrepareMaster 需在master进程中调用
	 * WorkerStart在worker进程提供服务
	 */
	void PrepareMaster(string sIpAddr, unsigned int nPort, string sProtocol = "TCP");	
	void WorkerStart(bool bDaemon = true);
	virtual void HandleSignal();
	void WorkerExit();
	//int AcceptMutexLock();
	//int AcceptMutexUnlock();
	
	/**
	 * epoll event
	 */
	int InitEpoll();
	void CleanEpoll();
	/**
	 * 添加到epoll监听事件中
	 * @param  pTask [wTask*]
	 * @return       [是否出错]
	 */
	int AddToEpoll(wTask* pTask, int iEvents = EPOLLIN, int iOp = EPOLL_CTL_ADD);
    int RemoveEpoll(wTask* pTask);
	
	/**
	 *  Listen Socket(nonblock fd)
	 */
	int AddListener(string sIpAddr, unsigned int nPort, string sProtocol = "TCP");
	/**
	 * 添加Listen Socket到侦听事件队列中
	 */
	void Listener2Epoll();

	/**
	 *  accept接受连接
	 */
	int AcceptConn(wTask *pTask);
	int AddToTaskPool(wTask *pTask);
	void CleanTaskPool();
    std::vector<wTask*>::iterator RemoveTaskPool(wTask *pTask);
	int PoolNum() { return mTaskPool.size();}

	/**
	 * 新建客户端
	 */
	virtual wTask* NewTcpTask(wSocket *pSocket);
	virtual wTask* NewUnixTask(wSocket *pSocket);
	/**
	 * 服务主循环逻辑，继承可以定制服务
	 */
	virtual void PrepareRun() {}
	virtual void Run() {}
	
	string &ServerName() { return mServerName;}
	bool IsRunning() { return mStatus == SERVER_RUNNING;}
	SERVER_STATUS &Status() { return mStatus;}
	
	void CheckTimer();
	virtual void CheckTimeout();
	
protected:
	//int mErr;
	//int mExiting {0};
	friend class wServer;
	string mServerName;
	vector<wSocket *> mListenSock;	//多监听服务

	//SERVER_STATUS mStatus {SERVER_INIT};	//服务器当前状态
	
	// 服务器当前时间
	uint64_t mLastTicker;
	// 心跳开关，默认关闭。强烈建议移动互联网环境下打开，而非依赖keepalive机制保活
	bool mIsCheckTimer;
	// 定时器
	wTimer mCheckTimer;

	//epoll
	int mEpollFD;
	uint64_t mTimeout;	//epoll_wait timeout
	
	// epoll_event
	struct epoll_event mEpollEvent;
	vector<struct epoll_event> mEpollEventPool; //epoll_event已发生事件池（epoll_wait）
	int mTaskCount;	// = mTcpTaskPool.size();
	
	//task|pool
	wTask *mTask;		//temp task
	vector<wTask*> mTaskPool;
};

}	// namespace hnet

#endif