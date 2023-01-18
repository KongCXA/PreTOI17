/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[7070][7070],cou[7070];
char c[7070];
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf(" %s",c);
		for(j=1;j<=m;j++)
		{
			dp[i][j] = c[j-1]-'0';
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(dp[i][j]==0) continue;
			dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
			dp[i][j]++;
			cou[dp[i][j]]++;
		}
	}
	for(i=min(m,n);i>=1;i--) cou[i-1]+=cou[i];
	for(i=1;i<=min(m,n);i++) printf("%d\n",cou[i]);
	return 0;
}
