/*************************************************************************
	> File Name: 5ziqi_checkfive2.c
	> Author: yang
	> Mail:826123027@qq.com 
	> Created Time: 2014年09月02日 星期二 22:23:48
 ************************************************************************/

#include"5ziqi.h"

int checkFive2(int x,int y,char gomoku[N][N]){
	int i,j,cou1=0,cou2=0;
	for(i=y+1;i<N;i++)//->
		if(gomoku[x][i]=='0')
			cou1++;
		else break;
	for(i=y-1;i>0;i--)
		if(gomoku[x][i]=='0')
			cou1++;
		else break;
	if(cou1>=4) return 1;
	cou1=0;



	for(i=x+1;i<N;i++)
		if(gomoku[i][y]=='0')
			cou1++;
		else break;
	for(i=x-1;i>0;i--)
		if(gomoku[i][y]=='0')
			cou1++;
		else break;
	if(cou1>=4) return 1;
	cou1=0;



	for(i=x+1,j=y+1;i<N,y<N;i++,j++)
		if(gomoku[i][j]=='0')
			cou1++;
		else break;
	for(i=x-1,j=y-1;i>0,j>0;i--,j--)
		if(gomoku[i][j]=='0')
			cou1++;
		else break;
	if(cou1>=4) return 1;
	cou1=0;



	for(i=x-1,j=y+1;i>0,j<N;i--,j++)
		if(gomoku[i][j]=='0')
			cou1++;
		else break;
	for(i=x+1,j=y-1;i<N,j>0;i++,j--)
		if(gomoku[i][j]=='0')
			cou1++;
		else break;
	if(cou1>=4) return 1;
	return 0;
}

