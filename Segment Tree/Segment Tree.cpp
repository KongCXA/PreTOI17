/*
	Author	: KongCXA
	Language: C++
	Algo	: Segment Tree
*/
#include <bits/stdc++.h>
using namespace std;

int a[100100],sextree[400400],ans;


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
	sextree[now] = max(sextree[now*2],sextree[now*2+1]);
}

int query(int now,int l,int r,int ll,int rr)
{
	if(l>rr || r<ll) return -1e9;
	if(l>=ll && r<=rr)
	{
		return sextree[now];
	}
	int mid = (l+r)/2;
	return ans = max(query(now*2,l,mid,ll,rr),query(now*2+1,mid+1,r,ll,rr));
}

int main()
{
	int n,q,i,l,r;
	char op;
	scanf("%d %d",&n,&q);
	while(q--)
	{
		scanf(" %c %d %d",&op,&l,&r);
		if(op=='U')
		{
			update(1,1,n,l,r);
		}
		if(op=='P')
		{
			ans=1e9;
			printf("%d\n",query(1,1,n,l,r));	
		}
	}
	return 0;
}
