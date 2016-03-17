/*************************************************************************
	> File Name: Hash_Map_redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月13日 星期六 01时20分22秒
 ************************************************************************/

#ifndef _HASH_MAP_REDIS_H
#define _HASH_MAP_REDIS_H

#include<iostream>
#include<string>
#include<memory>
#include<list>
//#include"./string_redis.cpp"

//static  int  Redis_for_rehash    10     模板类进CPP

#define hash_len 8

template <typename T>

class Key_Val{
    private:
        String Key_string;
        unsigned int Key ;
        //std::shared_ptr<T> ial;
        //std::auto_ptr<T> val;
        T  *val;
    public:
        Key_Val(){}
        Key_Val(const char *,const T  & data);
        unsigned int Key_Val_Get(const char *);
        unsigned int _Key_Val_Get(const char *,int);
	    unsigned int GetKey_int(unsigned int key);
        unsigned int GetKey_char(const void *,int );
        unsigned int & getkey(){return Key;}
        ~Key_Val();
        bool Key_Val_Show();  
        T & Key_Val_getval();
};
template<typename T>
unsigned Key_Val<T>::GetKey_int(unsigned int key){
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3);
    key ^=  (key >> 6);
    key +=~ (key << 11);
    key ^=  (key >> 16);
    return key;
}

template<typename T>
unsigned int Key_Val<T>::GetKey_char(const void *key,int len){
    
    uint32_t seed = 5635;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    uint32_t h = seed ^ len;
    const unsigned char *data = (const unsigned char *)key;

    while(len >= 4){
        uint32_t k = *(uint32_t *)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
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

template <typename T>
bool Key_Val<T>::Key_Val_Show(){
    std::cout<< Key_string << "   " << *((T *)val) << std::endl;
    //std::cout<< sizeof(*this)<< std::endl;

}

template <typename T>
Key_Val<T>::~Key_Val(){
    std::cout << "byby" << std::endl;
    delete val;
}

template <typename T>
unsigned int Key_Val<T>::Key_Val_Get(const char * key_name){
    int len;
    len = std::strlen(key_name);
    return Key_Val_Get(key_name,len);
}

template <typename T>
unsigned int Key_Val<T>::_Key_Val_Get(const char * key_name,int len){
    // hash_map_fun();   
}

template <typename T>

Key_Val<T>::Key_Val(const char * key_name, const T & data){
    //val = new std::auto_ptr<T>(data);
    Key_string= key_name;
    //std::cout << data ;
    //std::shared_ptr<T>  val (new T(data));
    //std::auto_ptr<T> val(new T(data));
    val = new T(data);
    int len = std::strlen(key_name);
    Key = GetKey_char(key_name,len);
}

template <typename T>

T & Key_Val<T>::Key_Val_getval(){
    return val;    
}



template<typename T>

class Hash_Map_KV{
    private:
        String name; /*哈希表的名字*/
        //std::list<Key_Val<T> > data1[4];
        //std::list<Key_Val<T> > data2[4];
        std::list<Key_Val<T> > data1[4];
        int key_len  ;
        int key_count;
        int mask     ;
    public:
        Hash_Map_KV(){}
        Hash_Map_KV(const char *s,int len):name(s),key_len(len),key_count(0),mask(4){}
        ~Hash_Map_KV(){}
        unsigned int GetKey_int(unsigned int key);
        unsigned int GetKey_char(const void *,int );
        Key_Val<T> & Find(const char *);
        int & Get_hash_len();
        int & Get_hash_count();
        int & Get_hash_mask(int m){mask = m;}
        bool Hash_Map_add(const char* key,const T & data);
        bool Get_hash_show();
        Key_Val<T> & Get_hash_node();
        
        
};

template <typename T>
Key_Val<T> & Hash_Map_KV<T>::Find(const char *key){
    unsigned int Key = GetKey_char(key,hash_len);
    /*typename  std::list<Key_Val<T> >::iterator it;

    for(it = data1[Key%4].begin();it!= data1[Key%4].end();it++){
        if((  *it).getkey() == Key){
            return *it;
        }
    }*/
    (*data1[Key%4]).Key_Val_Show();
}

template <typename T>
bool Hash_Map_KV<T>::Get_hash_show(){
    for(int i = 0; i < 4 ;i++){
            
    }
}

template<typename T>
bool Hash_Map_KV<T>::Hash_Map_add(const char * key,const T  & data){
    
    Key_Val<T> *node;
    node = new Key_Val<T>(key,data);
    int get = node->getkey();
    data1[(get & mask)].push_front(* node);
    
}

template<typename T>
int & Hash_Map_KV<T>::Get_hash_count(){
    return key_count;
}

template<typename T>
int & Hash_Map_KV<T>::Get_hash_len(){
    return key_len;
}


template<typename T>
unsigned Hash_Map_KV<T>::GetKey_int(unsigned int key){
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3);
    key ^=  (key >> 6);
    key +=~ (key << 11);
    key ^=  (key >> 16);
    return key;
}

template<typename T>
unsigned int Hash_Map_KV<T>::GetKey_char(const void *key,int len){
    
    uint32_t seed = 5635;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    uint32_t h = seed ^ len;
    const unsigned char *data = (const unsigned char *)key;

    while(len >= 4){
        uint32_t k = *(uint32_t *)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
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
