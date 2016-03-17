/*************************************************************************
	> File Name: AOF.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 12时07分24秒
 ************************************************************************/

#ifndef _AOF_H
#define _AOF_H

#include<iostream>
#include<mutex>
#include<thread>
#include<cstdlib>
#include<cstring>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<cstdio>

#define  AOF_LOG_MAXSIZE    256            /*每条日志默认256B = 0.25KB 大小*/
#define  AOF_LOG_ELEM       (1<<17)            /*每一个分配区默认1 << 16 = 65536条日志,大小为4MB*/
#define  AOF_LOG_AREA       5               /*每次大约有5个分配区在线，满负荷5*（16384）条日志为缓冲区*/


//typedef  char buffer[AOF_LOG_MAXSIZE]  BUFFER;

class AOF_FILE{
    private:
        int fd;
    public:
        std::mutex mutex_write;
        AOF_FILE();
};


class AOF_LOG{
    private:
        
        char    (*log_data)[AOF_LOG_MAXSIZE];
        AOF_FILE  FILE_WRITE;
        int useful;
                        
    public:
        std::mutex mutex_log;
        AOF_LOG();
        ~AOF_LOG();
        bool AOF_LOG_ADD(const char *mesg,int flag);
        bool WRITE();

};


class AOF_LOG_DO{
    private:
        AOF_LOG  aof_buffer[AOF_LOG_AREA];
        int useful;
        int resume;
    public:
        AOF_LOG_DO();
        bool AOF_LOG_add(const char *mesg);
        bool AOF_LOG_enforce_write();
        bool AOF_LOG_READ(char *get);
        int & AOF_LOG_getresume();
};







#endif
