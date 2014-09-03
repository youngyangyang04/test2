/*************************************************************************
	> File Name: client.c
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月02日 星期二 10:43:51
 ************************************************************************/

#include<my_socket.h>
#include<my_sort.h>
#define IP "127.0.1.1"
#define PORT 8888
int main(){
	srand(getpid());
	SA server_addr;
	int fd_socket,index,msg[128],sendlen,recvlen;
	my_socketCli(&fd_socket,MY_TCP,IP,PORT,&server_addr);//客户端socket初始化
	my_connect(fd_socket,(pSA)&server_addr,sizeof(SA));//链接服务器
	arr_init(msg,10);//准备要发送的信息
	arr_show(msg,10);
	my_send(&sendlen,fd_socket,msg,10*4);//发送给服务器端
	my_recv(&recvlen,fd_socket,msg,1024);//接受来自服务器的数据
	printf("after sort\n");
	arr_show(msg,10);//显示处理的信息
	my_close(fd_socket);
}
	


