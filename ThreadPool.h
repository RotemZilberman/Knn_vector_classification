//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART4_THREADPOOL_H
#define ADVANCED_PROGRAMIN_PART4_THREADPOOL_H

#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include "Task.h"

class ThreadPool {
public:
    /**
     * is the size of the pull
     * @param size is the size
     */
     ThreadPool(int size);
     /**
      * decostructor
      */
     ~ThreadPool();
     /**
      * add new task
      * @param t is the task
      */
     void enqueue(Task *t);
private:
    std::vector<std::thread> threads;
    std::queue<Task*> tasks;
    std::mutex QueueMutex;
    void ThreadFunction();
};


#endif //ADVANCED_PROGRAMIN_PART4_THREADPOOL_H
