/*
	Author	: KongCXA
	Language: C++
	Algo	: Segment Tree
*/
#include <bits/stdc++.h>
using namespace std;

int a[100100],segtree[400400],lazy[400400];


void update(int now,int l,int r,int ll,int rr)
{
	if(lazy[now])
	{
		lazy[2*now] ^= 1;
		lazy[2*now+1] ^= 1;
		lazy[now]=0;
		segtree[now]=(r-l+1)-segtree[now];
	}
	if(l>rr || r<ll) return;
	if(l>=ll && r<=rr)
	{
		segtree[now] = (r-l+1)-segtree[now];
		lazy[2*now]^=1; lazy[2*now+1]^=1;
		return;
	}
	int mid = (l+r)/2;
	update(now*2,l,mid,ll,rr);
	update(now*2+1,mid+1,r,ll,rr);
	segtree[now] = segtree[now*2]+segtree[now*2+1];
}

int query(int now,int l,int r,int ll,int rr)
{
	if(lazy[now])
	{
		lazy[2*now] ^= 1;
		lazy[2*now+1] ^= 1;
		lazy[now]=0;
		segtree[now]=(r-l+1)-segtree[now];
	}
	if(l>rr || r<ll) return 0;
	if(l>=ll && r<=rr)
	{
		return segtree[now];
	}
	int mid = (l+r)/2;
	return query(now*2,l,mid,ll,rr)+query(now*2+1,mid+1,r,ll,rr);
}

int main()
{
	int n,q,i,op,l,r;
	scanf("%d %d",&n,&q);
	while(q--)
	{
		scanf("%d %d %d",&op,&l,&r);
		if(op==0)
		{
			update(1,1,n,l,r);
		}
		if(op==1)
		{
			printf("%d\n",query(1,1,n,l,r));	
		}
	}
	return 0;
}
