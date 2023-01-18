/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[550][550];

int main()
{
	int n,i,j,k,ma=-1e9,a,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			dp[i][j] = dp[i-1][j]+a;
		}
	}
	
	for(k=1;k<=n;k++)
	{
		for(i=k;i<=n;i++)
		{
			for(j=1,sum=0;j<=n;j++)
			{
				sum += dp[i][j] - dp[i-k][j];
				ma = max(ma,sum);
				sum = max(sum,0);
			}
		}
	}
	printf("%d\n",ma);
	return 0;
}
