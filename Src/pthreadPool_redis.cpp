/*************************************************************************
	> File Name: pthreadPool_redis.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月09日 星期二 22时39分47秒
 ************************************************************************/

#include "./pthreadPool_redis.h"

ThreadPool::ThreadPool(const std::string &name)           /*创建线程池*/
    :name_(name),
     maxQueueSize_(0),
     running_(false)
{
    
}


ThreadPool::~ThreadPool(){                             /*销毁线程池*/
    if(running_){
        stop();
    }
}

void ThreadPool::start(int threadNums){                /*创建指定线程个数，待命*/
    assert(threads_.empty() && threadNums > 0);
    running_ = true;
    threads_.reserve(threadNums);
    for(int i = 0; i < threadNums;i++){
        threads_.push_back(new std::thread(&ThreadPool::threadFunc,this));
    }
}


void ThreadPool::stop(){                              /*  惊醒所有线程准备销毁 */
    {
        std::lock_guard<std::mutex> lock(mutex_);
        running_ = false;
        notEmptyCond_.notify_all();

    }
    for(auto &thread : threads_){
        thread->join();
        delete thread;
    }
}

void ThreadPool::putTask(Task task){                /*接收任务，*/
    if(threads_.empty()){
        task();
    }else{
        std::unique_lock<std::mutex> lock(mutex_);
        while(isFull()){
            notFullCond_.wait(lock);

        }
        assert(!isFull());
        queue_.push_back(task);         
        notEmptyCond_.notify_one();
    }
}

ThreadPool::Task ThreadPool::take(){
    std::unique_lock<std::mutex> lock(mutex_);
    while(queue_.empty() && running_){
        notEmptyCond_.wait(lock);
    }
    Task task;
    if(!queue_.empty()){
        task = queue_.front();
        queue_.pop_front();
        if(maxQueueSize_ > 0){
            notFullCond_.notify_one();
        }
    }
    return task;
}

void ThreadPool::threadFunc(){
    if(threadInitCallback_){
        threadInitCallback_();
    }

    while(running_){
        Task task(take());
        if(task){
            task();
        }
    }
}
