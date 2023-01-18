/*
	Author	: KongCXA
	Language: C++
	Algo	: Depth First Search + Dynamic Programming
*/
#include <bits/stdc++.h>
using namespace std;

int mark[100100];
long long all,mi,a[100100];
vector<int> g[100100];

void dfs(int u)
{
	
	for(auto x:g[u])
	{
		if(mark[x]) continue;
		mark[u] = 1;
		dfs(x);
		
		a[u] += a[x];
	}
	mi = min(mi,abs(all-a[u]*2));
}

int main()
{
	int q,n,i,u,v;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(i=1,all=0;i<=n;i++) scanf("%lld",&a[i]), all+=a[i];
		mi = 1e18;
		dfs(1);
		printf("%lld\n",mi);
		for(i=1;i<=n;i++) g[i].clear();
		memset(a,0,sizeof a);
		memset(mark,0,sizeof mark);
	}
	return 0;
}
