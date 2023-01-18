/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

int a[1010][1010],cou[1010][1010],dp[1010][1010];
int main()
{
	int m,n,i,j,k,kong=0,couu=0;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==1) cou[i][j] = 1;
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=1,k=1;i<=m;i++,k*=-1)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j] = a[i][j] + max(dp[i-1][j-k],dp[i-1][j]);
			if(dp[i][j] == a[i][j] + dp[i-1][j]) cou[i][j] += cou[i-1][j];
			if(dp[i][j] == a[i][j] + dp[i-1][j-k]) cou[i][j] += cou[i-1][j-k];
			kong = max(kong,dp[i][j]);
		}
	}
	for(j=1;j<=n;j++) if(kong == dp[m][j]) couu += cou[m][j];
	printf("%d %d\n",kong,couu);
	return 0;
}
