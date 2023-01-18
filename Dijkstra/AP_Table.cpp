/*
	Author	: KongCXA
	Language: C++
	Algo	: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int u,w;
	bool operator < (const A& o) const{
		return w>o.w;
	}
	
};

int check(char cc,char oc,int x,int y)
{
	if(cc==oc) return x;
	if(cc!=oc) return y;
}

int dj[4]={1,-1,0,0};
int dis[1000][1000];
char c[1000];
vector< A > g[1000];
priority_queue< A > dijk;


int main()
{
	int q,n,x,y,i,j,ma,u,w;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&n,&x,&y);
		dj[2] = n; dj[3] = -n;
		for(i=1;i<=n*n;i++) scanf(" %c",&c[i]);
		for(i=1;i<=n*n;i++) 
		{
			for(j=0;j<=3;j++)
			{
				if(i+dj[j]<=0||i+dj[j]>n*n) continue;
				if(i%n==1 && j==1) continue;
				if(i%n==0 && j==0) continue;
				g[i].push_back({i+dj[j],check( c[i+dj[j]] , c[i] ,x,y)});
			}	
		}
		for(i=1;i<=900;i++) for(j=1;j<=900;j++) dis[i][j] = 1e9;
		for(i=1;i<=n*n;i++)
		{
			dijk.push({i,0});
			dis[i][i] = 0;
			while(!dijk.empty())
			{
				u = dijk.top().u; w = dijk.top().w; dijk.pop();
				for(auto x:g[u])
				{
					if(dis[i][x.u] > w+x.w)
					{
						dis[i][x.u] = w+x.w;
						dijk.push({x.u,w+x.w});
					}
				}
			}
		}
		ma = 0;
		for(i=1;i<=n*n;i++) 
		{
			for(j=1;j<=n*n;j++) 
			{
				ma = max(ma,dis[i][j]);
			}	
		}
		printf("%d\n",ma);
		for(i=1;i<=n*n;i++) g[i].clear();
	}
	return 0;
}
