/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;
int dp[300300];
vector<int> g[300300];

int main()
{
	int n,i,u,v,ma=0;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d",&u,&v);
		if(u<v) swap(u,v);
		g[u].push_back(v);
		
	}
	for(i=1;i<=n;i++)
	{
		for(auto x:g[i])
		{
			dp[i] = max(dp[i],dp[x]);
			
		}
		dp[i]++;
		ma = max(ma,dp[i]);
	}
	
	printf("%d\n",ma);
	return 0;
}
