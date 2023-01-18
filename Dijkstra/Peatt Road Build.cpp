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

vector< A > g[50010];
priority_queue< A > dijk;
long long dis[50010][3],a[50010],b[50010],c[50010];

int main()
{
	long long n,m,i,j,u,w,state,l,r,kong,mid;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
		g[a[i]].push_back({b[i],c[i],0});
		g[b[i]].push_back({a[i],c[i],0});
	}
	for(i=1;i<=50000;i++) for(j=0;j<=1;j++) dis[i][j] = 1e18;
	
	dijk.push({1,0,0});
	dis[1][0] = 0;
	
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w; state = dijk.top().state;
		dijk.pop();
		
		for(auto x:g[u])
		{
			if(dis[x.u][(state+1)%2] > w+x.w)
			{
				dis[x.u][(state+1)%2] = w+x.w;
				dijk.push({x.u,w+x.w,(state+1)%2});
			}
		}
	}
	
	kong = dis[n][1];
	l = 1,r=m;
	while(l<r)
	{
		mid = (l+r)/2;
		for(i=1;i<=50000;i++) for(j=0;j<=1;j++) dis[i][j] = 1e18;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=mid;i++)
		{
			g[a[i]].push_back({b[i],c[i],0});
			g[b[i]].push_back({a[i],c[i],0});
		}
		
		dijk.push({1,0,0}); dis[1][0] = 0;
		while(!dijk.empty())
		{
			u = dijk.top().u; w = dijk.top().w; state = dijk.top().state;
			dijk.pop();
			
			for(auto x:g[u])
			{
				if(dis[x.u][(state+1)%2] > w+x.w)
				{
					dis[x.u][(state+1)%2] = w+x.w;
					dijk.push({x.u,w+x.w,(state+1)%2});
				}
			}
		}
		if(dis[n][1]==kong) r = mid;
		else l = mid+1;
	}
	printf("%lld %lld\n",l,kong);
	return 0;
}
