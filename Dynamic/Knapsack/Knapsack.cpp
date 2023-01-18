/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Knapsack)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[110][10100],w[110],va[110];

int main()
{
	int n,k,i,j,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d %d",&va[i],&w[i]);
	
	for(i=1;i<=n;i++)
	{
		for(j=0;j<w[i];j++) dp[i][j] = dp[i-1][j];
		for(j=w[i];j<=m;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+va[i]);
		}
	}
	
	printf("%d\n",dp[n][m]);
	return 0;
}
