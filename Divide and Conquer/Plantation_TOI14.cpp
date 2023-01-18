/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int x,y;
	bool operator<(const A& o)const{
		return x<o.x;
	}
};
A a[100100];

double di(A a,A b)
{
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x) + 1.0*(a.y-b.y)*(a.y-b.y));
}

double close(int l,int r)
{
	int i,j,k,mid;
	double ans = 2e9,dl,dr,d,tmp;
	
	if(r-l+1<=3)
	{
		for(i=l;i<r;i++) for(j=i+1;j<=r;j++) ans = min(ans,di(a[i],a[j]));	
		return ans;
	}
	mid = (r+l)>>1;
	d = min( close(l,mid),close(mid+1,r) );
	
	vector<A> strip;
	for(i=l;i<=r;i++) if(abs(a[i].x - a[mid].x)<d) strip.push_back({a[i].y,a[i].x});
	
	sort(strip.begin(),strip.end());	
	
	for(i=0,tmp=d;i<strip.size();i++)
	{
		for(k=i+1 ; k<strip.size() && strip[k].x-strip[i].x <tmp ;k++) d = min(d,di(strip[i],strip[k]));
	}
	return d;
}

int main()
{
	int q,n,r,d,i;
	double ans;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&n,&r,&d);
		for(i=0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].y);
		sort(a,a+n);
		ans = close(0,n-1);
		if(ans>=2*r+d) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
