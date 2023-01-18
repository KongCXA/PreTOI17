/*
	Author	: KongCXA
	Language: C++
	Algo	: Minimum Spanning Tree
*/
#include <bits/stdc++.h>
using namespace std;


struct A{
	int u;
	double w;
	bool operator < (const A& o)const{
		return w<o.w;
	}
};
A now;
priority_queue<A> heap;
vector<A> g[2510];
int dis[2510];

int main()
{
	int n,m,i,v,st,en,u;
	double w,num;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %lf",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	scanf("%d %d %lf",&st,&en,&num);
	dis[st] = 1e9;
	heap.push({st,1e9});
	while(!heap.empty())
	{
		u = heap.top().u; w = heap.top().w;
		heap.pop();
		
		if(u==en)
		{
			printf("%.0lf\n",ceil(num/(w-1)));
			break;
		}
		for(auto x:g[u])
		{
			if(dis[x.u]<min(w,x.w)) 
			{
				dis[x.u] = min(w,x.w);
				heap.push({x.u,dis[x.u]});
			}
		}
	}
	return 0;
}
