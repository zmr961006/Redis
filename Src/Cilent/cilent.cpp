/*************************************************************************
	> File Name: cilent.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月26日 星期五 17时19分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"./mesg.h"
#include"./DSAA.h"
#include<cstring>
#include<cstdlib>

#define MAXLINE 4096



int main(int argc,char **argv){
    
    int sockfd,n,rec_len;
    char recvline[4096],sendline[1024];
    char buf[MAXLINE];
    strcpy(sendline,"hello world");
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    
    while(1){
        struct mesg_body  mesg;
        char str[100];
        unsigned int type_data;
        std::cout << "> ";
        std::cin >> mesg.cmd;
        std::cin >> str;
        std::cin >> mesg.operation;
        mesg.length = strlen(mesg.operation);
        type_data = gettype(str);
        mesg.type = type_data;
        
        int length = sizeof(mesg);
        char buf_send[length];
        bzero(buf_send,length);
        memcpy(buf_send,(char*)&mesg,length);
        

        send(sockfd,buf_send,length,0);
        
        //std::cout << mesg.cmd << " " << mesg.type << " " << mesg.operation<<std::endl;
           
    }
    
    
    close(sockfd);

}
