/*************************************************************************
	> File Name: serv_work.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月27日 星期六 15时09分03秒
 ************************************************************************/

#ifndef _SERV_WORK_H
#define _SERV_WORK_H

#include"./mesg.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstring>


/*函数功能：
 * 处理从网络中接收的数据，然后处理之*/


void * work(char * buf);   /*解析数据包*/
bool DB_work(struct mesg_body *info);  /*解析命令参数以及执行*/



#endif
