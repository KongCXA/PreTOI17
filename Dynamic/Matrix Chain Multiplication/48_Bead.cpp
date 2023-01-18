/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[110][110],a[110],val[110][110];

int kong(int l,int r)
{
	
	if(l>=r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	int mi = 1e9;
	for(int k=l;k<r;k++)
	{
		int temp = kong(l,k) + kong(k+1,r) + val[l][k] * val[k+1][r];
		if(mi > temp)
		{
			mi = temp;
			val[l][r] = (val[l][k] + val[k+1][r]) % 100;
		}
		
	}
	return dp[l][r] = mi;
}

int main()
{
	int q,n,i;
	scanf("%d",&q);
	while(q--)
	{
		memset(dp,-1,sizeof dp);
		memset(val,0,sizeof val);
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]),val[i][i] = a[i];
		printf("%d\n",kong(0,n-1));
	}
	return 0;
}
