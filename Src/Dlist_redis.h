/*************************************************************************
	> File Name: Dlist_redis.h
	> Author: 
	> Mail: 
	> Created Time: 2016年02月10日 星期三 19时41分05秒
 ************************************************************************/

#ifndef _DLIST_REDIS_H
#define _DLIST_REDIS_H

/*双向链表模板，建议使用list/vector */
#include<memory>
//typedef std::shared_ptr<node> node;

template <typename T>


class List_Self{

    struct node{
        T data;
        node *prev;
        node *next;
        node(T t,node * p,node *n):data(t),prev(p),next(n){}
    };

    private:
        node * head ;    /*head of list*/
        node * tail ;    /*tail of list*/
        int list_len;    /*lehgth of list*/
        node * copy ;    /*copy of all list*/

    public:
        List_Self():head(NULL),tail(NULL),list_len(0){}
    template <int N>
        List_Self(T (&arr )[N]);
        List_Self(T  data);
        //List_Self(List_Self<T> & a);
        bool empty()const{return (!head || !tail);}
        operator bool()const{return !empty();}
        bool push_front(T);
        bool push_back(T);
        T pop_back();
        T pop_front();
        ~List_Self();
        int & show_length(){return list_len;}
        void show_list(); 
        bool Insert_list_behind(T data,T behind);
        bool Insert_list_frout(T data,T frout);
        T & get_data(); /*test*/
};
template <typename T>
T & List_Self<T>::get_data(){
    return head->data;
}

template <typename T>
bool List_Self<T>::Insert_list_behind(T data,T behind){
    node *temp,*new_node;
    temp = head;
    do{
        if(temp->data == data){
            break;
        }else{
            temp = temp->next;
        }

    }while(temp != tail);
    new_node = new node(behind,NULL,NULL);
    temp->next->prev = new_node;
    new_node->prev   = temp;
    new_node->next   = temp->next;
    temp->next       = new_node;
    list_len++;
}
template <typename T>
bool List_Self<T>::Insert_list_frout(T data,T frout){
    node *temp,*new_node;
    temp = head;
    do{
        if(temp->data == data){
            break;
        }else{
            temp = temp->next;
        }

    }while(temp != tail);
    new_node = new node(frout,NULL,NULL);
    temp->prev->next = new_node;
    new_node->prev   = temp->prev;
    new_node->next   = temp;
    temp->prev       = new_node;
    list_len++;

}

template <typename T>
void List_Self<T>::show_list(){
    node *temp;
    temp = head;
    for(int i = 0;i < list_len;i++){
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

template <typename T>
template <int N>
List_Self<T>::List_Self(T (&arr)[N]):head(NULL),tail(NULL),list_len(0),copy(NULL){
        for(int i = 0;i != N;i++){
        
            push_back(arr[i]);

        }    
}
template <typename T>
List_Self<T>::List_Self(T  data):head(NULL),tail(NULL),list_len(0),copy(NULL){

    push_back(data);
}

/*template <typename T>
List_Self<T>::List_Self(List_Self<T> & a){
    if(this == & a)
        return *this;

}*/



template <typename T>
List_Self<T>::~List_Self(){
        while(head){
            node *temp = head;
            head = head->next;
            delete temp;
        
        } 
    std::cout << "zmmr"<< std::endl;
    
}


template <typename T>

bool List_Self<T>::push_back(T data){    /*头插*/
    tail = new node(data,tail,NULL);
    if(tail->prev)
        tail->prev->next = tail;
    if(empty())
        head = tail;
    list_len++;
}

template <typename T>

bool List_Self<T>::push_front(T data){
    head = new node(data,NULL,head);
    if(head -> next)
        head->next->prev = head;
    if(empty())
        tail = head;
    list_len++;
}

template <typename T>

T List_Self<T>::pop_back(){
    if(empty())
        return NULL;
    node *temp = tail;
    T data(tail->data);
    tail = tail->prev;
    if(tail)
        tail->next = NULL;
    else
        head = NULL;
    list_len--;
    delete temp;
    return data;
}

template <typename T>

T List_Self<T>::pop_front(){
    if(empty())
        return NULL;
    node *temp = head;
    T data(head->data);
    head = head->next;
    if(head)
        head->prev = NULL;
    else
        tail = NULL;
    delete temp;
    list_len--;
    return data;
}


#endif
