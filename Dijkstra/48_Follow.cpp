/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int v,w,idx;
};

vector< A > g[1010];
int dis[1010],route[1010];
pair<int,int> node[10100];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dijk;


int main()
{
	int q,n,m,s,e,t,p,u,v,w,i,sum,wi,idx;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&m);
		scanf("%d %d %d %d",&s,&e,&t,&p);
		for(i=1;i<=p;i++) scanf("%d",&route[i]);
		for(i=0;i<m;i++)
		{	
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back({v,w,i});
			g[v].push_back({u,w,i});
		}
		sum = 0;
		for(i=1;i<p;i++)
		{
			for(auto x:g[route[i]])
			{
				if(x.v==route[i+1])
				{
					node[x.idx] = {sum,sum+x.w};
					sum += x.w;
					break;
				}
			}
		}
		for(i=0;i<=n;i++) dis[i] = 1e9;
		dijk.push({t,s}); dis[s] = t;
		while(!dijk.empty())
		{
			u = dijk.top().second; w = dijk.top().first;
			dijk.pop();
			for(auto x:g[u])
			{
				v = x.v; wi = x.w; idx = x.idx;
				if(node[idx].first <= w && w < node[idx].second)
				{
					if(dis[v] > wi + node[idx].second)
					{
						dis[v] = wi+node[idx].second;
						dijk.push({dis[v],v});
					}
				}
				else if(dis[v]>w+wi)
				{
					dis[v] = wi+w;
					dijk.push({dis[v],v});
				}
			}	
		}
		printf("%d\n",dis[e]-t);
		for(i=0;i<m;i++) node[i]={0,0};
		for(i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
