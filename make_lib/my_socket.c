/*************************************************************************
	> File Name: my_socket.c
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月01日 星期一 17:30:26
 ************************************************************************/

#include<my_socket.h>
void my_socketCli(int *fd_socket,int type,char* ip,int port,SA *my_addr){
	ASSERT(type==MY_TCP||type==MY_UDP,"invalid arg\n");
	if(type==MY_TCP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_STREAM,0))!=-1,"TCP socket init fail\n");
	}else if(type==MY_UDP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_DGRAM,0))!=-1,"UDP socket init fail\n");
	}
		memset(my_addr,0,sizeof(SA));
		(*my_addr).sin_family=AF_INET;
		(*my_addr).sin_port=htons(port);
		(*my_addr).sin_addr.s_addr=inet_addr(ip);
}
void my_socketSer(int *fd_socket,int type,char* ip,int port){
	ASSERT(type==MY_TCP || type==MY_UDP,"invalid arg\n");
	if(type==MY_TCP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_STREAM,0))!=-1,"TCP socket init fail\n");
	}else if(type==MY_UDP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_DGRAM,0))!=-1,"UDP socket init fail\n");
	}
		SA my_addr;
		memset(&my_addr,0,sizeof(my_addr));
		my_addr.sin_family=AF_INET;
		printf("%d  %s\n",port,ip);
		my_addr.sin_port=htons(port);
		my_addr.sin_addr.s_addr=inet_addr(ip);
		int len=sizeof(my_addr);
		ASSERT(bind(*fd_socket,(struct sockaddr*)&my_addr,len)!=-1,"bind fail\n");
		return ;
}
void my_accept(int *fd_client,int fd_socket,pSA client_addr,int* addrlen){
	ASSERT((*fd_client = accept(fd_socket,client_addr,addrlen))!=-1,"server accept fail\n");
}
void my_send(int *sendlen,int fd_socket,int *msg,int len){
	ASSERT((*sendlen=send(fd_socket,msg,len,0))!=-1,"send fail\n");
}
void my_recv(int *recvlen,int fd_socket,int *msg,int len){
	ASSERT((*recvlen=recv(fd_socket,msg,len,0))!=-1,"recv fail\n");
}
void my_connect(int fd_socket,pSA server_addr,int len){
	int cnt=0;
	while(connect(fd_socket,server_addr,len)!=0){
//		sleep(1);
		cnt++;
		if(cnt==10){
			fprintf(stdout,"connect fail\n");
			exit(EXIT_FAILURE);
		}
	}
}
void my_sendto(int* send_num,int fd_socket,int *msg,int len,pSA server_addr,int addrlen){
	ASSERT((*send_num=sendto(fd_socket,msg,len,0,server_addr,addrlen))!=-1,"sendto fail\n");

}
void my_recvfrom(int* recv_num,int fd_socket,int *msg,int len,pSA client_addr,int* addrlen){

	ASSERT((*recv_num=recvfrom(fd_socket,msg,len,0,client_addr,addrlen))!=-1,"recvfrom fail\n");
//	int index=0;
//	for(index=0;index<5;index++)
//		printf("%d ",msg[index]);
//	printf("\n");

}
void my_close(int fd_socket){
	ASSERT((close(fd_socket)!=-1),"close fail\n");
}

void my_listen(int fd_socket,int listen_num){
	ASSERT((listen(fd_socket,listen_num))!=-1,"listen fail\n");
}




