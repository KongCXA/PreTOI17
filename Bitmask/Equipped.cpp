/*
	Author	: KongCXA
	Language: C++
	Algo	: Bitmask
*/
#include <bits/stdc++.h>
using namespace std;

int dp[300];

int main()
{
	int n,k,i,w,j,sum,mark;
	scanf("%d %d",&n,&k);
	for(i=1;i<(1<<k);i++) dp[i] = 1e9;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		for(j=0,sum=0;j<k;j++)
		{
			scanf("%d",&mark);
			if(mark) sum+=(1<<j);
		}
		for(j=0;j<(1<<k);j++) dp[j|sum] = min(dp[j|sum],dp[j]+w);

	}
	printf("%d\n",dp[(1<<k)-1]);
	return 0;
}
