/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];
char a[1010];
int kong(int l,int r)
{
	
	if(l>=r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	if(a[l]==a[r]) return dp[l][r] = kong(l+1,r-1) + 1;
	else
	{
		for(int k=l;k<=r;k++) dp[l][r] = max(dp[l][r],kong(l,k)+kong(k+1,r));
	}
	return dp[l][r];
}

int main()
{
	int n,i;
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf(" %c",&a[i]);
	printf("%d",kong(0,n-1));
	return 0;
}
