/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1010][10010];
const int M=1e9+7;

int main()
{
	int n,d,i,j,tmp;
 	scanf("%d %d",&n,&d);
 	dp[1][0]=1;
 	for(i=2;i<=n;i++)
 	{
 		tmp = 0;
 		for(j=0;j<=d;j++)
 		{
 			tmp += dp[i-1][j];
 			if(j>=i) tmp -= dp[i-1][j-i];
 			tmp %= M;
 			dp[i][j] = (tmp+M)%M;
		}
	}
	printf("%d\n",dp[n][d]);
	return 0;
}


