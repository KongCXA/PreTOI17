/*
	Author	: KongCXA
	Language: C++
	Algo	: Binary Search
*/
#include <bits/stdc++.h>
using namespace std;
double a[300300],dp[300300],dp2[300300];

int main()
{
	int n,k,i,c,j;
	double l,r,mid;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lf",&a[i]);
	l=0; r=1e6;
	while(1e-6<r-l)
	{
		mid = (l+r+(1e-6))/2;
		for(i=1,c=0;i<=n;i++)
		{
			dp[i] = dp[i-1]+a[i]-mid;
			dp2[i] = min(dp[i],dp2[i-1]);
			if(i>=k && dp[i]-dp2[i-k]>=0)
			{
				c=1;
				break;
			}
		}
		if(c) l = mid;
		else r = mid-(1e-6);
	}
	printf("%.1lf",l);
	return 0;
}
