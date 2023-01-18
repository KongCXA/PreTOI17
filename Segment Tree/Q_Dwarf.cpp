/*
	Author	: KongCXA
	Language: C++
	Algo	: Segment Tree
*/
#include <bits/stdc++.h>
using namespace std;

int a[200100],matree[800400],mitree[800400],ma,mi,pos[200100];

void in(int now,int l,int r)
{
	if(l==r)
	{
		mitree[now] = matree[now] = pos[l];
		return;
	}
	int mid = (l+r)/2;
	in(now*2,l,mid);
	in(now*2+1,mid+1,r);
	mitree[now] = min(mitree[now*2],mitree[now*2+1]);
	matree[now] = max(matree[now*2],matree[now*2+1]);
	
}

void update(int now,int l,int r,int a,int b)
{
	if(l>a || r<a) return;
	if(l==r)
	{
		mitree[now] = matree[now] = b;
		return;
	}
	int mid = (l+r)/2;
	update(now*2,l,mid,a,b);
	update(now*2+1,mid+1,r,a,b);
	mitree[now] = min(mitree[now*2],mitree[now*2+1]);
	matree[now] = max(matree[now*2],matree[now*2+1]);
}

int querymi(int now,int l,int r,int ll,int rr)
{
	
	if(l>rr || r<ll) return 1e9+10;
	if(l>=ll && r<=rr)
	{
		return mitree[now];
	}
	int mid = (l+r)/2;
	
	return mi = min(querymi(now*2,l,mid,ll,rr),querymi(now*2+1,mid+1,r,ll,rr));
}

int queryma(int now,int l,int r,int ll,int rr)
{
	if(l>rr || r<ll) return -1e9+10;
	if(l>=ll && r<=rr)
	{
		return matree[now];
	}
	int mid = (l+r)/2;
	
	return ma = max(queryma(now*2,l,mid,ll,rr),queryma(now*2+1,mid+1,r,ll,rr));
}

int main()
{
	int n,q,i,op,l,r;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	in(1,1,n);
	while(q--)
	{
		scanf("%d %d %d",&op,&l,&r);
		if(op==1)
		{
			
			
			update(1,1,n,a[l],pos[a[r]]);
			update(1,1,n,a[r],pos[a[l]]);
			swap(pos[a[r]],pos[a[l]]);
			swap(a[l],a[r]);
		}
		if(op==2)
		{
			mi=1e9,ma=-1e9;
			if(queryma(1,1,n,l,r) - querymi(1,1,n,l,r) ==r-l) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
