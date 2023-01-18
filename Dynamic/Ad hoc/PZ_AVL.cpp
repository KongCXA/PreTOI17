/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

long long dp[100100];
int main()
{
	long long i,q,kong;
	dp[1] = 1,dp[2] = 2;
	for(i=3;i<=100000;i++)
	{
		dp[i] = (dp[i-1]+dp[i-2]+1)%100000007;
	}
	scanf("%lld",&q);
	
	while(q--)
	{
		scanf("%lld",&kong);
		printf("%lld\n",dp[kong]);
	}
	return 0;
}
