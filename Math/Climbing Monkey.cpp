/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int idx,h;
	bool operator <(const A& o)const{
		if(h==o.h) return idx<o.idx;
		return h<o.h;
	}
};

A bri[1000200];
int a[200200];

int main()
{
	int m,n,k,i,now,ans,ans2,l,r;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=k;i++) scanf("%d %d",&bri[i].idx,&bri[i].h);
	sort(bri+1,bri+1+k);
	
	for(i=k;i>=1;i--) swap(a[bri[i].idx] , a[bri[i].idx+1]);
	
	scanf("%d",&now);
	ans=a[now], ans2=0;
	for(i=1;i<=k;i++)
	{
		l = bri[i].idx; r=l+1;
		if(now>1 && i>1 && bri[i].h == bri[i-1].h && now-1==bri[i-1].idx+1) ans2=max(ans2,a[now-2]);
		else ans2 = max(ans2,a[now-1]);
		ans2 = max(ans2,a[now+1]);
		if(now == l) now=r;
		else if(now == r) now=l;
		swap(a[l],a[r]);
	}
	if(ans2>ans) printf("%d\nUSE",ans2);
	else printf("%d\nNO",ans);
	return 0;
}
