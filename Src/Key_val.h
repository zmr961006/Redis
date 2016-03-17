/*************************************************************************
	> File Name: Key_val.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月16日 星期二 22时05分29秒
 ************************************************************************/

#ifndef _KEY_VAL_H
#define _KEY_VAL_H


//template <typename T>
#include"./DSAA.h"
#include"./DEBUG.h"
#include<list>
#include<string>
#include"./Hash_Map_Redis.h"
#include"./Hash_Map_Rredis.h"
#include"./pseudo_hash_redis.h"
#include"./int_set.h"
class Key_Val_Node{

    private:
        void * data;
        //std::shared_ptr<voivoicd> data;
        int type   ;
        unsigned int hash;
        std::string  Key;
        unsigned int create_time;
        unsigned int cut_time;
        int Server_ID        ;
        int  data_type       ;

    public:
        Key_Val_Node * next;
        Key_Val_Node * prev;
        Key_Val_Node(){}
        Key_Val_Node(unsigned int Hash,std::string key_name,void * obj,int type_data,int elem);
        ~Key_Val_Node(){delete (char*)data;}
        bool add_elem(void *obj,int type_data,unsigned int index,const char *key_name,const char *hash_key);
        bool del_elem(void *obj,int type_data,unsigned int index,const char * key_name);
        bool set_elem(void *obj,int type_data,unsigned int index,const char * key_name,const char *hash_key);
        bool find_elem(void *obj,int type_data,unsigned int index,const char * key_name,void *getbuff,const char *hash_key);
        bool find_type(int type_obj);
	unsigned int gethash_elem();
        
};




#endif
