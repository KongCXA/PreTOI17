/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[100100];
int main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	dp[0] = 1;dp[1] = 1;
	for(i=2;i<=n;i++)
	{
		dp[i] = dp[i-1]*2; // dp[i] = dp[i-1] + dp[i-2]+...
		if(i>k) dp[i] -= dp[i-k-1] -2009;
		dp[i] %= 2009;
	}
	printf("%d\n",dp[n]);
	return 0;
}
