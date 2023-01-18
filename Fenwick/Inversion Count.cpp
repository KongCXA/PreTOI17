/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & (-x))
const int FEN = 1e5 + 10;
long long a[FEN],fenwick[FEN],n;
map<int,int> mp;

int main()
{
	long long i,j,ans=0,temp,it=1;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),mp[a[i]]=1;
	for(auto x:mp) mp[x.first] = it++;

	for(i=n;i>=1;i--)
	{
		if(i<n) for(j=mp[a[i]]-1,temp=0;j>0;j-=LSB(j)) ans+= fenwick[j],ans+=temp;
		for(j=mp[a[i]];j<=FEN;j+=LSB(j))  fenwick[j]++;	
	}
	printf("%lld",ans);
	return 0;
}
