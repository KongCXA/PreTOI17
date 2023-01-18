/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra + Dynamic Programming
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int u,w,bit;
	bool operator <(const A& o)const{
		return w>o.w;
	}
};

priority_queue<A> dijk;
vector<A> g[220];
int dis[220][40010],a[20],dp[220][220];

int main()
{
	int n,m,k,i,u,v,w,bit,t,j,c;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<k;i++) scanf("%d",&a[i]);
	sort(a,a+k);
	memset(dp,63,sizeof dp);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		dp[u][v] = min(dp[u][v],w);
		dp[v][u] = dp[u][v];
	}
	for(c=1;c<=n;c++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j] = min(dp[i][j],dp[i][c]+dp[c][j]);

	
	g[1].push_back({n,dp[1][n],0});
	for(i=0;i<k;i++)
	{
		u = a[i];
		g[1].push_back({u,dp[1][u],0});
		g[u].push_back({1,dp[1][u],0});
		g[u].push_back({n,dp[u][n],0});
		
	}
	
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			u = a[i]; v = a[j];
			g[u].push_back({v,dp[u][v],0});
			g[v].push_back({u,dp[u][v],0});
		}
	}
	
	for(i=1;i<=n;i++) for(j=0;j<=40000;j++) dis[i][j]=1e9;
	dijk.push({1,0,0});
	dis[1][0] = 0;
	
	while(!dijk.empty())
	{
		u=dijk.top().u; w=dijk.top().w; bit=dijk.top().bit;
		dijk.pop();
		for(auto x:g[u])
		{
			t=0;
			if(a[lower_bound(a,a+k,x.u)-a]==x.u) t=(1<<(lower_bound(a,a+k,x.u)-a));
			if(dis[x.u][bit|t] > x.w+w)
			{
				dis[x.u][bit|t] = x.w+w;
				dijk.push({x.u,x.w+w,bit|t});
			}
		}
	}
	printf("%d\n",dis[n][(1<<(k))-1]);
	return 0;
}
