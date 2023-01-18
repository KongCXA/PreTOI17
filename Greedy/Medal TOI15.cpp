/*
	Author	: KongCXA
	Language: C++
	Algo	: Greedy
*/
#include <bits/stdc++.h>
using namespace std;

long long a[500500],b[500500],c[500500];

int main()
{
	long long n,i,kong=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	for(i=0;i<n;i++) scanf("%lld",&b[i]);
	sort(a,a+n);
	sort(b,b+n,greater<long long>());
	
	for(i=0;i<n;i++) c[i] = a[i]+b[i];
	sort(c,c+n);
	for(i=1;i<n;i++) kong += abs(c[i] - c[i-1]);
	
	printf("%lld",kong);
	return 0;	
}
