/*************************************************************************
	> File Name: user_fd.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月26日 星期五 21时23分54秒
 ************************************************************************/

#ifndef _USER_FD_H
#define _USER_FD_H

#include<iostream>
#include<netdb.h>
#include<fcntl.h>
#include<unistd.h>
#include<list>
#include<sys/scoket.h>

struct user_data{
    struct sockaddr user;
    int fd;
}


class User_list{
    private:
        
}




#endif
