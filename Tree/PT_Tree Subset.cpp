/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> g[100100];
long long a[100100],dp[100100][2],mark[100100];

void play(long long u)
{
	mark[u] = 1;
	dp[u][1] = a[u];
	for(auto x:g[u])
	{
		if(mark[x]) continue;
		play(x);
		dp[u][0] += max(dp[x][0],dp[x][1]);
		dp[u][1] += dp[x][0];
	}
}

int main()
{
	long long n,u,v,q,i;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		play(1);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		memset(mark,0,sizeof mark);
		for(i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
