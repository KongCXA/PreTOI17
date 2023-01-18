/*
	Author	: KongCXA
	Language: C++
	Algo	: Two Pointer
*/
#include <bits/stdc++.h>
using namespace std;

long long mp[1000100],dp[100100],a[100100],mark[1000100],qs[100100];

int main()
{
	long long i,j,n,q,k,cou,l,r,lb,ub,sz,range;
	for(i=1;i<=1000000;i++)
	{
		if(mp[i]==0)
		{
			for(j=1;i*j*j<=1000000;j++) mp[i*j*j]=i;
		}
	}
	
	scanf("%lld %lld %lld",&n,&q,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	

	for(i=1,j=0,cou=0;i<=n;i++)
	{
		if(i!=1)
		{
			mark[mp[a[i-1]]]--;
			if(mark[mp[a[i-1]]]==0) cou--;
		}
		while(j<=n&&cou<k)
		{
			j++;
			mark[mp[a[j]]]++;
			if(mark[mp[a[j]]]==1) cou++;	
		}
		if(cou==k) dp[i]=j;
		if(j==n+1 || cou<k) dp[i]=100100;
		qs[i]=dp[i]+qs[i-1];
	}
	

	
	while(q--)
	{
		scanf("%lld %lld",&l,&r);
		ub=upper_bound(dp+l,dp+1+n,r)-dp;
		sz = ub-l;
		range=qs[ub-1]-qs[l-1];
		printf("%lld\n",sz*r-range+sz);
	}
	return 0;
}
