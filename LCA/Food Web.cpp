/*
	Author	: KongCXA
	Language: C++
	Algo	: Lowest Common Ancestor
*/
#include <bits/stdc++.h>
using namespace std;

int level[100100],in[100100],dp[20][100100];
vector<int> g[100100];

void dfs(int u,int pa)
{
	level[u]=level[pa]+1;
	dp[0][u]=pa;
	for(auto x:g[u]) dfs(x,u);
}

int main()
{
	int n,i,u,v,j,a,b,q;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		in[v]++;
	}
	
	for(i=1;i<=n;i++) if(in[i]==0) dfs(i,0);
	for(i=1;i<20;i++)
	{
		for(j=1;j<=n;j++) dp[i][j] = dp[i-1][dp[i-1][j]];
	}
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		if(level[a]>level[b]) swap(a,b);
		for(i=19;i>=0;i--)
		{
			if(level[dp[i][b]]<level[a]) continue;
			b=dp[i][b];
		}
		if(a==b)
		{
			printf("%d\n",a);
			continue;
		}
		for(i=19;i>=0;i--)
		{
			if(dp[i][b]==dp[i][a]) continue;
			b=dp[i][b];
			a=dp[i][a];
		}
		printf("%d\n",dp[0][b]);
	}
	return 0;
}
