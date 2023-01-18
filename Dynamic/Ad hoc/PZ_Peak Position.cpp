/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
const long long M=1e9+9;
long long dp[1000100],fac[1000100],facno3[1000100];

int main()
{
	long long i,q,n;
	fac[1]=1;fac[2]=2;fac[3]=6;
	fac[1]=fac[2]=0;facno3[3] = 2;
	for(i=4;i<=1000000;i++) fac[i] = (fac[i-1]*i)%M,facno3[i] = (facno3[i-1]*i)%M;
	dp[1]=dp[2]=0;dp[3]=2;
	
	for(i=4;i<=1000000;i++)
	{
		dp[i] = (fac[i-1]*(i-2))%M;
		dp[i] += (dp[i-1]*2)%M;
		dp[i]%=M;
		dp[i] += (dp[i-1]*(i-1-3))%M;
		dp[i]%=M;
	}
	
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		printf("%lld\n",dp[n]);
		/*
		supermath minimize the sigma with formular
		sum(1 to n,(i-1)(i-2) * n-3)
		== (n-2)n!/3
		printf("%lld\n", ((n-2)*facno3[n])%M);
		*/
	}
	return 0;
}
