/*************************************************************************
	> File Name: pseudo_hash_redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月10日 星期三 23时33分31秒
 ************************************************************************/

#ifndef _PSEUDO_HASH_REDIS_H
#define _PSEUDO_HASH_REDIS_H

#include<iostream>
#include<vector>

/*伪哈希表*/
/*当数据比较少的时候不用真正的哈希表，直接使用简单的伪哈希表*/


template <typename T,typename M>

class Hash_node{                    /*伪哈希表节点*/
    private:
        T data1;
        M data2;
    public:
        Hash_node(){}
        Hash_node(T d1,M d2);
        bool Hash_set(T d1,M d2);
        bool Hash_show();
        T &  Hash_key();
        M &  Hash_val();

};

template <typename T,typename M >
T & Hash_node<T,M>::Hash_key(){
    return data1;
}

template <typename T,typename M >
M & Hash_node<T,M>::Hash_val(){
    return data2;
}

template <typename T,typename M >
Hash_node<T,M>::Hash_node(T d1,M d2){
    data1 = d1;
    data2 = d2;
}
template <typename T,typename M >
bool Hash_node<T,M>::Hash_set(T d1,M d2){
    data1 = d1;
    data2 = d2;
}

template <typename T,typename M >
bool Hash_node<T,M>::Hash_show(){
    std::cout << data1 << "    " << data2 << std::endl;
}


template <typename T ,typename M>

class Hash_Map{
    private:
        int len;
        int use;
        std::vector<Hash_node<T,M> > data;
    public:
        Hash_Map(){}
        Hash_Map(int size):data(size),len(size),use(0){}
        bool Hash_Map_set(T d1,M d2);
        bool Hash_Map_show(int index);
        bool Hash_Map_show();
        bool Hash_Map_add(T d1,M d2);
        bool Hash_Map_del(T d1);
        M  Hash_Map_getval(T key);
        T & Hash_Map_getkey(M val);
        int & Hash_Map_length();
        int & Hash_Map_use();
  	bool Hash_Map_set_z(T d1,M d2);      

};

template <typename T,typename M>
bool Hash_Map<T,M>::Hash_Map_set_z(T d1,M d2){
	if(use < 1){
		std::cout << "ERROR\n";
		return false;
        }else{
                for(int i = 0;i < use;i++){
                        if(data[i].Hash_key()== d1){
                              data[i].Hash_set(d1,d2);
			      return true;
                         }
		}
	}
	return false;
}


template <typename T,typename M>
bool Hash_Map<T,M>::Hash_Map_set(T d1,M d2){
   data[use].Hash_set(d1,d2);
    use++;
}

template <typename T,typename M>
bool Hash_Map<T,M>::Hash_Map_show(){
    //std::cout << data[index].data1 << "   " << data[index].data2 << std::endl;
    for(int i = 0 ;i < use;i++){  
    
        data[i].Hash_show();
        std::cout << "ksksk\n";
    }
}

template <typename T,typename M>
bool Hash_Map<T,M>::Hash_Map_show(int index){
    
    data[index].Hash_show();

}

template <typename T,typename M>
bool Hash_Map<T,M>::Hash_Map_add(T d1,M d2){
    if(use < len){  
        data[use].Hash_set(d1,d2);
        use++;
        return true;
    }else{
        return false;
    }
}

template <typename T, typename M>
bool Hash_Map<T,M>::Hash_Map_del(T d1){
    for(int i = 0;i < len;i++){
        if(data[i].Hash_key == d1){
            data[i].Hash_set(T(NULL),M(NULL));
            break;
        }    
    }
}

template <typename T,typename M>
int & Hash_Map<T,M>::Hash_Map_length(){
    return len;
}

template <typename T,typename M>
int & Hash_Map<T,M>::Hash_Map_use(){
    return use;
} 
 
template <typename T,typename M>

T & Hash_Map<T,M>::Hash_Map_getkey(M d2){
    for(int i = 0;i < len;i++){
        if(data[i].Hash_val() == d2){
            return data[i].Hash_key();
        }
    }
    return NULL;
}

template <typename T,typename M>

M  Hash_Map<T,M>::Hash_Map_getval(T d1){
    for(int i = 0; i < len ;i++){
        if(data[i].Hash_key() == d1){
            return data[i].Hash_val();
        }
    }

    return 0;
}

#endif
