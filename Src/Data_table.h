/*************************************************************************
	> File Name: Data_table.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月18日 星期四 22时11分47秒
 ************************************************************************/

#ifndef _DATA_TABLE_H
#define _DATA_TABLE_H

#include<mutex>
#include<thread>
#include<condition_variable>
#include"./Key_val.h"
class Data_Table{

    private:
        mutable std::mutex mutex_;
        Key_Val_Node *head;
        Key_Val_Node *tail;
        int keys_count;

    public:
        Data_Table();
        bool Data_Table_Init();
        bool Data_Table_create(unsigned int Hash,const char *key_name,void *obj,int type_data,int elem);
        bool Data_Table_add(unsigned int Hash,const char *key_name,void *obj,int type_data,int elem,const char *hash_key);
        bool Data_Table_del(unsigned int Hash,const char *key_name,void *obj,int type_data,int elem);
        bool Data_Table_find(unsigned int Hash,void *obj,int type_data,unsigned int index,const char *key_name,void *getbuff,const char *hash_key);
        bool Data_Table_set(unsigned int Hash,void *obj,int type_data,unsigned int index,const char *key_name,const char *hash_key);
	int  Data_Table_count();
        


};

#endif
