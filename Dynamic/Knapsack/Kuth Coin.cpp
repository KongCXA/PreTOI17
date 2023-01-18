/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Knapsack)
*/
#include <bits/stdc++.h>
using namespace std;
int coins[] = {50,1,10,5,25};
int dp[100100];
int main()
{
	int i,j,k,n,q;
	dp[0] = 1;
	for(i=0;i<5;i++) for(k=0,j=coins[i];j<=100000;k++,j++) dp[j] += dp[k]%1000003,dp[j]%=1000003;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
