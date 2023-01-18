/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[100100];
vector<int> ans[100100],ans2;

int main()
{
	int n,i,idx,kong=0,num,ma=1000100;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		idx = lower_bound(dp,dp+kong,num)-dp;
		if(idx==kong) kong++;
		dp[idx] = num;
		ans[idx].push_back(num);
	}
	
	printf("%d\n",kong);
	
	for(i=kong-1;i>=0;i--)
	{
		for(auto x:ans[i])
		{
			if(x<ma)
			{
				ma = x;
				ans2.push_back(x);
				break;
			}
		}
	}
	
	for(i=kong-1;i>=0;i--) printf("%d ",ans2[i]); 
	return 0;
}
