/*************************************************************************
	> File Name: Data_Base.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月18日 星期四 22时27分41秒
 ************************************************************************/

#ifndef _DATA_BASE_H
#define _DATA_BASE_H

#include"./Data_table.h"

class Data_Base{

    private:
        Data_Table  Data_b[16];      /*这是一个数据库的实例,具有16张表*/
        int mask;
        int key_count;
    public:
        Data_Base();
        bool Data_Base_create(const char *key_name,int type_data,void *obj,int elem);
        bool Data_Base_del(const char *key_name);
	bool Data_Base_add(const char *key_name,int type_data,void *obj,int elem,const char *hash_key);
        bool Data_Base_find(const char *key_name,int type_data,void *obj,int elem,void *getbuff,const char *hash_key);
        bool Data_Base_set(const char *key_name,int type_data,void *obj,int elem,const char *hash_key);
        unsigned int Data_Base_gethash(const void *key);
          
};



#endif
