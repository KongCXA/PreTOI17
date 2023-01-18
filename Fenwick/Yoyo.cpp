/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & -(x))
long long fenwick[500500];
const long long N=500500;
char s[5];
int main()
{
	long long n,m,a,b,c,i,ans;
	scanf("%lld %lld",&n,&m);
	while(m--)
	{
		scanf(" %s",s);
		if(s[0]=='Y')
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			if(c<b) swap(b,c);
			for(i=b  ;i<=N;i+=LSB(i)) fenwick[i] += (a);
			for(i=c+1;i<=N;i+=LSB(i)) fenwick[i] += -(a);
			
		}
		if(s[0]=='A')
		{
			scanf("%lld",&a);
			for(i=a,ans=0;i>0;i-=LSB(i)) ans += (fenwick[i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
