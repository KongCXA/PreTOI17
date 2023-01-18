/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;

int now,n,a[5050],dp[5050][110];

int play(int u,int k)// 3 3
{
	if(u>n) return 0;
	if(dp[u][k]!=-1) return dp[u][k];
	if(k==0) return 0;
	int i,now=0;
	
	for(i=0;i<=k-1;i++)
	{
		now = max(now,a[u]+play(2*u,i)+play(2*u+1,k-1-i));
		
	}
	return dp[u][k] = now;

}

int main()
{
	int k,i,ma=0;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,-1,sizeof dp);
	for(i=1;i<=n;i++) ma = max(ma,play(i,k));
	printf("%d\n",ma);
	return 0;
}
