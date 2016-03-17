




#include"./Key_val.h"



unsigned int Key_Val_Node::gethash_elem(){

	return hash;

}


bool Key_Val_Node::find_elem(void *obj,int type_data,unsigned int index,const char * key_name,void * getbuff,const char *hash_key){
	if((type_data & LIST_R) == LIST_R){
        	if((type_data & INT32_R)== INT32_R){
			int i = 0;
            		typename std::list<int>::iterator ob;
			for(ob = (*(std::list<int>*)data).begin(); ob != (*(std::list<int>*)data).end(); ob++){
				
				((int*)getbuff)[i] = (*ob);
				i++;
			}
        	}else{
            		int i = 0;
            		typename std::list<std::string>::iterator ob;
			for(ob = (*(std::list<std::string>*)data).begin(); ob != (*(std::list<std::string>*)data).end(); ob++){
				
				((std::string*)getbuff)[i] = (*ob);
				i++;
			}
            	
        	}
    }else if((type_data & INT_SET_R) == INT_SET_R){
	    if((type_data & INT32_R)== INT32_R){
           	unsigned int i = 0;
		int len = (*(Set_Int<int>*)data).Set_Int_len();
		for(i = 0;i < len;i++){
			((int *)getbuff)[i] = (*(Set_Int<int>*)data).Set_Int_back(i);
                         
		}
                
        }else{
         unsigned int i = 0;
		int len = (*(Set_Int<unsigned int>*)data).Set_Int_len();
		for(i = 0;i < len;i++){
			((unsigned int *)getbuff)[i] = (*(Set_Int<unsigned int>*)data).Set_Int_back(i);
                         
		}
        }
    }else if((type_data & HASH_MAP_R) == HASH_MAP_R){
	    if((type_data & INT32_R) == INT32_R){
            
            ((int *)getbuff)[0] =   (*(Hash_Map_V<int>*)data).Find(hash_key);
           
        }else{
	     std::cout << "OOOOPPPP" << hash_key << std::endl;
            ((std::string*)getbuff)[0] =   (*(Hash_Map_V<std::string>*)data).Find(hash_key);
        }
    }else if((type_data & HASH_MAP_RV) == HASH_MAP_RV){
        if((type_data & INT32_R)==INT32_R){
            
            std::string A(hash_key);
            ((int*)getbuff)[0]  =(*(Hash_Map<std::string,int>*)data).Hash_Map_getval(A);
        
        }else{
            std::string A(hash_key);
            ((std::string*)getbuff)[0]  =(*(Hash_Map<std::string,std::string>*)data).Hash_Map_getval(A);
            
        }
    }else{
	    if((type_data & INT32_R)==INT32_R){ 
            
            ((int*)getbuff)[0]  =  *((int*)data);
            std::cout << "*******" << std::endl;
            
        }else{
            
            ((std::string*)getbuff)[0] =  *((std::string*)data);
        }
    }

}





bool Key_Val_Node::set_elem(void *obj,int type_data,unsigned int index,const char * key_name,const char *hash_key){
	
	if((type_data & LIST_R) == LIST_R){
        
        if((type_data & INT32_R)== INT32_R){
             int temp = *(int*)obj;
             typename std::list<int>::iterator ob;
		for(ob = (*(std::list<int>*)data).begin(); ob != (*(std::list<int>*)data).end(); ob++){
				if(*ob == temp){
				     ob = (*(std::list<int>*)data).erase(ob);
				}
		}
                        
        }else{            
            std::string temp((const char *)obj);
              typename std::list<std::string>::iterator ob;
		for(ob = (*(std::list<std::string>*)data).begin(); ob != (*(std::list<std::string>*)data).end(); ob++){
				if(*ob == temp){
				     ob = (*(std::list<std::string>*)data).erase(ob);
				}
		}
                  
            
        }

    }else if((type_data & INT_SET_R) == INT_SET_R){
	    if((type_data & INT32_R)== INT32_R){
            int val = *((int*)obj);
            (*(Set_Int<int>*)data).Set_Int_set(index,val);    
        
        }else{
            
            unsigned int val = *((unsigned int *)obj);
            (*(Set_Int<unsigned int>*)data).Set_Int_set(index,val);
        }
    }else if((type_data & HASH_MAP_R) == HASH_MAP_R){
	    if((type_data & INT32_R) == INT32_R){
            
            int val = (*(int*)obj);
            //std::cout << "the hash_key and val "<< hash_key << " " << val << std::endl;
            (*(Hash_Map_V<int>*)data).Hash_Map_set(hash_key,val);
            //std::cout << "~~~~~~~\n";
        }else{
            std::string A((const char *)obj);
            
            (*(Hash_Map_V<std::string>*)data).Hash_Map_set(hash_key,A);
            
        }
    }else if((type_data & HASH_MAP_RV) == HASH_MAP_RV){
        if((type_data & INT32_R)==INT32_R){
            
             
            int val = *((int *)obj);
	    //std::cout << "the hash_key and val "<< hash_key << " " << val << std::endl;
            std::string temp(hash_key);
            (*(Hash_Map<std::string,int>*)data).Hash_Map_set_z(temp,val);
            //std::cout << "~~~~~~~~~~\n";
            
        }else{
                
            std::string val((const char *)obj);
            (*(Hash_Map<std::string,std::string>*)data).Hash_Map_set(hash_key,val);
            //(*(Hash_Map<std::string,std::string>*)data).Hash_Map_show();
            
        }
    }else{
	     if((type_data & INT32_R)==INT32_R){            
            DEBUG();
            int val = *((int *)obj);
            *((int*)data) = val;
            DEBUG();
        }else{
            DEBUG();
            std::string val = ( const char *)obj;
            *((std::string*)data) = val;
            DEBUG();
            std::cout << *((std::string*)data) << std::endl;
        }
    }

}



bool Key_Val_Node::add_elem(void *obj,int type_data,unsigned int index,const char * key_name,const char *hash_key){
	
	if((type_data & LIST_R) == LIST_R){
        
        if((type_data & INT32_R)== INT32_R){
            
            
            //DEBUG();
            (*(std::list<int>*)data).push_back(*(int*)obj);
            //DEBUG();
            
        }else{
            
            std::string temp((const char *)obj);
            //DEBUG();
            (*(std::list<std::string>*)data).push_back(temp);
            //DEBUG();
        }

    }else if((type_data & INT_SET_R) == INT_SET_R){
	    if((type_data & INT32_R)== INT32_R){
            //DEBUG();
            int val = *((int*)obj);
            
            (*(Set_Int<int>*)data).Set_Int_add(val);    
            //(*(Set_Int<int>*)data).Set_Int_show();
            //DEBUG();
        }else{
            
            unsigned int val = *((unsigned int *)obj);
            (*(Set_Int<unsigned int>*)data).Set_Int_add(val);
        }
    }else if((type_data & HASH_MAP_R) == HASH_MAP_R){
	    if((type_data & INT32_R) == INT32_R){
            //DEBUG();
            int val = (*(int*)obj);
            std::cout << "the res " << val << std::endl;
            (*(Hash_Map_V<int>*)data).Hash_Map_V_add(hash_key,val);
            //(*(Hash_Map_V<int>*)data).Get_hash_show(key_name);
            //DEBUG();
        }else{
            std::string A((const char *)obj);
            std::cout << "the key and val " << hash_key << " " << A << std::endl;
            (*(Hash_Map_V<std::string>*)data).Hash_Map_V_add(hash_key,A);
            //(*(Hash_Map_V<std::string>*)data).Get_hash_show(key_name);
            //DEBUG();
        }
    }else if((type_data & HASH_MAP_RV) == HASH_MAP_RV){
        if((type_data & INT32_R)==INT32_R){
            
            //DEBUG();
            int val = *((int *)obj);
            (*(Hash_Map<std::string,int>*)data).Hash_Map_add(hash_key,val);
            //(*(Hash_Map<std::string,int>*)data).Hash_Map_show();
            //DEBUG();
        }else{
            //DEBUG();    
            std::string val((const char *)obj);
            (*(Hash_Map<std::string,std::string>*)data).Hash_Map_add(hash_key,val);
            //(*(Hash_Map<std::string,std::string>*)data).Hash_Map_show();
            //DEBUG();
        }
    }else{
	    if((type_data & INT32_R)==INT32_R){            
            DEBUG();
            int val = *((int *)obj);
            *((int*)data) = val;
            DEBUG();
        }else{
            DEBUG();
            std::string val = ( const char *)obj;
            *((std::string*)data) = val;
            DEBUG();
            std::cout << *((std::string*)data) << std::endl;
        }
    }

}


Key_Val_Node::Key_Val_Node(unsigned int Hash,std::string key_name,void * obj,int type_data,int elem){
        hash = Hash;
        Key  = key_name;
        std::cout << (type_data & LIST_R) << std::endl;
    if((type_data & LIST_R) == LIST_R){
        
        if((type_data & INT32_R)== INT32_R){
            
            
            data = new std::list<int>;
            
            (*(std::list<int>*)data).push_front(*(int*)obj);
            
            
        }else{
            data = new std::list<std::string>;
            std::string temp((const char *)obj);
            (*(std::list<std::string>*)data).push_front(temp);
            ///std::cout << (*(std::list<std::string>*)data).front() << std::endl;

        }

    }else if((type_data & INT_SET_R) == INT_SET_R){
	    if((type_data & INT32_R)== INT32_R){
           //std::cout << "i am here\n";
            data = new Set_Int<int>(elem,(int *)obj) ;
            //(*(Set_Int<int>*)data).Set_Int_show();
        }else{
            data = new Set_Int<unsigned int>(elem,(unsigned int *)obj);
        }
    }else if((type_data & HASH_MAP_R) == HASH_MAP_R){
	if((type_data & INT32_R) == INT32_R){
            data = new Hash_Map_V<int>(key_name);
            //std::cout << *((int*)data) << std::endl;
        
        }else{

            data = new Hash_Map_V<std::string>(key_name);
            //std::cout << "i am here\n";
        }
    }else if((type_data & HASH_MAP_RV) == HASH_MAP_RV){
        if((type_data & INT32_R) == INT32_R){
            data = new Hash_Map<std::string,int>(elem);
        }else{
            data = new Hash_Map<std::string,std::string>(elem);
        }
    }else{
	if((type_data & INT32_R)){

        data = new int(*(int *)obj);
            std::cout << "end of class \n";
            //std::cout << (*(int*)data) << std::endl;
        }else{
            
            data = new std::string((const char *)obj);
            //std::cout << "end of class \n";
            //std::cout << *((std::string *)data) << std::endl;
        }
    }
        
        
}



