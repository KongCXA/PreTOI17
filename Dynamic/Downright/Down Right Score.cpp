/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(DownRight)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[300][300];

int main()
{
	int n,m,i,j,a;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a);
			dp[i][j] = max(dp[i-1][j],dp[i][j-1])+a;
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
