/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;
long long cou,a[11000010],b[11000010],k,mark[11000010];

void com(long long num,long long state,long long last,long long find)
{
	long long i,sum;
	if(state==k-1)
	{
		cou++;
		if(cou==find) for(i=0;i<state;i++) mark[b[i]]=1;
		return;
	}
	for(i=last+1;i<=num;i++)
	{
			a[i]=1;
			b[state] = i;
			com(num,state+1,i,find);	
			a[i] = 0;

	}
}

long long cnr(long long n,long long r)
{
	long long ma = max(r,n-r);
	long long mi = min(r,n-r);
	long long up=1;
	for(long long i=n;i>ma;i--) up*=i;
	for(long long i=2;i<=mi;i++) up/=i;
	return up;
}


int main()
{
	long long n,sum,i,m,range,lon;
	scanf("%lld %lld",&n,&k);
	if(n==1)
	{
		for(i=1;i<=k;i++) printf("1");
		return 0;
	}

	m=n;
	n--;
	sum=1;
	for(i=1;n-cnr(i+k-1,k-1)>0;i++) sum+=cnr(i+k-1,k-1) , n-=cnr(i+k-1,k-1);
	range = cnr(i+k-1,k-1)-(m-sum)+1;
	lon = k+i;
	com(i+k-1,0,0,range);
	printf("1");
	for(i=1;i<lon;i++) printf("%lld",mark[i]);
	
	return 0;
}
