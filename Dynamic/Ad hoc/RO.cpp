/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;

long long qs[1001000];
unordered_map<long long,long long> mark;

int main()
{
	long long n,k,i,ans=0;
	char c;
	scanf("%lld %lld",&n,&k);
	mark[0]=1;
	for(i=2;i<=n+1;i++)
	{
		scanf(" %c",&c);
		if(c=='R') qs[i]=k+qs[i-1];
		else qs[i]=qs[i-1]-1;
		if(mark[qs[i]]) ans=max(ans,i-mark[qs[i]]);
		if(!mark[qs[i]]) mark[qs[i]]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
