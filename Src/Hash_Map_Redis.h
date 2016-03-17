/*************************************************************************
	> File Name: Hash_Map_Redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月15日 星期一 14时53分26秒
 ************************************************************************/

#ifndef _HASH_MAP_REDIS_H
#define _HASH_MAP_REDIS_H

#include<iostream>
#include<memory>
#include<list>
#include<string>


#define HAH_LEN 8

template <typename T>

class Key_Val{
    
    private:
        std::string Key_string;
        unsigned int Key ;
        std::shared_ptr<T> val;
        
    public:
        Key_Val(){}
    	Key_Val(const std::string & str,unsigned int key,T data);
        ~Key_Val(){ val.reset();std::cout << "dd" << val.use_count() <<std::endl;};
        bool Key_Val_Show();
        T    Key_Val_getval();
        bool Key_Val_Set(T set_val);
        unsigned int & Key_Val_getkey();
};

template <typename T>
bool Key_Val<T>::Key_Val_Set(T set_val){

	*val = set_val;
	return true;
}


template <typename T>
Key_Val<T>::Key_Val(const std::string & str,unsigned int key,T d):val(new T(d)){
    Key_string = str;
    Key = key;
    //std::shared_ptr<T> va (new T(d));
    //val = va;
    //*val = (new T(d));
    
}

template <typename T>

bool Key_Val<T>::Key_Val_Show(){
    //std::cout << Key_string << " " << *((T*)val) << std::endl;  
    std::cout << Key_string << " " << ((*val)) << std::endl;  
}

template <typename T>

T  Key_Val<T>::Key_Val_getval(){
    /*std::cout << "~~~~~~" << std::endl;
    std::cout << val << std::endl;
    std::cout << "......" << std::endl;*/
    return *val;
}

template <typename T>

unsigned int & Key_Val<T>::Key_Val_getkey(){
    return Key;
}









#endif
