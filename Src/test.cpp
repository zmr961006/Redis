/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月08日 星期一 21时30分22秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include"./string_redis.h"
#include"./pthreadPool_redis.h"
#include"./Dlist_redis.h"
#include"./pseudo_hash_redis.h"
//#include"./Hash_Map_redis.h"
#include"./Hash_Map_Redis.h"
#include"./Hash_Map_Rredis.h"
#include"./int_set.h"
#include"./Key_val.h"
//#include"./DEBUG.h"
#include"./Data_table.h"
#include<list>
#include<vector>
//#include<gtest/gtet.h>
#include"./Data_Base.h"
#include"./Data_All.h"
#include"./AOF.h"
using namespace std;

#define STRING String

//void test(String   & num){
//    std::cout << num << std::endl;
//}


void test(){
    std::shared_ptr<Hash_Map_V< String > > ma (new Hash_Map_V<String >("zmr"));
    //for(int i = 0;i < 1000000;i++){
        String B = "zmrl0l";
        const char * A = "hello";
        (*ma).Hash_Map_V_add(A,B);
        //std::cout << "aaa" << std::endl;
    //}
    //const char * A = "hello";
    String c = "jjjjjj";
    std::cout << "!!!!!!!!!!!!!!!!\n";
    (*ma).Hash_Map_set(A,c);
    //String a = (*ma).Find(A);
    bool  result;
    result = (*ma).Hash_Map_del(A);
    std::cout << "I find the obj " << result << "()"<< std::endl;
    std::cout << ma.use_count() << std::endl;
    //std::shared_ptr<Hash_Map_V< int > > m (new Hash_Map_V<int >("zmr"));
    ma.reset();

    std::cout << ma.use_count() << std::endl;
}

/*void test_set(){
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    Set_Int<int> test(10,1,a);
    test.Set_Int_show();
    for(int i = 1;i < 1000000 ;i++){  
        std::shared_ptr<Set_Int<int> > test (new Set_Int<int>(10,1,a));
    }
    //std::cout << test.use_count()<< std::endl;
}*/

/*void test_key(){
	int a = 10;
    int b = 20;
    const char * B = "BBBBBBBB";
    const char * A = "AAAAAAAA";        字符串，单个整数创建正常
    int type = INT32_R;
    //type |= INT32_R;
    //int type = 0;
    //type |= STRING_R;
    const char *key_name = "AAA";
    const char *key_name2= "GGGG";
    std::cout << type << std::endl;
    void * ret;
	Key_Val_Node temp(110,"zmr",(void *)&a,type,3);
    //temp.add_elem((void *)A,type,1,key_name);
    //temp.add_elem((void *)B,type,1,key_name2);
    //std::string *buf = new std::string[10];
    int *buf = new int[10];
    temp.find_elem((void *)A,type,1,key_name,(void *)buf);
    std::cout << buf[0] << std::endl;
}*/

void test_data(){

	Data_All test;
	const char * key_name = "zmrdata";
	const char * obj    = "helloworld";
    const char * obb    = "yes";
	//int obj = 10;
    int num1 = 10;
    int num2 = 20;
	//int *buf = new int[10];
    //std::string *buf = new std::string[10];
	int *buf = new int[10];
    int type_data = INT32_R;
    type_data |= HASH_MAP_R;
    test.Data_All_create(key_name,type_data,1,(void*)&num1,1);
    test.Data_All_add(key_name,type_data,1,(void*)&num1,1,obj);
    test.Data_All_set(key_name,type_data,1,(void*)&num2,0,obj);
	test.Data_All_find(key_name,type_data,1,(void*)obj,1,(void*)buf,obj);
	std::cout<< "____"  << buf[0] << std::endl;
    //std::cout<< "++++"  << buf[1] << std::endl;
	std::cout << "lalalalal" << std::endl;
}

void test_log(){

    AOF_LOG_DO test;
    const char *log = "hello  world  i like compture yeyeyey!!!";
    for(int i = 0;i < 100000;i++){
        test.AOF_LOG_add(log);
    }

}


/*int main(){
    字符串测试
    String A("zmr");
    String B(A);
    String C = "zmr";

    cout << A << " " << B << " " << C << endl;
    
    String A("zmr");

    ThreadPool pool;
    pool.setMaxQueueSize(10);
    pool.start(4);

    for(int i = 1;i < 10;i++){
        pool.putTask(std::bind(test,std::ref(A)));
    }
    sleep(1);

    pool.stop();
    */
    
     /*   int a[10] = {1,2,3,4,5,6,7,8,9,10};
        List_Self<int> * test = new List_Self<int>(a);
        int b = 11;
        int s = 3;
        while(b > 0){
            s = test->pop_back();
            std::cout << s << std::endl;
            b--;
        }
        //test->push_back(b);
        test->Insert_list_frout(s,b);
        test->Insert_list_behind((s+2),b);
        test->show_list();
        std::cout << test->show_length() << std::endl;
        std::cout << test->show_length()<< std::endl;
        s = test->pop_front();
        while(b < 5){  
            std::cout << s << std::endl;
      */ 
    /*
    vector< Hash_node<string,string> > vec(3);
    vec[0].Hash_set("zmr","hello");
    vec[0].Hash_show();
     */
    
    /*Hash_Map_v<string,string,int> test(10);
    test.Hash_Map_v_add("zmr","hello",0);
    test.Hash_show();
    */
    /*Hash_Map<STRING,STRING> * test;
    test = new Hash_Map<String,String>(10);
    test->Hash_Map_set("zmr","hello");
    test->Hash_Map_show(0);
    */
    
    /*List_Self<Hash_Map<string,string> > *test;
    test = new List_Self<Hash_Map<string,string> >(10);
    test->get_data().Hash_Map_set("zmer","kk");
    

   int i = 0;
   for(i = 0;i < 100000;i++){
       Key_Val<String> *test;
       test = new Key_Val<String>(name,A);
   }*/
   /*test_log();
   while(1){
       
   }
    
   //while(1){
    //std::cout << "hello world" << std::endl;  
   //}


}*/
