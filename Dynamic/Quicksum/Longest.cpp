/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;
int dpl[1010][1010],dpr[1010][1010],dpu[1010][1010],dpd[1010][1010],dp[1010][1010];

int main()
{
	int m,n,i,j,q,ma,lu,ld,ru,rd;
	char a;
	scanf("%d",&q);
	while(q--)
	{
		
		scanf("%d %d",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&a);
				if(a=='1') dp[i][j] = 1;
			}
		}
		
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dp[i][j]==0) continue;
				dpl[i][j] = dpl[i][j-1] + 1;
				dpu[i][j] = dpu[i-1][j] + 1;
			}
		}
		
		for(i=m;i>=1;i--)
		{
			for(j=n;j>=1;j--)
			{
				if(dp[i][j]==0) continue;
				dpr[i][j] = dpr[i][j+1] + 1;
				dpd[i][j] = dpd[i+1][j] + 1;
			}
		}
		
		
		
		for(i=1,ma=0;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				lu = dpl[i][j]+dpu[i][j] - 1;
				ld = dpl[i][j]+dpd[i][j] - 1;
				ru = dpr[i][j]+dpu[i][j] - 1;
				rd = dpr[i][j]+dpd[i][j] - 1;
				ma = max(max(lu,max(ld,max(ru,rd))),ma);
			}
		}
		printf("%d\n",ma);
		memset(dp,0,sizeof dp);
		memset(dpl,0,sizeof dpl);
		memset(dpr,0,sizeof dpr);
		memset(dpd,0,sizeof dpd);
		memset(dpu,0,sizeof dpu);
		
	}
	return 0;
}
