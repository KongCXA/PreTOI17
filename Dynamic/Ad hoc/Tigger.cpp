/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[1010],n;

int play(int now,int last)
{
	if(now<1||now>n) return 1e9;
	if(now==n) return a[now];
	if(dp[now][last]!=-1) return dp[now][last];
	return dp[now][last] = a[now]+min(play(now-last,last),play(now+last+1,last+1));
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,-1,sizeof dp);
	printf("%d\n",play(2,1));
	return 0;
}
