/*************************************************************************
	> File Name: int_set.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月16日 星期二 20时22分44秒
 ************************************************************************/

#ifndef _INT_SET_H
#define _INT_SET_H
/*整数集合*/
#include<vector>
#include<algorithm>

template <typename T>

class Set_Int{
    private:
        unsigned int N;
        std::vector<T> data;
        unsigned int Typename;
        unsigned int count;
    public:
        Set_Int(){}
        Set_Int(unsigned int n,T *da);
        bool Set_Int_set(T *da);
        T  Set_Int_back(unsigned int index);
        bool Set_Int_up(T update,unsigned int index);
        bool Set_Int_add(T add_date);
        bool Set_Int_bzero(unsigned int index);
        bool Set_Int_exit(T obj);
        bool Set_Int_sort();
        unsigned int Set_Int_mm();
        unsigned int Set_Int_balance();
        bool Set_Int_show();
	unsigned int & Set_Int_len();
	bool Set_Int_set(unsigned int index,T da);
};

template<typename T>
bool Set_Int<T>::Set_Int_set(unsigned int index,T da){
	data[index] = da;
	return true;
}


template <typename T>
unsigned int & Set_Int<T>::Set_Int_len(){
	return   N;
}

template <typename T>
bool Set_Int<T>::Set_Int_add(T add_date){
	
	data.push_back(add_date);
        N++;	

}


template <typename T>

bool Set_Int<T>::Set_Int_show(){
    for(int i = 0;i < N;i++){
        std::cout << data[i] << std::endl;
    }
}

template <typename T>
unsigned int Set_Int<T>::Set_Int_balance(){
    //
}
template <typename T>
Set_Int<T>::Set_Int(unsigned int n,T *da):N(n),count(0),data(n){
    Set_Int_set(da);
}

template <typename T>
bool Set_Int<T>::Set_Int_set(T *da){
    for(int i = 0; i < N;i++){
        data[i] = da[i];
    }
    return true;
}

template <typename T>
T  Set_Int<T>::Set_Int_back(unsigned int index){
    //std::cout << "KOKOKO\n"; 	    
    //std::cout << data[index] << std::endl;
    //std::cout << "KOKOKO\n";
    return data[index];
}

template <typename T>
bool Set_Int<T>::Set_Int_up(T update,unsigned int index){
    data[index] = update;
}

template <typename T>
bool Set_Int<T>::Set_Int_bzero(unsigned int index){
    data[index] = -1;
    N--;
    return true;
}

template <typename T>
bool Set_Int<T>::Set_Int_exit(T obj){
    for(int i = 0; i < N;i++){
        if(data[i] == obj){
            return true;
        }
    }
    return false;
}

template <typename T>
bool Set_Int<T>::Set_Int_sort(){
    sort(data.begin(),data.end());
}


template <typename T>
unsigned int  Set_Int<T>::Set_Int_mm(){
    return sizeof(data);
}
#endif


