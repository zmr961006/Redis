/*************************************************************************
	> File Name: string_redis.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月08日 星期一 20时08分02秒
 ************************************************************************/


#include"./string_redis.h"


String::String(const char *s){     /*C 字符串构造函数*/
 
    size = std::strlen(s);
    free = FREE_STR(size);
    //sds = (char *)std::malloc(LEN_STR(size)); 
    sds = new char[LEN_STR(size)];
    std::strcpy(sds,s);
    
}

String::String(){                  /*无参构造函数*/
    size = DEFAULT_SIZE;
    free = FREE_STR(size);
    //sds  = (char *)std::malloc(LEN_STR(size));
    sds = new char[LEN_STR(size)];
    sds[0] = '\0';
}

String::String(const String & st){ /*复制构造函数*/
    size = st.size;
    free = FREE_STR(st.size);
    //sds = (char *)std::malloc(LEN_STR(size));
    sds = new char[LEN_STR(size)];
    std::strcpy(sds,st.sds);
}

String::~String(){                 /*析构函数*/

    //std::cout << "~~~~" << std::endl; /*测试析构函数*/
    //std::free(sds);
    delete [] sds;

}

String & String::operator=(const char *s){    /*重载=*/
    //std::free(sds);
    if(!sds){
        std::free(sds);
    }
    size = std::strlen(s);
    //sds = (char *)malloc(LEN_STR(size));
    sds = new char[LEN_STR(size)];
    std::strcpy(sds,s);
    free = FREE_STR(size);
    return *this;
}


String & String::operator=(const String & st){ /*重载=*/
    if(this == &st)
        return *this;
    std::free(sds);
    size = LEN_STR(st.size);
    //sds = (char *)std::malloc(LEN_STR(size));
    sds = new char[LEN_STR(size)];
    free = FREE_STR(size);
    std::strcpy(sds,st.sds);
    return *this;
}

char & String::operator[](int i){              /*重载【】*/
    return sds[i];
}

bool operator<(const String &st,const String &st2){
    return(std::strcmp(st.sds,st2.sds) < 0);
}

bool operator>(const String &st,const String &st2){
    return(std::strcmp(st.sds,st2.sds) > 0);
}

bool operator==(const String &st,const String &st2){
    return(std::strcmp(st.sds,st.sds) == 0);
}

std::ostream & operator<<(std::ostream & os,const String & st){
    os << st.sds;
    return os;
}

std::istream & operator>>(std::istream & is,String & st){
    char temp[DEFAULT_SIZE];
    is.get(temp,DEFAULT_SIZE);
    if(is)
        st = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}

int String::getsize()const{
    return size;
}

int String::getfree()const{
    return free;
}

String & String::StringAdd(const String & st2){
    
    int len = st2.getsize();
    if(len < free){
        size += len;
        free -= len;
        std::strcat(sds,st2.sds);
    }else if(len <= STRING_MAX && len >= free){
        char temp[size + 1];
        std::strcpy(temp,sds);
        std::free(sds);
        size = size + len;
        free = FREE_STR(size);
        //sds = (char *)std::malloc(LEN_STR((size)));
        sds = new char[LEN_STR(size)];
        assert(sds != NULL);
        std::strcpy(sds,temp);
        std::strcat(sds,st2.sds);
    }else{
        //do nothing
    }

    return *this;
}

String & String::StringAdd(const char *s){
    int len = std::strlen(s);
    if(len < free){
        size += len;
        free -= len;
        std::strcat(sds,s);
    }else if(len <= STRING_MAX && len >= free){
        char temp[size + 1];
        std::strcpy(temp,sds);
        std::free(sds);
        size = size + len;
        free = FREE_STR(size);
        //sds = (char *)std::malloc(LEN_STR(size));
        sds = new char[LEN_STR(size)];
        assert(sds != NULL);
        std::strcpy(sds,temp);
        std::strcat(sds,s);
    }else{
        //do nothing
    }
    return *this;
}

String & String::StringClear(String & st){
    
    memset(sds,0,size+free);
    free += size;
    size  = 0;

    return *this;

}

String & String::StringSizeClear(String & st,int len){
    
    memset(sds,0,len);
    (len >= size) ? (free += size):(free += len);
    (len >= size) ? (size = 0) : (size -= len);
    return *this;
}


String & String::StringUpDate(const char *s){
    int len = std::strlen(s);
    if(len < free){
        size += len;
        free -= len;
        std::strcat(sds,s);
    }else if(len <= STRING_MAX && len >= free){
        char temp[size + 1];
        std::strcpy(temp,sds);
        std::free(sds);
        size = size + len;
        free = FREE_STR(size);
        //sds = (char *)std::malloc(LEN_STR(size));
        sds = new char[LEN_STR(size)];
        assert(sds != NULL);
        std::strcpy(sds,temp);
        std::strcat(sds,s);
    }else{
        //do nothing
    }
    return *this; 
}

String & String::StringUpDate(const String & st){

	int len = st.getsize();
    if(len < free){
        size += len;
        free -= len;
        std::strcat(sds,st.sds);
    }else if(len <= STRING_MAX && len >= free){
        char temp[size + 1];
        std::strcpy(temp,sds);
        std::free(sds);
        size = size + len;
        free = FREE_STR(size);
        //sds = (char *)std::malloc(LEN_STR((size)));
        sds = new char[LEN_STR(size)];
        assert(sds != NULL);
        std::strcpy(sds,temp);
        std::strcat(sds,st.sds);
    }else{
        //do nothing
    }

    return *this;


}
