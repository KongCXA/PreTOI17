/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;


int mark[2020][2020],di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
char a[2020][2020];
struct A{
	int i,j,w;
};
queue< A > bfs;

int main()
{
	int m,n,i,j,w,ii,jj,k,kong=0,cou=0;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&a[i][j]);
			if(a[i][j]=='X') bfs.push({i,j,0});
			if(a[i][j]=='W') mark[i][j] = 1;
		}
	}
	
	while(!bfs.empty())
	{
		
		i = bfs.front().i; j = bfs.front().j; w = bfs.front().w;
		bfs.pop();
		
		if(a[i][j]=='A')
		{
			a[i][j] = 'W';
			cou++;
			kong += w*2;
			
		}
		for(k=0;k<4;k++)
		{
			ii = i+di[k]; jj = j+dj[k];
			if(ii<1||jj<1||ii>m||jj>n) continue;
			if(a[ii][jj]=='W') continue;
			if(a[ii][jj]!='A') a[ii][jj] = 'W';
			bfs.push({ii,jj,w+1});
			
		}
	}
	
	printf("%d %d\n",cou,kong);
	return 0;
}
