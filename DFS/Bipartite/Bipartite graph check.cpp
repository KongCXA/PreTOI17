/*
	Author	: KongCXA
	Language: C++
	Algo	: Bipartite(Depth First Search)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int mark[100100];

int dfs(int u,int color)
{
	if(mark[u]!=0 && mark[u]==color) return 1;
	if(mark[u]!=0 && mark[u]!=color) return 0;
	mark[u] = color;
	for(auto x:g[u])
	{
		if(dfs(x,3-color)==0) return 0;
	}
	return 1;
}

int main()
{
	int q,n,m,u,v,i,k;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&m);
		while(m--)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		
		for(i=1,k=0;i<=n;i++)
		{
			if(!mark[i])
			{
				if(dfs(i,1)==0)
				{
					k=1;
					break;
				}
			}
		}
		
		if(k) printf("no\n");
		else printf("yes\n");
		for(i=1;i<=n;i++) g[i].clear();
		memset(mark,0,sizeof mark);
	}
	return 0;
}

