/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[5050];

int main()
{
	int n,kong,i,j;
	scanf("%d %d",&n,&kong);
	dp[0] = 1;
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		{
			dp[j] += dp[j-i]%kong;
		}
	}
	printf("%d\n",dp[n]%kong-1);
	return 0;
}

