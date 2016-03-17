/*************************************************************************
	> File Name: Data_All.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月18日 星期四 22时40分41秒
 ************************************************************************/

#ifndef _DATA_ALL_H
#define _DATA_ALL_H


#include"./Data_table.h"
#include"./Data_Base.h"
#include"./Key_val.h"

/*此类的一些说明*/
/*参数解释：
	@key_name   :  键值对的键
	@type_data  :  键值对的类型
	@Data_ID    :  数据库ID，默认为0号数据库
	@obj        :  键值对的值，为void * 类型
	@index      :  伪哈希表，和整数类集合的参数，有以下的一些情况
			创建时：表示整数集的总元素个数，伪哈希表的预创建元素个数，这个版本不支持随意添加个数和类型升级
                        修改时：直接访问整数类集合的元素下标
	@hash_key   :  哈希表类以及伪哈希表的参数，表示哈希表内部的键
*/



class Data_All{

    private:
        Data_Base Data_A[16];        /*每个服务器有16个数据库实例*/
        int key_count;
        int server_id;
        int thread_pool;
    public:
        Data_All();
	bool Data_All_create(const char *key_name,int type_data,int Data_ID,void *obj,int index);
	bool Data_All_add(const char *key_name,int type_data,int Data_ID,void *obj,int index,const char *hash_key);
	bool Data_All_del(const char *key_name,int type_data,int Data_ID,void *obj,int index);
	bool Data_All_find(const char *key_name,int type_data,int Data_ID,void *obj,int index,void *getbuff,const char *hash_key);
	bool Data_All_set(const char *key_name,int type_data,int Data_ID,void *obj,int index,const char *hash_key);
	int Data_All_keycount();


};





#endif
