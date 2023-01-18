/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int w,s;
};

A a[1010];
int dp[1010];

int main()
{
	int q,n,i,j;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=n;i>=1;i--) scanf("%d %d",&a[i].w,&a[i].s),dp[i]=1e9;
		dp[0] = 0; dp[n+1] = 1e9;
		for(i=1;i<=n;i++) for(j=i;j>=1;j--) if(a[i].s >= dp[j-1]) dp[j]=min(dp[j], a[i].w+dp[j-1]);

		for(i=1;i<=n+1;i++)
		{
			if(dp[i]==1e9)
			{
				printf("%d",i-1);
				break;
			}
		}	
	}
	return 0;
}
