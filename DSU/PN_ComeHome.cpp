/*
	Author	: KongCXA
	Language: C++
	Algo	: Disjoint Set Union
*/
#include <bits/stdc++.h>
using namespace std;

int p[300100],che[300100];
int find(int u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]);
}

int main()
{
	int n,m,i,u,v,fu,fv,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++) p[i] = i;
	while(n--)
	{
		k = 0;
		scanf("%d %d",&u,&v);
		fu = find(u); fv = find(v);
		
		if(!che[u])
		{
			che[u] = 1;
			p[fu] = fv;
			k=1;
		}
		
		else if(!che[v])
		{
			che[v] = 1;
			p[fv] = fu;
			k=1;
		}
		
		else if(!che[fu])
		{
			che[fu] = 1;
			p[fu] = fv;
			k=1;
		}
		
		else if(!che[fv])
		{
			che[fv] = 1;
			p[fv] = fu;
			k=1;
		}
		
		if(k)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
