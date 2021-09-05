#ifndef C_NET_H_
#define C_NET_H_
// 头文件的包含
#include <netinet/in.h>
#include <sys/socket.h>

#include <ctype.h>
#include <arpa/inet.h>
#include <stdio.h>

// 类型的定义
typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;


// 宏定义
#define E_MSG(STRING,E_CODE) do{perror(STRING); return (E_CODE);}while(0)


// 函数的定义
int s_bind(int domain, int type , unsigned short port);
int s_listen(int domain, int type , unsigned short port);
int n_accept(int fd) ;
int h_accept(int fd) ;



#endif