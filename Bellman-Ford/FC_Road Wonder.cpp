/*
	Author	: KongCXA
	Language: C++
	Algo	: Bellman-Ford
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int u,v,w;
};
A e[1110];
int dis[2000],dis2[2000];

int main()
{
	int n,m,k,t,i,u,v,w,j,s;
	scanf("%d %d %d %d",&n,&m,&k,&t);

	for(i=1;i<=m+k;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		
		if(i>m) w*=-1;
		e[i].u = u; 
		e[i].v = v;
		e[i].w = w;
	}

	while(t--)
	{
		scanf("%d",&s);
		for(i=1;i<=n;i++) dis[i] = 1e9;
		dis[s] = 0;
		
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=m+k;j++)
			{
				if(e[j].u!=1e9 && dis[e[j].u]+e[j].w < dis[e[j].v])
				dis[e[j].v] = min(dis[e[j].v],dis[e[j].u]+e[j].w);
			}
		}
		for(i=1;i<=n;i++) dis2[i] = dis[i];
		for(i=1;i<=m+k;i++)
		{
			if(e[j].u!=1e9 && dis[e[j].u]+e[j].w < dis[e[j].v])
			dis[e[i].v] = min(dis[e[i].v],dis[e[i].u]+e[i].w);
		}
		for(i=1;i<=n;i++)
		{
			if(dis[i]!=dis2[i] || dis[i]==1e9) printf("-1 ");
			else printf("%d ",dis[i]);
		}
		printf("\n");
	}
	return 0;
}
