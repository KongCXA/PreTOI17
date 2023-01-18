/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

int marks[200][200],marke[200][200],a[200][200];
int di[4]={0,0,1,-1},dj[4]={1,-1,0,0};
struct A{
	int i,j,w;
};
queue< A > bfs;

int main()
{
	int m,n,si,sj,ei,ej,ii,jj,k,i,j,w,kong=9000,ans=0;
	scanf("%d %d %d %d %d %d",&m,&n,&si,&sj,&ei,&ej);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			marks[i][j] = marke[i][j] = 1e9;
		}
	}
	
	bfs.push({si,sj,0});
	while(!bfs.empty())
	{
		i = bfs.front().i; j = bfs.front().j; w = bfs.front().w;
		bfs.pop();
		if(marks[i][j] != 1e9) continue;
		marks[i][j] = w;
		for(k=0;k<4;k++)
		{
			ii = i+di[k] ; jj = j+dj[k];
			if(ii<1||jj<1||ii>m||jj>n) continue;
			if(marks[ii][jj] != 1e9) continue;
			if(a[ii][jj]==1) bfs.push({ii,jj,w+1});
			if(a[ii][jj]==0) marks[ii][jj] = w+1;
		}
	}
	while(!bfs.empty()) bfs.pop();
	
	bfs.push({ei,ej,0});
	while(!bfs.empty())
	{
		i = bfs.front().i; j = bfs.front().j; w = bfs.front().w;
		bfs.pop();
		if(marke[i][j] != 1e9) continue;
		marke[i][j] = w;
		for(k=0;k<4;k++)
		{
			ii = i+di[k] ; jj = j+dj[k];
			if(ii<1||jj<1||ii>m||jj>n) continue;
			if(marke[ii][jj] != 1e9) continue;
			
				if(a[ii][jj]==1) bfs.push({ii,jj,w+1});
				if(a[ii][jj]==0) marke[ii][jj] = w+1;
		
		}
	}
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(marke[i][j] != 1e9 && marks[i][j] != 1e9 && a[i][j] == 0)
			{
				kong = min(kong,marke[i][j]+marks[i][j]);
				ans++;
			}
		}
	}
	
	printf("%d\n%d\n",ans,kong+1);
	
	return 0;
}
