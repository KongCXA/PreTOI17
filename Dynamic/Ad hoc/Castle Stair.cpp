/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[100100],a[100100],qs[100100];
const int M=95959;

int main()
{
	int q,n,k,i,j;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&n,&k,&a[1]);
		dp[1] = qs[1] = 1;
		for(i=2,j=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			while(a[i]-k > a[j] && j<=i) j++;
			dp[i] = (qs[i-1]-qs[j-1]+M)%M;
			qs[i] = (qs[i-1]+dp[i])%M;
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
