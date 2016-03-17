/*************************************************************************
	> File Name: AOF.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月24日 星期三 12时07分32秒
 ************************************************************************/

#include<iostream>
#include"./AOF.h"
using namespace std;


AOF_FILE::AOF_FILE(){
    
    fd = 0;

}

/********************************************************/



AOF_LOG::AOF_LOG(){             /*init  one pice of buffer*/
    
    log_data = new char[AOF_LOG_ELEM][AOF_LOG_MAXSIZE];
    
    useful   = 0;
      
}

AOF_LOG::~AOF_LOG(){
    
    delete [] log_data;

}

bool AOF_LOG::AOF_LOG_ADD(const char *mesg,int flag){
    
    int length = std::strlen(mesg);
    if(length != flag){
        /*两次大小不一样，这条日志可能有安全问题，直接返回错误*/
	    return false;
    }
    bzero(log_data[useful],AOF_LOG_MAXSIZE);
    memcpy(log_data[useful],mesg,AOF_LOG_MAXSIZE);
    useful++;
    if(useful == AOF_LOG_ELEM){
        WRITE();
    }
    return true;
}

bool AOF_LOG::WRITE(){
    
    /*while(1){
        if(FILE_WRITE.mutex_write.try_lock()){
            break;
        }
    }*/
    FILE *fp;
    //fd = open("LOG_AOF.log",O_RDWR|O_APPEND|O_CREAT,777);
    fp = fopen("LOG_AOF.log","ab+");
    if(!fp){
               /*这里如果失败应当尝试打开备用日志文件，暂时不处理*/
        return false;                                             
    }else{
        for(int i = useful;i > 0;i--){
	     
             //write(fd,log_data[i],AOF_LOG_MAXSIZE);
            fwrite(log_data[i],AOF_LOG_MAXSIZE,1,fp);
        }
        useful = 0;
        fclose(fp);
        FILE_WRITE.mutex_write.unlock();
        return true;
    }


}

/*******************************************************/

AOF_LOG_DO::AOF_LOG_DO(){
    useful = 0;
}




bool AOF_LOG_DO::AOF_LOG_add(const char *mesg){

    int length = std::strlen(mesg);
    if(length > AOF_LOG_MAXSIZE){
        return false;                               /*当遇到超大的日志信息应当存储进更大的另外一个文件，这里暂时返回错误*/
    }
    int get_mutex = 1;
    while(get_mutex){
        for(int id = 0;id < AOF_LOG_AREA; id++){     /*循环获取每一个缓冲区的锁找到一个可以添加日志的*/  
            if(aof_buffer[id].mutex_log.try_lock()){
                aof_buffer[id].AOF_LOG_ADD(mesg,length); 
                aof_buffer[id].mutex_log.unlock();
                get_mutex = 0;
                break;
            }
        }
    }

}

bool AOF_LOG_DO::AOF_LOG_enforce_write(){    
    for(int i = 0;i < AOF_LOG_AREA;i++){
        while(1){
            if(aof_buffer[i].mutex_log.try_lock()){
                break;
            }
        }
        aof_buffer[i].WRITE();
        aof_buffer[i].mutex_log.unlock();
        
    }
    return true;
}

bool AOF_LOG_DO::AOF_LOG_READ(char *get){
    FILE *fp;
    resume = 0;
    fp = fopen("LOG_AOF.log","rb");
    if(!fp){
        return false;
    }else{
        while(fread(get,AOF_LOG_MAXSIZE,1,fp)){
            //这是开机恢复信息程序，从AOF日志文件读取信息然后给解析程序恢复数据库
            resume++;
            //std::cout << get << std::endl;
        }
    }
    fclose(fp);
}

int & AOF_LOG_DO::AOF_LOG_getresume(){
    return resume;
}


