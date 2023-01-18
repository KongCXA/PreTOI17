/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int v,w,fuel,use,ch;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};
struct B{
	int v,w;
};
A now;
vector <B> g[105];
priority_queue<A> heap;
int cost[105],dis[105][105];
int main()
{
	int n,st,en,full,m,u,v,w,i,k,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&cost[i]);
	scanf("%d %d %d %d",&st,&en,&full,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int kong=1e9;
	for(k=1;k<=n;k++) 
	{
		for(i=1;i<=n;i++) for(j=0;j<=full;j++) dis[i][j] = 1e9;
		heap.push({st,0,0,k,1});
		while(!heap.empty())
		{
			now = heap.top();
			heap.pop();
			if(now.v==en && now.fuel == full)
			{
				kong = min(kong,dis[en][full]);
				break;
			}
			if(now.use == now.v && now.w<dis[now.v][full])
			{
				dis[now.v][full] = now.w;
				heap.push({now.v,dis[now.v][full],full,now.use,0});
			}
			if(now.fuel+1<=full && now.w+cost[now.v]<dis[now.v][now.fuel+1])
			{
				dis[now.v][now.fuel+1] = now.w+cost[now.v];
				heap.push({now.v,dis[now.v][now.fuel+1],now.fuel+1,now.use,now.ch});
			}
			for(auto x:g[now.v])
			{
				if(now.fuel-x.w>=0 && now.w<dis[x.v][now.fuel-x.w])
				{
					dis[x.v][now.fuel-x.w] = now.w;
					heap.push({x.v,now.w,now.fuel-x.w,now.use,now.ch});
				}
			}
		}
	}
		
	printf("%d\n",kong);
	return 0;
}

