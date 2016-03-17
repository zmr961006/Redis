/*************************************************************************
	> File Name: Hash_Map_Rredis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月15日 星期一 15时06分35秒
 ************************************************************************/

#ifndef _HASH_MAP_RREDIS_H
#define _HASH_MAP_RREDIS_H

#include<string>
#include<memory>
#include<iostream>
#include<list>
#include"./Hash_Map_Redis.h"
template <typename T>

class Hash_Map_V{
    private:
        std::string name;
        std::list<std::shared_ptr<Key_Val<T> > > data[4];
        std::list<std::shared_ptr<Key_Val<T> > > data_rehash[4];
        int key_count;
        int len;
        int mask;
    public:
        Hash_Map_V(){}
	~Hash_Map_V(){}
        Hash_Map_V(const std::string & hash_name):name(hash_name){}
   	bool Hash_Map_V_add(const char * elem,T  da);
        unsigned int GetKey_int(unsigned int key);
        unsigned int GetKey_char(const void *);
        T  Find(const char *);
        bool Hash_Map_set(const char * want,T &set);
	bool Hash_Map_del(const char *want);
        int & Get_hash_mask(int m){mask = m;}
        bool Get_hash_show(const char * find);

};

template <typename T>
bool Hash_Map_V<T>::Get_hash_show(const char *find){
	T  temp;
	temp = Find(find);
        //std::cout << "lalal\n" << std::endl;
	//std::cout << temp << std::endl;
	unsigned int  key = GetKey_char(find);
    	int flag = (key % 4);
	typename std::list<std::shared_ptr<Key_Val<T> > >::iterator obj;
        for(flag = 0;flag < 4;flag++){
    	for(obj = data[flag].begin();obj != data[flag].end();obj++){
        		(**obj).Key_Val_Show();
        }
}
}

template <typename T>
bool Hash_Map_V<T>::Hash_Map_del(const char *want){
    unsigned int  key = GetKey_char(want);
    int flag = (key % 4);
    typename std::list<std::shared_ptr<Key_Val<T> > >::iterator obj;
    for(obj = data[flag].begin();obj != data[flag].end();obj++){
        if((key) == (**obj).Key_Val_getkey()){
      
		obj = data[flag].erase(obj);
		return true;
        }
    }
    return false;
	

}
template <typename T>
bool Hash_Map_V<T>::Hash_Map_set(const char * want,T &set){
    unsigned int  key = GetKey_char(want);
    int flag = (key % 4);
    typename std::list<std::shared_ptr<Key_Val<T> > >::iterator obj;
    //std::cout << "find the key is " << key << "the mask is " << flag << std::endl;
    for(obj = data[flag].begin();obj != data[flag].end();obj++){
        if((key) == (**obj).Key_Val_getkey()){
            //std::cout << (**obj).Key_Val_getval() << std::endl;
		(**obj).Key_Val_Set(set);
		return true;
        }
    }
    return false;
}
template <typename T>
T  Hash_Map_V<T>::Find(const char * want_get){
    unsigned int  key = GetKey_char(want_get);
    int flag = (key % 4);
    typename std::list<std::shared_ptr<Key_Val<T> > >::iterator obj;
    //std::cout << "find the key is " << key << "the mask is " << flag << std::endl;
    for(obj = data[flag].begin();obj != data[flag].end();obj++){
        if((key) == (**obj).Key_Val_getkey()){
            //std::cout << (**obj).Key_Val_getval() << std::endl;
		return (**obj).Key_Val_getval();
	
        }
    }
}


template <typename T>
bool Hash_Map_V<T>::Hash_Map_V_add(const char * elem,T  da){
    unsigned int key = GetKey_char(elem);
    //std::cout << "in the key is " << key << "the mask is " << (key%4) << std::endl;
  
    std::shared_ptr<Key_Val<T> > new_node(new Key_Val<T>(elem,key,da));
    data[(key % 4)].push_back(new_node);
    return NULL;
}




template <typename T>
unsigned int Hash_Map_V<T>::GetKey_int(unsigned int key){
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3 );
    key ^=  (key >> 6 );
    key += ~(key << 11);
    key ^=  (key >> 16);
    return key;
}


template <typename T>
unsigned int Hash_Map_V<T>::GetKey_char(const void *key){
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




#endif
