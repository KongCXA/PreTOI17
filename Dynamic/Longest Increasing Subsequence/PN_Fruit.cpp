/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;

long long a[100100],dp[100100];
int main()
{
	long long q,n,i,idx,kong;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		kong = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i] += a[i-1];
			if(a[i] <= 0) continue;
			idx = lower_bound(dp,dp+kong,a[i])-dp;
			dp[idx] = a[i];
			if(idx == kong ) kong++;
		}
		
		printf("%lld",idx+1);
		
	}
	return 0;
}
