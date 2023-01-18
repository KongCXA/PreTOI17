/*
	Author	: KongCXA
	Language: C++
	Algo	: Bipartite(Depth First Search) + Binary Search
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[300100];
int mark[300100];
pair<int , int> a[300100];

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
	int n,m,i,l,r,mid,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	
	l=1,r=m;
	while(l<r)
	{
		mid = (l+r)/2;
		for(i=1;i<=mid;i++)
		{
			g[a[i].first].push_back(a[i].second);
			g[a[i].second].push_back(a[i].first);
		}

		for(i=1,k=0;i<=mid;i++)
		{
			if(!mark[i])
			{
				if(dfs(i,1)==0)
				{
					k = 1;
					break;
				}
			}
		}
		
		if(k) r = mid;
		else l = mid+1; 
		for(i=1;i<=n;i++) g[i].clear();
		memset(mark,0,sizeof mark);
	}
	printf("%d\n",l);
	return 0;
}
