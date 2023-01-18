/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Common Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;

int a[3030],b[3030],dp[3030][3030];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	printf("%d\n",dp[n][n]);
	return 0;
}
