/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & (-x))
const int FEN = 1e5 + 10;
long long fenwick[FEN],fenwick2[FEN];
pair<long long,long long> a[100100];

int main()
{
	long long i,j,temp,ans,n;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&a[i].second,&a[i].first);
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
	{
		for(j=a[i].second;j<=FEN;j+=LSB(j)) fenwick[j]++;
		for(j=a[i].second-1,temp=0;j>=1;j-=LSB(j)) temp += fenwick[j];
		ans += a[i].second * temp;
		
		for(j=a[i].second;j<=FEN;j+=LSB(j)) fenwick2[j]+=a[i].second;
		for(j=a[i].second-1,temp=0;j>=1;j-=LSB(j)) temp += fenwick2[j];
		ans+= temp;
	}
	printf("%lld\n",ans);
	return 0;
}
