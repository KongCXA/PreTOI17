/*
	Author	: KongCXA
	Language: C++
	Algo	: Minimum Spanning Tree
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
struct A{
	int u,v,w;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};


A edge[70100];
int p[50100];
int find(int u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]);
}

int main()
{
	int q,n,m,i,num,ans,u,v,w;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&m,&n);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&num);
			mp[num] = i;
			p[i] = i;
		}
		
		for(i=0,ans=0;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			edge[i]={mp[u],mp[v],w};
			ans += w;
		}
		
		sort(edge,edge+n);
		for(i=0;i<n;i++)
		{
			if(p[find(edge[i].u)]!=p[find(edge[i].v)])
			{
				ans-=edge[i].w;
				p[find(edge[i].u)]=find(edge[i].v);
			}
		}
		printf("%d\n",ans);
		mp.clear(); 	
	}
	return 0;
}
