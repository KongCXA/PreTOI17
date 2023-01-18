/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	long long a[5][5];
};
long long M,n;
A mul(A a,A b)
{
	long long i,j,k;
	A tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp.a[i][j]=0;
			for(k=0;k<n;k++)
			{
				tmp.a[i][j] += a.a[i][k]*b.a[k][j];
				tmp.a[i][j] %= M;
			}
		}
	}
	return tmp;
}



A p[70],ans;

int main()
{
	long long i,j,b;
	scanf("%lld",&n);
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lld",&p[0].a[i][j]);
	for(i=0;i<n;i++) ans.a[i][i] = 1;
	
	scanf("%lld %lld",&b,&M); 
	if(b==0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j) printf("%lld ",1ll%M);
				else printf("0 ");
			}
			printf("\n");
		}
		return 0;
	}
	for(i=1;i<=63;i++) p[i]=mul(p[i-1],p[i-1]);
	for(i=0;i<=63;i++) if((1ll<<i)&b) ans = mul(ans,p[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) printf("%lld ",ans.a[i][j]);
		printf("\n");
	}
	return 0;
}
