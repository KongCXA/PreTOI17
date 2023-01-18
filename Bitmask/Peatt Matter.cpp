/*
	Author	: KongCXA
	Language: C++
	Algo	: Bitmask
*/
#include <bits/stdc++.h>
using namespace std;
int a[110],dp[60][20110],mark[110];

int main()
{
	int q,n,i,j,sum,mi,ans,k;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1,sum=0;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
		
		dp[0][10000] = 1;
		for(i=1;i<=n;i++)
		{
			for(j=n/2;j>=1;j--)
			{
				for(k=0;k<=20000;k++)
				{
					dp[j][k+a[i]] |= dp[j-1][k];
				}
			}
			
		}
		for(i=0,ans=1e9;i<=20000;i++) if(dp[n/2][i]) ans = min(ans,abs(sum-2*(i-10000)));
		printf("%d\n",ans);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
