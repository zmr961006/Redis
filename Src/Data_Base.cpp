/*************************************************************************
	> File Name: Data_Base.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月19日 星期五 22时40分23秒
 ************************************************************************/

#include<iostream>
#include"./Data_table.h"
#include"./Data_Base.h"

Data_Base::Data_Base(){
    mask = 16;
    key_count = 0;
}


unsigned int Data_Base::Data_Base_gethash(const void *key){
    uint32_t seed = 5635;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    int len = 8;
    uint32_t h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;
    
    while(len >= 4){
        uint32_t k = *(uint32_t *)data;

        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        
        data += 4;
        len -=  4;
    }

    switch(len){
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8 ;
        case 1: h ^= data[0]; h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return (unsigned int )h;
}


bool Data_Base::Data_Base_create(const char *key_name,int type_data,void *obj,int elem){
    unsigned int Hash;
    unsigned int flag;
    Hash = Data_Base_gethash(key_name);
    flag = Hash % 16;
    Data_b[flag].Data_Table_create(Hash,key_name,obj,type_data,elem);

}

bool Data_Base::Data_Base_add(const char *key_name,int type_data,void *obj,int elem,const char *hash_key){
    unsigned int Hash;
    unsigned int flag;
    Hash = Data_Base_gethash(key_name);
    flag = Hash % 16;
    Data_b[flag].Data_Table_add(Hash,key_name,obj,type_data,elem,hash_key);

}




bool Data_Base::Data_Base_del(const char *key_name){
    unsigned int Hash;
    unsigned int flag;
    Hash = Data_Base_gethash(key_name);
    flag = Hash % 16;
    Data_b[flag].Data_Table_del(Hash,key_name,NULL,0,0);
}

bool Data_Base::Data_Base_set(const char *key_name,int type_data,void *obj,int index,const char *hash_key){
    unsigned int Hash;
    unsigned int flag;
    Hash = Data_Base_gethash(key_name);
    flag = Hash % 16;
    Data_b[flag].Data_Table_set(Hash,obj,type_data,index,key_name,hash_key);

}

bool Data_Base::Data_Base_find(const char *key_name,int type_data,void *obj,int index,void *getbuff,const char *hash_key){
    unsigned int Hash;
    unsigned int flag;
    Hash = Data_Base_gethash(key_name);
    flag = Hash % 16;
    Data_b[flag].Data_Table_find(Hash,obj,type_data,index,key_name,getbuff,hash_key);
    //DEBUG();
}

