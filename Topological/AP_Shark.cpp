/*
	Author	: KongCXA
	Language: C++
	Algo	: Topological
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[1010];
int deg[1010],mark[1010],a[1010];
int sum,i;

void dfs(int u)
{
	if(mark[u]==i) return;
	mark[u] = i;
	sum += a[u];
	for(auto x:g[u]) dfs(x);
}

int main()
{
	int n,m,u,v,ma=0,idx;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		deg[v]++;
	}
	for(i=1;i<=n;i++)
	{
		sum=0;
		if(!deg[i]) dfs(i);
		if(sum>ma) ma=sum,idx=i;
	}
	printf("%d %d\n",idx,ma);
	return 0;
}
