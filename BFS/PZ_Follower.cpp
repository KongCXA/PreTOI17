/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;
queue< pair<int,int> > bfs;
vector< pair<int,int> > g[200];
int mark[200][1050];

int main()
{
	int q,n,m,s,e,a,b,w,i,ans;
	scanf("%d",&q);
	
	while(q--)
	{
		ans=1023;
		scanf("%d %d %d %d",&n,&m,&s,&e);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&w);
			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}
		
		bfs.push({s,0});
	
		while(!bfs.empty())
		{
			i = bfs.front().first; w = bfs.front().second;
			bfs.pop();
			if(mark[i][w]) continue;
			mark[i][w] = 1;
			if(i==e) ans = min(ans,w);
			for(auto x:g[i]) bfs.push({x.first,(x.second)^w});	
		}
		
		printf("%d\n",ans);
		for(i=1; i<=n ; i++) g[i].clear();
		memset(mark,0,sizeof mark);
	}
	
	return 0;
}
