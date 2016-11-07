//
// Created by jianyu on 11/6/16.
//

#include <pthread.h>
#include "browser_thread.hpp"

void *message_loop(void *args) {
    BrowserThread *thread = (BrowserThread*)args;
    while(thread->running) {
        pthread_mutex_lock(&thread->lock);
        while (thread->work_queue.size() == 0) {
            pthread_cond_wait(&thread->cv, &thread->lock);
        }
        pthread_mutex_unlock(&thread->lock);
        std::pair<CallbackFunc, CallbackArgs> pair = thread->work_queue.front();
        thread->work_queue.pop();
        //callback
        (pair.first)(pair.second);
    }
    return NULL;
}

BrowserThread::BrowserThread() {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cv, NULL);
    running = false;
}

void BrowserThread::post_task(CallbackFunc callback, CallbackArgs args) {
    pthread_mutex_lock(&lock);
    work_queue.push(std::make_pair(callback, args));
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&lock);
}

bool BrowserThread::run() {
    pthread_create(&thread_id, NULL, message_loop, this);
    running = true;
    return true;
}

void BrowserThread::join() {
    pthread_join(thread_id, NULL);
}