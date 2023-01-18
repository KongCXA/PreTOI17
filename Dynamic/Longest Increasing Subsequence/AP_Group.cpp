/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;


pair<int , int> a[100100];
int dp[100100];

int main()
{
	int q,n,i,kong,idx;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].first,&a[i].second);
			a[i].second *= -1;
		}
		sort(a,a+n);
		kong = 1,dp[0] = a[0].second;
		
		for(i=1;i<n;i++)
		{
			idx = upper_bound(dp,dp+kong,a[i].second) - dp;
			dp[idx] = a[i].second;
			if(idx==kong) kong++;
		}
		printf("%d\n",kong);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
