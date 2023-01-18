/*
	Author	: KongCXA
	Language: C++
	Algo	: Minimum Spanning Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int u,v,w;
	bool operator < (const A& o)const{
		return w < o.w;
		
	}
};

A a[1000100];
int p[1000100],deg[1000100];

int find(int u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]);
}

int main()
{
	int q,n,i,j,num,idx;
	scanf("%d",&q);
	while(q--)
	{
		int cou=1,ma=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&num);
				if(j>i) p[cou] = cou,a[cou++] = {i,j,num};
			}
		}
		sort(a+1,a+cou);
		
		
		for(i=1;i<cou;i++)
		{
			if(find(a[i].u)!=find(a[i].v))
			{
				
				p[find(a[i].u)] = find(a[i].v);
				deg[a[i].u]++; deg[a[i].v]++;
			}
		}
		
		for(i=n;i>=1;i--)
		{
			if(deg[i]>=ma)
			{
				ma = deg[i];
				idx = i;
			}
		}
		printf("%d %d\n",idx,ma);
		memset(deg,0,sizeof deg);
		
	}
	return 0;
}
