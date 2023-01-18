/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & -(x))
const long long N=800000;
long long fenwick[800800];
char s[5];
int main()
{
	long long n,m,x,y,i,ans;
	scanf("%lld %lld",&n,&m);
	while(m--)
	{
		scanf(" %s %lld %lld",s,&x,&y);
		if(s[0]=='B') for(i=y;i<=N;i+=LSB(i)) fenwick[i]+=x;
		if(s[0]=='F')
		{
			for(i=y,ans=0;i>0;i-=LSB(i)) ans+=fenwick[i];
			for(i=x-1;i>0;i-=LSB(i)) ans-=fenwick[i];
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}
