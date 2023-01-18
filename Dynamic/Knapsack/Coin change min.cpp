/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Knapsack)
*/
#include <bits/stdc++.h>
using namespace std;
int c[15],dp[1000100];

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	dp[0] = 0;
	for(i=1;i<=m;i++) dp[i] = m+1;
	for(i=1;i<=m;i++)
	{
		
		for(j=1;j<=n;j++)
		{
			if(i-c[j] >= 0)
			{
				dp[i] = min(dp[i],dp[i-c[j]]+1);
			}
		}
	}
	if(dp[m]==m+1) printf("0\n");
	else printf("%d\n",dp[m]);
	return 0;
}
