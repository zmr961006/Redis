/*************************************************************************
	> File Name: Data_All.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月20日 星期六 21时36分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include"./Data_All.h"

Data_All::Data_All(){
	
	key_count = 0;
	server_id = 0;
        thread_pool = 3;

}

bool Data_All::Data_All_create(const char *key_name,int type_data,int Data_ID,void *obj,int index){
	int id = 0;
	Data_A[id].Data_Base_create(key_name,type_data,obj,index);
	return true;
}


bool Data_All::Data_All_add(const char *key_name,int type_data,int Data_ID,void *obj,int index,const char *hash_key){
	int id = 0;
	Data_A[id].Data_Base_add(key_name,type_data,obj,index,hash_key);
	return true;
}

bool Data_All::Data_All_del(const char *key_name,int type_data,int Data_ID,void *obj,int index){
	int id = 0;
	Data_A[id].Data_Base_del(key_name);
	return true;
}

bool Data_All::Data_All_find(const char *key_name,int type_data,int Data_ID,void *obj,int index,void *getbuff,const char *hash_key){
	int id = 0;
        Data_A[id].Data_Base_find(key_name,type_data,obj,index,getbuff,hash_key);
	return true;
}

bool Data_All::Data_All_set(const char *key_name,int type_data,int Data_ID,void *obj,int index,const char *hash_key){
	int id = 0;
	Data_A[id].Data_Base_set(key_name,type_data,obj,index,hash_key);
	return true;
}

int Data_All::Data_All_keycount(){
	return key_count;
}

