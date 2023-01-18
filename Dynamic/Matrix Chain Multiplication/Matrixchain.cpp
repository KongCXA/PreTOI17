/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

int l[20],r[20],dp[20][20],path[20][20];
int kong(int ll,int rr)
{
	
	if(ll==rr) return 0;
	if(dp[ll][rr]) return dp[ll][rr];
	int mi = 1e9,now;
	for(int k = ll ; k<rr ;k++)
	{
		now = kong(ll,k) + kong(k+1,rr) + (l[ll]*r[k]*r[rr]);
		if(mi > now)
		{
			mi = now;
			path[ll][rr] = k;
		}
	}
	return dp[ll][rr] = mi;
}

void print(int ll,int rr)
{
	if(ll==rr)
	{
		printf("A%d",ll+1);
		return;
	}
	printf("(");
	print(ll,path[ll][rr]);
	printf(" x ");
	print(path[ll][rr]+1,rr);
	printf(")");
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
	}
	printf("%d\n",kong(0,n-1));
	print(0,n-1);
	return 0;
}
