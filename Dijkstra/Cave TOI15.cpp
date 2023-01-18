/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int u,w,t;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};

int dis[2021][2021];
priority_queue< A > dijk;
vector<A> g[2021];


int main()
{
	int n,p,u,e,v,w,i,j,t,l,a,ans=1e9,en;
	scanf("%d %d %d %d",&n,&p,&en,&e);
	while(e--)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w,0});
	}
	for(i=0;i<=2000;i++) for(j=0;j<=2000;j++) dis[i][j] = 1e9;
	dis[p][0] = 0;
	dijk.push({p,0,0});
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w; t = dijk.top().t;
		dijk.pop();
		for(auto x:g[u])
		{
			if(u == p)
			{
				if(dis[x.u][t] > dis[u][t]+x.w)
				{
					dis[x.u][t] = dis[u][t]+x.w;
					dijk.push({x.u , dis[x.u][t] , t});
				}
			}
			else
			{
				if(dis[x.u][t+1] > dis[u][t]+x.w)
				{
					dis[x.u][t+1] = dis[u][t]+x.w;
					dijk.push({x.u , dis[x.u][t+1] , t+1});
				}
			}
		}
	}
	
	
	scanf("%d",&l);
	while(l--)
	{
		ans = 1e9;
		scanf("%d",&a);
		for(j=0;j<n;j++)
		{
			ans = min(ans,dis[en][j] + (j*a));
		}
		printf("%d ",ans);
	}
	return 0;
}
