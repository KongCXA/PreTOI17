/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;
long long va,s,bomb[100100],sum,c;
long long play(long long l,long long r)
{
	long long mid,n,lr,ll,k,tr;
	n = r-l+1;
	mid = (r+l)>>1;
	lr = upper_bound(bomb,bomb+c,r)-bomb;
	ll = lower_bound(bomb,bomb+c,l)-bomb;
	k = lr-ll;
	
	if(n<=1 && k<=0) return va;
	if(n<=1 && k>0) return k*s;
	
	if(k<=0) return va;
	else return min(k*s*n,play(l,mid)+play(mid+1,r));

}

int main()
{
	long long q,n,i;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld %lld %lld",&n,&c,&va,&s);
		for(i=0;i<c;i++)
		{
			scanf("%lld",&bomb[i]);
		}
		sort(bomb,bomb+c);
		printf("%lld\n",play(1,(1<<n)));

	}
	return 0;
}
