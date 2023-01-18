/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int u,w,state;
	bool operator <(const A& o)const{
		return w>o.w;
	}
};

priority_queue<A> dijk;
vector<A> g[100100];
int dis[2][100100];

int main()
{
	int n,m,s,t,i,u,v,w,state,sum=0;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		sum+=w;
	}
	for(i=0;i<=n;i++) dis[0][i]=dis[1][i]=1e9;
	
	dis[0][s] = 0;
	dijk.push({s,0,0});
	while(!dijk.empty())
	{
		u = dijk.top().u; w = dijk.top().w; state = dijk.top().state;
		dijk.pop();
		for(auto x:g[u])
		{
			if(!state && dis[1][x.u]>w)
			{
				dis[1][x.u] = w;
				dijk.push({x.u,w,1});
			}
			if(dis[state][x.u]>w+x.w)
			{
				dis[state][x.u] = w+x.w;
				dijk.push({x.u,dis[state][x.u],state});
			}
		}
	}
	printf("%d\n",sum-dis[1][t]);
	return 0;
}
