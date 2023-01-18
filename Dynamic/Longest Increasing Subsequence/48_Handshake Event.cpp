/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Longest Increasing Subsequence)
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	long long pos,neg;
	bool operator < (const A& o)const{
		if(pos == o.pos) return neg < o.neg;
		return pos < o.pos; 
	}
};

A a[100100];
long long dp[100100];

int main()
{
	long long q,n,v,x,t,i,idx,kong;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld",&n,&v);
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld",&x,&t);
			a[i].pos = x+v*t;
			a[i].neg = v*t-x;
		}
		
		sort(a,a+n);
		dp[0] = a[0].neg;
		for(i=1,kong=1;i<n;i++)
		{
			idx = upper_bound(dp,dp+kong,a[i].neg)-dp;
			if(idx == kong) kong++;
			dp[idx] = a[i].neg;
		}
		printf("%lld",kong);
		
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
	}
	return 0;
}
