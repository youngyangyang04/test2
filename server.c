/*************************************************************************
	> File Name: server.c
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月02日 星期二 10:55:44
 ************************************************************************/

#include<my_socket.h>
#include<my_sort.h>
#define IP "127.0.1.1"
#define PORT 8888
int main(){
	SA client_addr;
	int fd_socket,fd_client;
	my_socketSer(&fd_socket,MY_TCP,IP,PORT);//初始化socket
	my_listen(fd_socket,5);//监听
	int sendlen,recvlen,msg[128];
	int len;
	my_accept(&fd_client,fd_socket,(pSA)&client_addr,&len);//接受客户端，接到客户端的addr
	my_recv(&recvlen,fd_client,msg,1024);//接受客户端信息
	arr_show(msg,10);
	printf("recvlen:%d\n",recvlen);
//	insert_sort(msg,recvlen/4);或者可以用这个函数排序
	quick_sort(msg,0,recvlen/4-1);//排序
	my_send(&sendlen,fd_client,msg,recvlen);//发回客户端
	my_close(fd_socket);
	my_close(fd_client);
}
	

