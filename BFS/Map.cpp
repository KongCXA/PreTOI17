/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;


struct A{
	int pos,i,j;
	bool operator < (const A& o)const{
		if(i==o.i) return j<o.j;
		return i>o.i;
	}
};

queue <int > bfs;
vector < A > g[50000];
A ans[50000];
int mark[50000];

int main()
{
	int m,n,a,c,ii,pospos,pos,jj,i,j;
	char b;
	scanf("%d %d",&m,&n);
	for(i=0;i<=m*n-1;i++) ans[i].pos=i;
	for(i=0;i<m*n-1;i++)
	{
		scanf("%d %c %d",&a,&b,&c);
		if(b=='L')
		{
			g[a].push_back({c,0,1});
			g[c].push_back({a,0,-1});
		}
		
		if(b=='U')
		{
			g[a].push_back({c,-1,0});
			g[c].push_back({a,1,0});
		}	
	}
	
	bfs.push(0);
	
	while(!bfs.empty())
	{
		pos = bfs.front(); mark[pos] = 1;
		bfs.pop();
		for(auto x:g[pos])
		{
			pospos = x.pos; ii = x.i; jj = x.j;
			if(mark[pospos]) continue;
			ans[pospos].i = ans[pos].i+ii; ans[pospos].j = ans[pos].j+jj;
			bfs.push(pospos);
		}
	}
	
	sort(ans,ans+m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",ans[i*n+j].pos);
		}
		printf("\n");
	}
	
	return 0;
}
