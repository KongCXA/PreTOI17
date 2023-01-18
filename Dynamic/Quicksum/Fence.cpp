/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[550][550],a[550][550];
int main()
{
	int q=2,m,n,t,x,y,i,j,k,kong=0;
	while(q--)
	{
	
		scanf("%d %d %d",&m,&n,&t);
		while(t--)
		{
			scanf("%d %d",&x,&y);
			a[x+1][y+1] = 1;
		}
		
		for(i=1;i<=m;i++) for(j=1;j<=n;j++) dp[i][j] = a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		
		for(k=1;k<=min(m,n);k++)
		{
			for(i=k;i<=m;i++)
			{
				for(j=k;j<=n;j++)
				{
					if(dp[i][j]+dp[i-k][j-k]-dp[i-k][j]-dp[i][j-k] - (dp[i-1][j-1]+dp[i-k+1][j-k+1]-dp[i-k+1][j-1]-dp[i-1][j-k+1])==0)
					{
						kong = k;
					}
				}
			}
		}
		printf("%d\n",kong);
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
	}
	return 0;
}
