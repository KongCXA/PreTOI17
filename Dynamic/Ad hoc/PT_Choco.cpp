/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[550][550];
int main()
{
	int k,l,i,j,q,x,y;
	for(k=0;k<=33;k++)
		{
			for(l=0;l<=33;l++)
			{
				for(i=500-k;i>=0;i--)
				{
					for(j=500-l;j>=0;j--)
					{
						
						dp[i+k][j+l] = max(dp[i+k][j+l],dp[i][j]+1);
					}
				}
			}
		}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",dp[x][y]-1);
	}
	return 0;
}
