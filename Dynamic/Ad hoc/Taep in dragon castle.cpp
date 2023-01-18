/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[25][25][3];

int main()
{
	int q,r,c,kk,p,i,j,k,sum;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d %d",&r,&c,&kk,&p);
		for(i=1;i<=r;i++) for(j=1;j<=c;j++) dp[i][j][0] = 1;
		
		for(k=1;k<kk;k++)
		{
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					dp[i][j][k%2] = (dp[i][j][(k+1)%2]+dp[i-1][j][(k+1)%2]+dp[i+1][j][(k+1)%2]+dp[i][j-1][(k+1)%2]+dp[i][j+1][(k+1)%2])%p;
				}
			}
		}
		for(i=1,sum=0;i<=r;i++) for(j=1;j<=c;j++) sum = (sum + dp[i][j][(kk-1)%2])%p;
		printf("%d\n",sum);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
