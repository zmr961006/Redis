/*************************************************************************
	> File Name: DSAA.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月17日 星期三 16时55分29秒
 ************************************************************************/

#ifndef _DSAA_H
#define _DSAA_H

/*数据结构相关*/


unsigned int gettype(char *);       /*根据解析的字符串来分析，类型*/
#define   INT32_R         1
#define   STRING_R        (1 << 1)
#define   LONG_R          (1 << 2)
#define   SHORT_R         (1 << 3)
#define   DOUBLE_R        (1 << 4)


#define   LIST_R          (1 << 6)
#define   INT_SET_R       (1 << 7)
#define   HASH_MAP_R      (1 << 8)
#define   HASH_MAP_RV     (1 << 9)


/***************cmd*****************/

/***************单个元素***********/

#define     SET     1       /*设置一个单个键值对1*/
#define     GET     (1<<1)  /*获得一个键的值2*/
#define     DEL     (1<<2)  /*删除一个键值对4*/
#define     EXIT    (1<<3)  /*确定存在与否8*/
#define     ADD     (1<<4)  /*添加一个子元素16*/

/**************链表操作*************/

#define     LSET    101    
#define     LGET    102
#define     LDEL    103
#define     LEXIT   104
#define     LADD    105

/*************整数集合操作*********/


#define     SSET    201 
#define     SGET    202
#define     SDEL    203
#define     SEXIT   204
#define     SADD    205


/*************哈希表操作**********/

#define     HSET    301
#define     HGET    302
#define     HDEL    303
#define     HEXIT   304
#define     HADD    305


/************伪哈希表操作********/

#define     HVSET   401
#define     HVGET   402
#define     HVDEL   403
#define     HVEXIT  404
#define     HVADD   405

/***********其它操作************/

#define   TIMESET   501
#define   TIMEGET   502










#endif
