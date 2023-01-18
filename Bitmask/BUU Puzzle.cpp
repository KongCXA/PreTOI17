/*
	Author	: KongCXA
	Language: C++
	Algo	: Bitmask
*/
#include <bits/stdc++.h>
using namespace std;

int s[13] = {0,1,2,4,5,8,9,10,16,17,18,20,21},a[6][50010],dp[14][50010];

int main()
{
	int q,n,i,j,k,sum,ans;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=0;i<5;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<13;j++)
			{
				for(k=0,sum=0;k<5;k++) if(s[j]&(1<<k)) sum+=a[k][i];
				for(k=0;k<13;k++) if(!(s[j]&s[k])) dp[j][i+1] = max(dp[j][i+1],dp[k][i]+sum);
			}
		}
		for(i=0,ans=0;i<13;i++) ans=max(ans,dp[i][n]);
		printf("%d\n",ans);
		memset(dp,0,sizeof dp);	
	}
	return 0;
}

