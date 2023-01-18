/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

char a[1010],b[1010],c[2020];
int dp[1010][1010];
int main()
{
	int k,ii,jj,i,len,n,m,j;
	scanf(" %s %s",a+1,b+1);
	n = strlen(a+1);
	m = strlen(b+1);
	
	scanf("%d",&k);
	while(k--)
	{
		memset(dp,0,sizeof dp);
		scanf(" %s",c+1);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(i==0&&j==0) 
				{
				dp[i][j] = 1;
				continue;
				}
				if(i && dp[i-1][j] && a[i] == c[i+j]) dp[i][j] = 1;
				if(j && dp[i][j-1] && b[j] == c[i+j]) dp[i][j] = 1;
			}
		}
		if(dp[n][m]) printf("Yes\n");
		else printf("No\n");	
	}
	return 0;
}
