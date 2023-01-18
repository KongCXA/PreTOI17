/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Common Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
char a[1010],b[1010];

int main()
{
	int q,n,m,i,j;
	scanf("%d",&q);
	while(q--)
	{
		scanf(" %s %s",a+1,b+1);
		n = strlen(a+1);
		m = strlen(b+1);
		for(i=1;i<=n;i++) dp[i][0] = i;
		for(i=1;i<=m;i++) dp[0][i] = i;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(dp[i-1][j-1],(min(dp[i-1][j],dp[i][j-1]))) + 1;
			}
		}
		
		printf("%d\n",dp[n][m]);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
