/*
	Author	: KongCXA
	Language: C++
	Algo	: Bitmask
*/
#include <bits/stdc++.h>
using namespace std;

int a[25][25],dp[2000000],k,n;

int play(int bit)
{
	if(__builtin_popcount(bit)==k) return 0;
	if(dp[bit]!=-1) return dp[bit];
	int temp=1e9;
	for(int i=0;i<n;i++)
	{
		if((bit&(1<<i))==0) continue;
		for(int j=0;j<n;j++)
		{
			if((bit&(1<<j))==0) continue;
			if(i==j) continue;

			temp = min(temp,a[i][j]+play(bit^(1<<i)));
			
		}
	}
	
	return dp[bit] = temp;
}

int main()
{
	int q,i,j;
	scanf("%d",&q);
	while(q--)
	{
		memset(dp,-1,sizeof dp);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);
		
		printf("%d\n",play((1<<n)-1));
	}
	return 0;
}
