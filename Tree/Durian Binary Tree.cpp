/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> g[105];
int a[105];
int dp[105][105];
vector<int> child[105];
void dfs(int u)
{
	for(auto x:g[u])
	{
		if(a[x.first]==-1)
		{
			a[x.first] = x.second;
			child[u].push_back(x.first);
			dfs(x.first);
		}
	}
}

int play(int u,int K)
{
	if(dp[u][K] != -1) return dp[u][K];
	if(K==0) return 0;
	if(child[u].size()==0) return a[u];
	if(child[u].size()==1) return dp[u][K] = play(child[u][0],K-1)+a[u];
	int now=0;
	
	for(int i=0;i<=K-1;i++)
	{
		now = max(now,play(child[u][0],i)+play(child[u][1],K-i-1)+a[u]);
	}
	return dp[u][K] = now;
}

int main()
{
	int n,k,s,e,v;
	memset(a,-1,sizeof a);
	memset(dp,-1,sizeof dp);
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&s,&e,&v);
		g[s].push_back({e,v});
		g[e].push_back({s,v});
	}
	a[1] = 0;
	dfs(1);
	
	printf("%d\n",play(1,k+1));
	return 0;
}

