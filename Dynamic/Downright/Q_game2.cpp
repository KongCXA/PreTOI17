/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(DownRight)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[220][220],dp2[220][220],a[220][220];

int main()
{
	int h,w,i,j;
	scanf("%d %d",&h,&w);
	
	for(i=h;i>=1;i--) for(j=1;j<=w;j++) scanf("%d",&a[i][j]);
	
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
			if(i==1)dp2[i][j] = dp2[i][j-1] + a[i][j];	
			else if(j==1)dp2[i][j] = dp2[i-1][j] + a[i][j];	
			else dp2[i][j] = min(dp2[i-1][j],dp2[i][j-1]) + a[i][j];	
		}
	}
	
	printf("%d\n",dp[h][w]-dp2[h][w]);
	return 0;
}
