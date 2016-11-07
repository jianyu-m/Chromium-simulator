
#ifndef BROWSER_THREAD_H
#define BROWSER_THREAD_H

#include "callback.hpp"
#include <queue>
#include <sys/types.h>

/* this class is used to implement a message loop callback */

class BrowserThread {
public:
  	std::queue<std::pair<CallbackFunc, CallbackArgs>> work_queue;
  	pthread_mutex_t lock;
    pthread_cond_t cv;
    pthread_t thread_id;
    bool running;
    BrowserThread();
  	void post_task(CallbackFunc callback, CallbackArgs args);
	bool run();
	void join();
};

#endif