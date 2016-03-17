/*************************************************************************
	> File Name: DSAA.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月17日 星期三 16时55分29秒
 ************************************************************************/

#ifndef _DSAA_H
#define _DSAA_H

#include<cstring>
#include<iostream>
#include<string>

unsigned int gettype(char *);

#define   INT32_R         1
#define   STRING_R        (1 << 1)
#define   LONG_R          (1 << 2)
#define   SHORT_R         (1 << 3)
#define   DOUBLE_R        (1 << 4)


#define   LIST_R          (1 << 6)
#define   INT_SET_R       (1 << 7)
#define   HASH_MAP_R      (1 << 8)
#define   HASH_MAP_RV     (1 << 9)



#endif
