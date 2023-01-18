/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

char a[110][110];
int dis[110][110];
queue< pair<int,int> > bfs;
vector< pair<int,int> > g[110][110];

int main()
{
	
	int n,m,i,j,ii,jj;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			dis[i][j] = 1e9;
			scanf(" %c",&a[i][j]);
			if(a[i][j]== 'B')
			{
				g[i][j].push_back({i,j+1});
				g[i][j+1].push_back({i,j});
				g[i][j].push_back({i+1,j});
				g[i+1][j].push_back({i,j});
			}
			if(a[i][j]== 'R')
			{
				g[i][j].push_back({i,j+1});
				g[i][j+1].push_back({i,j});
			}
			if(a[i][j]== 'D')
			{
				g[i][j].push_back({i+1,j});
				g[i+1][j].push_back({i,j});
			}
		}
	}
	dis[1][1] = 1;
	bfs.push({1,1});
	while(!bfs.empty())
	{
		i = bfs.front().first; j = bfs.front().second;
		bfs.pop();
		
		for(auto x:g[i][j])
		{
			ii = x.first ; jj = x.second;
			if(ii<1||jj<1||ii>m||jj>n) continue;
			if(dis[ii][jj] < dis[i][j] + 1) continue;
			if(dis[ii][jj]==dis[i][j]+1)
			{
				printf("%d\n%d %d\n",dis[ii][jj],ii,jj);
				return 0;
			}
			dis[ii][jj] = dis[i][j]+1;
			bfs.push({ii,jj});
			
		}
		
	}
	
	return 0;
}
