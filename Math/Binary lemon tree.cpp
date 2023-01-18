/*
	Author	: KongCXA
	Language: C++
	Algo	: Math(Catalan)
*/
#include <bits/stdc++.h>
using namespace std;


long long dp[10010];
int main()
{
	long long n,i,j;
	scanf("%lld",&n);
	dp[0] = 1;
	for(i=1;i<=n;i++)
	{
		dp[i] = 0;
		for(j=0;j<i;j++) dp[i] += ((dp[j]%909091) * (dp[i-j-1]%909091))%909091,dp[i] %= 909091;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
