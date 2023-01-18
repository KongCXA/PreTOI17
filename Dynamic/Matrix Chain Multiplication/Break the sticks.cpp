/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];
int a[1010];
int kong(int l,int r,int len,int first)
{
	
	if(l>=r) return 0;
	if(dp[l][r]) return dp[l][r];
	int mi = 1e9,temp;
	for(int k=l;k<r;k++) 
	{
		temp = kong(l,k, a[k]-first , first ) + kong(k+1,r, len-a[k]+first , a[k] ) + len;
		mi = min(mi,temp);
	
	}
	return dp[l][r] = mi;
}

int main()
{
	int l,p,i;
	scanf("%d %d",&l,&p);
	for(i=0;i<p;i++) scanf("%d",&a[i]);
	printf("%d\n",kong(0,p,l,0));
	return 0;
}
