/*************************************************************************
	> File Name: serv_work.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月27日 星期六 15时09分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include"./serv_work.h"


extern Data_All Data_Base;



void * work(char *buf){        /*集群分片处理位置*/

    struct mesg_body *info;
    info = (struct mesg_body *)malloc(sizeof(buf));
    info = (struct mesg_body *)buf;
    std::cout << info->cmd << " " << info->type <<" " << info->sockfd <<" " << info->operation << std::endl;
    bool result;
    result = DB_work(info);

}


void DB_work(struct mesg_body *info){
    
    int mod;
    mod = info->type ;

    if((mod & LIST_R) == LIST_R){
	if((mod & INT32_R) == INT32_R){
		if(strcmp(info->cmd,"LSET")==0){
			Data_Base.Data_All_create(info->key,info->type,info->Data_id,(void *)info->operation,0);	
                }else if(strcmp(info->cmd,"LDEL")==0){
			Data_Base.Data_All_del();
		}else if(strcmp(info->cmd,"LGET")==0){
			Data_Base.Data_All_find();
		}else if(strcmp(info->cmd,"LEXIT")==0){
			Data_Base.Data_All_exit();
		}else if(strcmp(info->cmd,"LADD")==0){
			Data_Base.Data_All_add();
		}

        }else if((mod & STRING_R ) == STRING_R){


        }
        
    }else if((mod & INT_SET_R) == INT_SET_R){\
	if((mod & INT32_R) == INT32_R){


        }else if((mod & STRING_R ) == STRING_R){


        }

    }else if((mod & HASH_MAP_R) == HASH_MAP_R){
	if((mod & INT32_R) == INT32_R){


        }else if((mod & STRING_R ) == STRING_R){


        }

    }else if((mod & HASH_MAP_RV) == HASH_MAP_RV){
	if((mod & INT32_R) == INT32_R){


        }else if((mod & STRING_R ) == STRING_R){


        }
        
    }else{
        
        if((mod & INT32_R) == INT32_R){


        }else if((mod & STRING_R ) == STRING_R){


        }

    }
    
    
}




