//Rotem Zilberman 213231418
//Ohad Langer
#include "ThreadPool.h"

void ThreadPool::ThreadFunction() {
    while(true){
        Task *FirstTask;
        {
            while(true) {
                QueueMutex.lock();
                if (!tasks.empty()) {
                    FirstTask = tasks.front();
                    tasks.pop();
                    QueueMutex.unlock();
                    break;
                }
                QueueMutex.unlock();
            }
        }
        FirstTask->execute();
        delete(FirstTask);
    }
}
ThreadPool::ThreadPool(int size){
    for (int i = 0; i < size; i++){
        this->threads.emplace_back(std::mem_fn(&ThreadPool::ThreadFunction), this);
    }
}

ThreadPool::~ThreadPool() {
    for (std::thread &worker : threads) {
        worker.join();
    }
}

void ThreadPool::enqueue(Task *t) {
    tasks.push(t);
}