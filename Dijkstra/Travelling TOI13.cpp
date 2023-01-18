/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	long long u,w,state;
	bool operator < (const A& o)const{
		return w>o.w;
	}
	
};

long long dis[10010],backdis[10010];
priority_queue< A > dijk;
vector<A> g[100100];

int main()
{
	long long n,m,a,b,c,u,v,w,i,idx,kong=1e18;
	scanf("%lld %lld %lld %lld %lld",&n,&m,&a,&b,&c);
	while(m--)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(i=0;i<=10000;i++) dis[i] = 1e18,backdis[i] = 1e18; 
	dijk.push({a,0}); dis[a]=0;
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w; dijk.pop();
		for(auto x:g[u])
		{
			if(dis[x.u] > w+x.w && w+x.w <= c)
			{
				dis[x.u] = w+x.w;
				dijk.push({x.u,w+x.w});
			}
		}
	}
	
	dijk.push({b,0}); backdis[b]=0;
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w; dijk.pop();
		for(auto x:g[u])
		{
			if(backdis[x.u] > w+x.w)
			{
				backdis[x.u] = w+x.w;
				dijk.push({x.u,w+x.w});
			}
		}
	}
	
	if(dis[b]!=1e18) printf("%lld %lld 0\n",b,dis[b]);
	else
	{
		for(i=n-1;i>=0;i--)
		{
			if(dis[i]!=1e18)
			{
				if(backdis[i] <= kong) kong = backdis[i],idx=i;
			}
		}
		printf("%lld %lld %lld\n",idx,dis[idx],kong);
	}
	return 0;
}
