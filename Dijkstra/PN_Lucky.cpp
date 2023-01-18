/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int u,w,state;
	bool operator < (const A& o)const{
		return w>o.w;
	}
	
};

int dis[50010][32],a[50010];
priority_queue< A > dijk;
vector<A> g[50010];

int main()
{
	int state,n,m,l,s,t,i,u,v,j,w,q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d %d %d",&n,&m,&l,&s,&t);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while(m--)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back({v,w,a[v]});
		}
		for(i=1;i<=50000;i++) for(j=0;j<=30;j++) dis[i][j] = 1e9;
		
		dijk.push({s,0,0});
		dis[s][0] = 0;
		while(!dijk.empty())
		{
			u = dijk.top().u; w = dijk.top().w; state = dijk.top().state;
			dijk.pop();
			for(auto x:g[u])
			{
				if(x.state == state+1 && dis[x.u][x.state] > w+x.w)
				{
					dis[x.u][x.state] = w+x.w;
					dijk.push({x.u,w+x.w,state+1});	
				}
				else if(dis[x.u][state] > w+x.w)
				{
					dis[x.u][state] = w+x.w;
					dijk.push({x.u,w+x.w,state});
				}
			}
		}
		
		if(dis[t][l]==1e9) printf("-1\n");
		else printf("%d\n",dis[t][l]);
		for(i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
