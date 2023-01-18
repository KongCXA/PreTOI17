/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

long long a[5050],b[5050],dp[5010][5010];
int main()
{
	long long m,n,i,j,q;
	scanf("%d",&q);
	while(q--)
	{
		memset(dp,0,sizeof dp);
		scanf("%lld %lld",&m,&n);
		for(i=1;i<=m;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j] = max(dp[i-1][j-1]+abs(a[i]-b[j]),max(dp[i][j-1],dp[i-1][j]));
			}
		}
		printf("%lld\n",dp[m][n]);
	}
	return 0;
}
