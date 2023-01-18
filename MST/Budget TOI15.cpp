/*
	Author	: KongCXA
	Language: C++
	Algo	: Minimum Spanning Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int u,v,w;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};

priority_queue< A > heap;
int mi[1000100],p[3030];

int find(int u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]); 
}

int main()
{
	int n,m,i,u,v,w,r,num,c,d,ma=0,ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) p[i] = i;
	for(i=0;i<=1000000;++i) mi[i] = 1e9;
	while(m--)
	{
		scanf("%d %d %d %d",&u,&v,&w,&r);
		if(!r) heap.push({u,v,w});
		else p[find(u)] = find(v);
	}
	
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d %d",&c,&d);
		mi[c] = min(mi[c],d);
		ma = max(c,ma);
	
	}
	
	for(i=ma;i>=1;i--) mi[i] = min(mi[i],mi[i+1]);
	
	while(!heap.empty())
	{
		u = heap.top().u; v = heap.top().v; w = heap.top().w;
		heap.pop();
		
		if(find(u) != find(v))
		{
			ans += mi[w];
			p[find(u)] = find(v);
		}
		
	}
	
	printf("%d\n",ans);
	return 0;
	
}
