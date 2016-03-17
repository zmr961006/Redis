/*************************************************************************
	> File Name: pthreadPool_redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月09日 星期二 22时21分10秒
 ************************************************************************/

#ifndef _PTHREADPOOL_REDIS_H
#define _PTHREADPOOL_REDIS_H

#include <queue>
#include <vector>
#include <string>
#include <mutex>
#include <functional>
#include <thread>
#include <condition_variable>

#include <assert.h>

class noncopyable{                                         /*防止子类赋值和构造*/ 

    protected:
        noncopyable(){}
        ~noncopyable(){}
    private:
        noncopyable(const noncopyable &);
        const noncopyable &operator=(const noncopyable &);

};


class ThreadPool : private noncopyable{                   /*线程池主体*/
    
    typedef std::function<void()> Task;

    public:
        explicit ThreadPool(const std::string &name = std::string());
        ~ThreadPool();
        void start(int threadNums);
        void stop();
        void putTask(Task task);
    	void setThreadPoolinitCallback(Task callback){
        	threadInitCallback_ = callback;
    	}
    	void setMaxQueueSize(size_t maxSize){
        	maxQueueSize_ = maxSize;
    	}
    	size_t queueSize()const{
        	std::lock_guard<std::mutex> lock(mutex_);
        	return queue_.size();
    	}
    private:
    	bool isFull()const{
        	assert(!mutex_.try_lock());
        	return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;

    	}
    	Task take();
    	void threadFunc();
    private:
        std::string name_;
        size_t maxQueueSize_;           //最大线程队列长度
        bool running_;             
        mutable std::mutex mutex_;
        std::condition_variable notFullCond_;        //两个条件变量，判断线程池的状态
        std::condition_variable notEmptyCond_;
        
        Task threadInitCallback_;
        std::vector<std::thread*> threads_;         //线程ID 
        std::deque<Task>queue_;                     //任务队列
};


















#endif
