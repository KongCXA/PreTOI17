/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	long long x,y;
	bool operator<(const A& o)const{
		return y<o.y;
	}
};
A tmp[100100];
long long a[100100],b[100100],qs[100100],ans;

void mergesort(long long l,long long r)
{
	if(l>=r) return;
	long long mid = (l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	long long i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		qs[i] = a[i]+qs[i-1];
		qs[j] = a[j]+qs[j-1];
		if(a[i]<=a[j]) b[k++] = a[i++];
		else
		{
			ans += (mid-i+1)*a[j];
			ans += qs[mid] - qs[i-1];
			b[k++] = a[j++];
		}
		
	}
	while(i<=mid) b[k++] = a[i++];
	while(j<=r) b[k++] = a[j++];
	for(i=l;i<=r;i++) a[i] = b[i];
}

int main()
{
	long long n,i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&tmp[i].x,&tmp[i].y);

	sort(tmp+1,tmp+n+1);
	for(i=1;i<=n;i++) a[i] = tmp[i].x;
	mergesort(1,n);
	printf("%lld\n",ans);
	return 0;
}
