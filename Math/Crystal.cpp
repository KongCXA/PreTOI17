/*
	Author	: KongCXA
	Language: C++
	Algo	: Math(Catalan)
*/
#include <bits/stdc++.h>
using namespace std;


int dp[10010];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	dp[0] = 1;
	for(i=1;i<=n;i++)
	{
		dp[i] = 0;
		for(j=0;j<i;j++) dp[i] += ((dp[j]%10001) * (dp[i-j-1]%10001))%10001,dp[i] %= 10001;
	}
	printf("%d\n",dp[n]);
	return 0;
}
