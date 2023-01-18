/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int u,w;
	bool operator <(const A& o)const{
		return w>o.w;
	}
};

int dis[1010];
vector<A> g[1010];
priority_queue<A> dijk;

int main()
{
	int n,m,q,u,v,w,i,c;
	scanf("%d %d %d",&n,&m,&q);
	while(m--)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
	}
	for(i=1;i<=n;i++) dis[i] = 1e9;
	dijk.push({1,0}); dis[1] = 0;
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w;
		dijk.pop();
		for(auto x: g[u])
		{
			if(dis[x.u] > x.w+w)
			{
				dis[x.u] = x.w+w;
				dijk.push({x.u,x.w+w});
			}
		}
	}
	while(q--)
	{
		scanf("%d",&c);
		if(dis[c]!=1e9)printf("%d\n",dis[c]);
		else printf("-1\n");
	}
	return 0;
}
