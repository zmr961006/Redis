/*************************************************************************
	> File Name: string_redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月08日 星期一 19时37分53秒
 ************************************************************************/

#ifndef _STRING_REDIS_H
#define _STRING_REDIS_H
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cassert>

#define  STRING_MAX      (1024 * 1024)  /*最大字符串长度*/
#define  FREE_STR(n)     (LEN_STR(n) - n)  /*初始化时空闲长度*/
#define  LEN_STR(n)      (n * 2)           /*预分配一倍额外长度*/

#define  DEFAULT_SIZE_MAX    (1<<2)        /*默认空字符串长度*/
#define  DEFAULT_SIZE        (1<<7)        /*默认字符串长度*/


/*自己实现的string类*/
/*带有预分配策略，每次会比字符串多一倍大小*/
class  String{
    private:
        char * sds;                        /* 指针 */
        int size;                          /*字符串已经使用长度*/
        int free;                          /*空闲长度*/
    public:
        String(const char * s);
        String();
        String(const char *s,int len);
        String(const String & st);
        ~String();
        

        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        
        friend bool operator<(const String &st,const String &st2);
        friend bool operator>(const String &st,const String &st2);
        friend bool operator==(const String &st,const String &st2);
        friend std::ostream & operator<<(std::ostream & os,const String &st2);
        friend std::istream & operator>>(std::istream & is,String & st);

        int getsize()const;
        int getfree()const;
        String & StringAdd(const String & st2);
        String & StringAdd(const char *s);
        String & StringClear(String & st);
        String & StringSizeClear(String & st,int len);
        String & StringUpDate(const char *s);
        String & StringUpDate(const String & st);
};



#endif
