/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	long long a,b;
	
	bool operator < (const A& o) const{
		return b < o.b;
	}
	
};

A a[500500];

long long qs1[500500],qs2[500500];

int main()
{
	long long n,i,sum=0,mi=1e18,mih=1e18,up,down,ans;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].a);
		if(a[i].a<mih) mih = a[i].a;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].b);
	}
	sort(a+1,a+1+n);
	//qs1 = dot height
	//qs2 = box height
	for(i=1;i<=n;i++)
	{
		qs1[i] = qs1[i-1] + a[i].b;
		qs2[i] = qs2[i-1] + a[i].a;
	}
	for(i=1;i<=n;i++)
	{
		down = (qs1[n] - qs1[i]) - (n-i)*a[i].b;
		up = (qs1[i-1]) - (i-1)*a[i].b + qs2[i-1];
		if(a[i].b>mih) break;
		if(up+down < mi)
		{
			mi = up+down;
			ans = a[i].b;	
		}
	}
	
	printf("%lld %lld",ans,mi);
	return 0;
}
