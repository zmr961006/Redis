/*************************************************************************
	> File Name: Data_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月19日 星期五 21时18分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include"./Data_table.h"



Data_Table::Data_Table(){
    keys_count = 0;
}


bool Data_Table::Data_Table_add(unsigned int Hash,const char *key_name,void *obj,int type_data,int index,const char *hash_key){
    std::lock_guard<std::mutex> lock(mutex_);
   
    Key_Val_Node *temp;
    for(temp = head;temp != NULL;temp = temp->next){
	
        if(temp->gethash_elem() == Hash){
		std::cout << "PPPPPPPP\n"<<  std::endl;
    		temp->add_elem(obj,type_data,index,key_name,hash_key);
		return true;
	}
    }
    return false;
    
}



bool Data_Table::Data_Table_create(unsigned int Hash,const char *key_name,void *obj,int type_data,int elem){
    
	 std::lock_guard<std::mutex> lock(mutex_);
    Key_Val_Node * keyval;
    std::string temp(key_name);
    keyval = new Key_Val_Node(Hash,temp,obj,type_data,elem);
    //std::cout << Hash << std::endl;
    if(keys_count == 0){
        head = tail = keyval;
	head->next = NULL;
	tail->next = NULL;
        keys_count++;
        std::cout << keys_count << std::endl;
    }else{
        
        keyval->prev = tail;
        tail->next   = keyval;
        keyval->next = NULL;
        if(keys_count == 1){
              head = tail;
        }
        tail = keyval      ;
	keys_count++;
          
    }
    
}

bool Data_Table::Data_Table_del(unsigned int Hash,const char *key_name,void *obj,int type_data,int elem){
    std::lock_guard<std::mutex> lock(mutex_);
    if(keys_count == 0){
        std::cout << "error no keys" << std::endl;
        return false;
    }
    Key_Val_Node *temp;
    unsigned int hash_temp;
    for(temp = head ;temp != NULL;temp = temp->next){
          hash_temp = temp->gethash_elem();
        if(hash_temp == Hash){  
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
	    return false;
        }
    }

}


bool Data_Table::Data_Table_set(unsigned int Hash,void *obj,int type_data,unsigned int index,const char *key_name,const char *hash_key){
    std::lock_guard<std::mutex> lock(mutex_);
    if(keys_count == 0){
        std::cout << "ERROR zero" << std::endl;
        return false;
    }
    Key_Val_Node *temp;
    for(temp = head;temp != NULL;temp = temp->next){
        if(temp->gethash_elem() == Hash){
            std::cout << "OKOKOKOKOKO\n";
            temp->set_elem(obj,type_data,index,key_name,hash_key);
            return true;
        }
    }
    return false;

}

bool Data_Table::Data_Table_find(unsigned int Hash,void *obj,int type_data,unsigned int index,const char *key_name,void *getbuff,const char *hash_key){
    std::lock_guard<std::mutex> lock(mutex_);
    if(keys_count == 0){
        std::cout << "Error no objs" << std::endl;
        return false;
    }
    Key_Val_Node *temp;
    unsigned int temp_hash;
    for(temp = head;temp != NULL;temp = temp->next){
	//std::cout << "~~~~~~temp->gethash_elem()\n" << temp->gethash_elem() << std::endl;
        temp_hash = temp->gethash_elem(); 
        std::cout << "the hash " << temp_hash << std::endl;
        if(temp_hash == Hash){
             DEBUG();
            temp->find_elem(obj,type_data,index,key_name,getbuff,hash_key);
	    //DEBUG();
            return true;
        }
    }
    return false;

}

int Data_Table::Data_Table_count(){
    
    return keys_count;

}



