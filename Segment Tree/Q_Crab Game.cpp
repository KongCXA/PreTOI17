/*
	Author	: KongCXA
	Language: C++
	Algo	: Segment Tree
*/
#include <bits/stdc++.h>
using namespace std;

int a[100100],sextree[400400],ans;

void in(int now,int l,int r)
{
	if(l==r)
	{
		sextree[now] = a[l];
		return;
	}
	int mid = (l+r)/2;
	in(now*2,l,mid);
	in(now*2+1,mid+1,r);
	sextree[now] = min(sextree[now*2],sextree[now*2+1]);
	
}

void update(int now,int l,int r,int a,int b)
{
	if(l>a || r<a) return;
	if(l==r)
	{
		sextree[now] = b;
		return;
	}
	int mid = (l+r)/2;
	update(now*2,l,mid,a,b);
	update(now*2+1,mid+1,r,a,b);
	sextree[now] = min(sextree[now*2],sextree[now*2+1]);
}

int query(int now,int l,int r,int ll,int rr)
{
	if(l>rr || r<ll) return 1e9+10;
	if(l>=ll && r<=rr)
	{
		return sextree[now];
	}
	int mid = (l+r)/2;
	return ans = min(query(now*2,l,mid,ll,rr),query(now*2+1,mid+1,r,ll,rr));
}

int main()
{
	int n,q,i,op,l,r;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	in(1,1,n);
	while(q--)
	{
		scanf("%d %d %d",&op,&l,&r);
		if(op==1)
		{
			update(1,1,n,l,r);
		}
		if(op==2)
		{
			ans=1e9;
			printf("%d\n",query(1,1,n,l,r));	
		}
	}
	return 0;
}
