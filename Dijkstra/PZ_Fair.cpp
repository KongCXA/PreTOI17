/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;


struct A{
	int v,w;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};

int dis[110][21000],id[21000];
vector< A > g[21000];
priority_queue< A > heap;
vector< int > node[110];

int main()
{
	int n,m,a,i,u,v,w,j,q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&n,&m,&a);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&id[i]);
			node[ id[i] ].push_back(i);
		}
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back({v,w}),g[v].push_back({u,w});
		}
		
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=n;j++)
			{
				dis[i][j] = 1e9;
			}
			for(auto x:node[i]) heap.push({x,0}),dis[i][x] = 0;
			while(!heap.empty())
			{
				A now = heap.top(); heap.pop();
				for(auto x:g[now.v])
				{
					if(dis[i][x.v]<=now.w+x.w) continue;
					dis[i][x.v] = now.w+x.w;
					heap.push({x.v,now.w+x.w});
				}	
			}
		}
		long long ans = 1e18,sum;
		for(i=1;i<=n;i++)
		{
			vector< int > best;
			for(j=1;j<=100;j++)
			{
				best.push_back(dis[j][i]);
			}
			sort(best.begin(),best.end());
			sum = 0;
			for(j=0;j<a;j++)
			{
				if(best[j]==1e9)
				{
					sum = 1e18;
					best;
				}
				sum += best[j];
			}
			ans = min(ans,sum);
		}
		if(ans==1e18) printf("-1\n");
		else printf("%lld",ans);
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=100;i++) node[i].clear();
	}
	return 0;
}
