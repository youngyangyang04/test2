/*************************************************************************
	> File Name: 5ziqi.h
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月02日 星期二 20:29:07
 ************************************************************************/
#ifndef _5ZIQI_
#define _5ZIQI_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
typedef struct tag{
	int x,y,xl,yl;
}node;
/*void gomoku_show(char gomoku[][10]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",gomoku[i][j]);
		}
		printf("\n");
	}
}
void gomoku_init(char gomoku[][10]){
	int i,j;	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			gomoku[i][j]='_';
	for(i=0;i<N;i++)
		gomoku[0][i]=gomoku[i][0]=(i+'0');
}*/
#endif
