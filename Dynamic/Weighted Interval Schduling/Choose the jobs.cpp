/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Weighted Interval Schduling)
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int s,e,w;
	bool operator < (const A& o)const{
		if(e!=o.e) return e<o.e;
		return s<o.s;
	}
};
A a[100100];
int b[100100],dp[100100];

int main()
{
	int n,i,idx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].w);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) b[i]=a[i].e;
	for(i=1;i<=n;i++)
	{
		idx = lower_bound(b+1,b+n+1,a[i].s)-(b+1);
		dp[i] = max(dp[i-1],dp[idx]+a[i].w);
	}
	printf("%d\n",dp[n]);
	return 0;
}
