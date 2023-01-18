/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;
int dp[520][520],a[520][520],ans;

void play(int si,int sj,int ei,int ej,int n)
{
	int qs = dp[ei][ej]-dp[si-1][ej]-dp[ei][sj-1]+dp[si-1][sj-1];
	if(qs == n*n || qs == 0)
	{
		ans+=2;
		return;
	}
	else ans+=1;
	n/=2;
	play(si,sj,si+n-1,sj+n-1,n);
	play(si,sj+n,si+n-1,ej,n);
	play(si+n,sj,ei,sj+n-1,n);
	play(si+n,sj+n,ei,ej,n);
}

int main()
{
	int q,n,i,j;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1,ans=0;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				dp[i][j] = a[i][j]+dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		play(1,1,n,n,n);
		printf("%d\n",ans);
		memset(dp,0,sizeof 0);
	}
	return 0;
}
