/*
	Author	: KongCXA
	Language: C++
	Algo	: Greedy
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int s,e;
	bool operator <(const A& o)const{
		if(s==o.s) return e>o.e;
		return s<o.s;
	}
};
A a[100100];

int main()
{
	int q,n,t,i,e,s,ans;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&t);
		for(i=1;i<=n;i++) scanf("%d %d",&a[i].s,&a[i].e),a[i].e = (a[i].e*t)+a[i].s;
		sort(a+1,a+1+n);
		for(i=1,e=0,s=0,ans=0;i<=n;i++)
		{
			if(a[i].e<e) continue;
			else if(a[i].e==e && a[i].s>s) continue;
			e = a[i].e;	
			s = a[i].s;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
