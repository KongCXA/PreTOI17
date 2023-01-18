/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1000100];
int main()
{
	int n,num,idx,i;
	scanf("%d %d",&n,&dp[0]);
	int kong = 1;
	for(i=1;i<n;i++)
	{
		scanf("%d",&num);
		idx = upper_bound(dp,dp+kong,num)-dp;
		dp[idx] = num;
		if(kong == idx) kong++;
	}
	printf("%d",n-kong);
	return 0;
}
