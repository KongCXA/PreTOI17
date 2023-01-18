/*
	Author	: KongCXA
	Language: C++
	Algo	: Bitmask
*/
#include <bits/stdc++.h>
using namespace std;

double dp[25][1100000],a[25][25];
int n;

double play(int state,int bit)
{
	if(state==n) return 1;
	if(dp[state][bit]!=-1) return dp[state][bit];
	double ans=0;
	for(int i=0;i<n;i++) if(!(bit&(1<<i))) ans = max(ans,play(state+1,bit|(1<<i))*a[state][i]);
	return dp[state][bit] = ans;
	
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lf",&a[i][j]),a[i][j]/=100;
	for(i=0;i<n;i++) for(j=0;j<(1<<n);j++) dp[i][j] = -1;
	printf("%.2lf",play(0,0)*100);
	return 0;
}
