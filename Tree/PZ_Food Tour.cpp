/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	long long u,w;
};
struct B{
	long long ht,fd[510];
};

vector<A> g[40040];
B dp[40040];
long long m,menu[40040],hotel[40040],food[510],mp[40040],p[40040];

long long find(long long u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]);
}

void dfs(long long u,long long pa)
{
	long long i;
	dp[u].ht = -1e9;
	for(i=1;i<=m;i++) dp[u].fd[i] = -1e9;
	if(menu[u]) dp[u].fd[mp[find(u)]] = 0;
	if(hotel[u]) dp[u].ht = 0;
	for(auto x:g[u])
	{
		if(x.u==pa) continue;
		dfs(x.u,u);
		
		for(i=1;i<=m;i++)
		{
			food[i]=max(food[i],dp[u].ht + dp[x.u].fd[i]+x.w);
			food[i]=max(food[i],dp[u].fd[i] + dp[x.u].ht+x.w);
			dp[u].fd[i] = max(dp[u].fd[i],dp[x.u].fd[i]+x.w);
		}
		dp[u].ht = max(dp[u].ht,dp[x.u].ht+x.w);
	}
}

int main()
{
	long long q,n,r,k,i,u,v,w,ans,idx;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld %lld %lld",&n,&m,&r,&k);
		for(i=1;i<=n-1;i++)
		{
			scanf("%lld %lld %lld",&u,&v,&w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		for(i=1;i<=n;i++) p[i]=i;
		while(r--)
		{
			scanf("%lld %lld",&u,&v);
			p[find(u)] = find(v);
			menu[u] = menu[v] = 1;
		}
		for(i=1,idx=0;i<=n;i++)
		{
			if(menu[i]&&!mp[find(i)]) mp[find(i)] = ++idx;
		}
		for(i=1;i<=k;i++)
		{
			scanf("%lld",&u);
			hotel[u] =1;
		}
		dfs(1,-1);
		for(i=1,ans=0;i<=idx;i++) ans+=food[i]*2;
		printf("%lld\n",ans);
		memset(food,0,sizeof food);
		memset(dp,0,sizeof dp);
		memset(menu,0,sizeof menu);
		memset(hotel,0,sizeof hotel);
		memset(mp,0,sizeof mp);
		for(i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
