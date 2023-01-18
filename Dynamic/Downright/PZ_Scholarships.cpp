/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(DownRight)
*/
#include <bits/stdc++.h>
using namespace std;

long long a[1010][1010],b[1010][1010],dp1[1010][1010],dp2[1010][1010];

int main()
{
	long long r,c,k,q,i,j;
	scanf("%lld",&q);
	while(q--)
	{
		long long ans = 1e18+1;
		scanf("%lld %lld %lld",&r,&c,&k);
		for(i=1;i<=r;i++) for(j=1;j<=c;j++) scanf("%lld",&a[i][j]),b[i][j]=a[i][j];
		if(k==2) for(i=1;i<=r;i++) for(j=1;j<=c;j++) scanf("%lld",&b[i][j]);
		for(i=0;i<=r+1;i++) for(j=0;j<=c+1;j++) dp1[i][j] = dp2[i][j] = 1e18+1;
		
		for(i=1;i<=r;i++) 
		{
			for(j=1;j<=c;j++)
			{
				if(i==1 && j==1) dp1[1][1] = a[1][1];
				else dp1[i][j] = min(dp1[i-1][j],dp1[i][j-1])+a[i][j];
			}
		}
		
		for(i=r;i>=1;i--) 
		{
			for(j=c;j>=1;j--)
			{
				if(i==r && j==c) dp2[r][c] = b[r][c];
				else dp2[i][j] = min(dp2[i+1][j],dp2[i][j+1])+b[i][j];
			}
		}

		for(i=1;i<=r;i++) for(j=1;j<=c;j++) ans = min(ans,dp1[i][j] + dp2[i][j] - max(a[i][j],b[i][j]));
		printf("%lld\n",ans);
	}
	return 0;
}
