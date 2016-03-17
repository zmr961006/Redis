/*************************************************************************
	> File Name: mesg.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月26日 星期五 21时55分00秒
 ************************************************************************/

#ifndef _MESG_H
#define _MESG_H
#include<iostream>
#include<cstdio>
#include"./auto.h"
struct mesg_head{

    unsigned int length;
};

struct mesg_body{
    char cmd[10];
    char key[10];
    unsigned int type;
    unsigned int Data_id;
    unsigned int sockfd ;
    unsigned int length ;
    char operation[768];
};


#endif
