/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010],minu[1010][1010],a[1010],b[1010];
int main()
{
	int m,n,i,j,aa,bb,mia,mib;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		minu[i][0]=minu[i-1][0];
		if(minu[i][0]+a[i]>m)
		{
			dp[i][0]++;
			minu[i][0]=a[i];
		}
		else minu[i][0] += a[i];
	}
	
	for(j=1;j<=n;j++)
	{
		dp[0][j]=dp[0][j-1];
		minu[0][j]=minu[0][j-1];
		if(minu[0][j]+b[j]>m)
		{
			dp[0][j]++;
			minu[0][j]=b[j];
		}
		else minu[0][j] += b[j];
	}
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			aa=dp[i-1][j],mia=minu[i-1][j]+a[i];
			if(mia>m) aa++,mia=a[i];
	
			bb = dp[i][j-1],mib=minu[i][j-1]+b[j];
			if(mib>m) bb++,mib=b[j];
			
			if(aa<bb || aa==bb&&mia<mib) dp[i][j] = aa,minu[i][j] = mia;
			else dp[i][j] = bb,minu[i][j] = mib;
		}
	}
	printf("%d\n%d\n",dp[n][n]+1,minu[n][n]);
	return 0;
}
