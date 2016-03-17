#include"./DSAA.h"
#include<iostream>
#include<string>
#include<cstring>
unsigned int gettype(char *type){
    char main_type[20];
    char fu_type[20];
    int type_data = 0;
    int len = std::strlen(type);
    for(int i = 0;i < len;i++){
        if(type[i] == '&' ){
            if(i < len){
                for(int j = i;j < len;j++)
                    fu_type[i] = type[i];
            }
            break;
        }
        main_type[i] = type[i];
    }
    
    if(main_type){
        if(strcmp(main_type,"LIST_R") == 0){
            type_data |= LIST_R;
            if(strcmp(fu_type,"INT32_R") == 0){
                    type_data |= INT32_R;
            }else{
					type_data |= STRING_R;
			}
        }else if(strcmp(main_type,"INT_SET_R") == 0){
            type_data |= LIST_R;
            if(strcmp(fu_type,"INT32_R") == 0){
                    type_data |= INT32_R;
            }else{
 					type_data |= STRING_R;
			}
	    }else if(strcmp(main_type,"HASH_MAP_R") == 0){
            type_data |= LIST_R;
            if(strcmp(fu_type,"INT32_R") == 0){
                    type_data |= INT32_R;
            }else{
					type_data |= STRING_R;
			}
	    }else if(strcmp(main_type,"HASH_MAP_RV") == 0){
            type_data |= LIST_R;
            if(strcmp(fu_type,"INT32_R") == 0){
                    type_data |= INT32_R;
            }else{
					type_data |= STRING_R;
			}
	   }else{
           if(strcmp(main_type,"INT32_R") == 0){
               type_data |= INT32_R;
           }else{
               type_data |= STRING_R;
           }
	   }
       
    return type_data;
}
}
