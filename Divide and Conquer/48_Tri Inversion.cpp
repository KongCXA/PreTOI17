/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	long long x,y;
};

long long ll[100100],rr[100100];
A a[100100],b[100100];

void mergesort(long long l,long long r)
{
	if(l>=r) return;
	long long mid = (l+r)>>1;
	mergesort(l,mid);
	mergesort(mid+1,r);
	
	long long i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(a[i].x<=a[j].x)
		{
			rr[a[i].y] += (j-1) - (mid+1)+1;
			b[k++] = a[i++];
		}
		else
		{
			ll[a[j].y] += mid -i +1;
			b[k++] = a[j++];
		}
	}
	while(i<=mid)
	{
		rr[a[i].y] += r-(mid+1)+1;
		b[k++] = a[i++];
	}
	while(j<=r) b[k++] = a[j++];
	for(i=l;i<=r;i++) a[i] = b[i];
	
}

int main()
{
	long long q,n,i,ans;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i].x);
			a[i].y = i;
		}
		mergesort(0,n-1);
		for(i=1,ans=0;i<n-1;i++) ans+=ll[i]*rr[i];
		printf("%lld",ans);
		memset(ll,0,sizeof ll);
		memset(rr,0,sizeof rr);
	}
	return 0;
}
