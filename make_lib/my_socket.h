/*************************************************************************
	> File Name: my_socket.h
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月01日 星期一 16:28:04
 ************************************************************************/

#ifndef __MY_SOCKET_H__
#define __MY_SOCKET_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define IN
#define OUT
#define IN_OUT
#define MY_TCP 1
#define MY_UDP 2
typedef struct sockaddr* pSA;
typedef struct sockaddr_in SA;
#define ASSERT(flag,msg) ((flag)? NULL:(fprintf(stdout,msg),exit(EXIT_FAILURE)))

void my_socketCli(int *fd_socket,int type,char* ip,int port,SA *my_addr);//客户端不需要绑定，但得把存有server的addr发过去，所以的将addr传出
void my_socketSer(int *fd_socket,int type,char *ip,int port);//绑定自己的addr
void my_accept(int *fd_client,int fd_socket,pSA client_addr,int *addrlen);
void my_send(int* sendlen,int fd_socket,int *msg , int len);
void my_recv(int* recvlen,int fd_socket,int *msg, int len);
void my_connect(int fd_socket,pSA server_addr,int len);
void my_sendto(int* send_num,int fd_socket,int *msg,int len,pSA server_addr,int addrlen);
void my_recvfrom(int* recv_num,int fd_socket,int* msg,int len,pSA client_addr,int *addrlen);
void my_close(int fd_socket);
void my_listen(int fd_socket,int listen_num);
#endif
