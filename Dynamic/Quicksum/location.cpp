/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;

int a[1010][1010],dp[1010][1010];
int main()
{
	int kong=0,m,n,k,i,j;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			dp[i][j] = a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	
	for(i=k;i<=m;i++) for(j=k;j<=n;j++) kong = max(kong,dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
	
	printf("%d\n",kong);
	return 0;
}
