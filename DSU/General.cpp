/*
	Author	: KongCXA
	Language: C++
	Algo	: Disjoint Set Union
*/
#include <bits/stdc++.h>
using namespace std;

int p[100100],a[100100];

int find(int u)
{
	if(p[u]==u) return u;
	return p[u] = find(p[u]);
}

int main()
{
	int n,m,i,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) p[i] = i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	while(m--)
	{
		scanf("%d %d",&x,&y);
		if(find(x) == find(y)) printf("-1\n");
		else if(a[find(x)] == a[find(y)])
		{
			if(find(x) < find(y))
			{
				a[find(x)] += a[find(y)]/2;
				p[find(y)] = find(x);
				printf("%d\n",find(x));
			}
			else 
			{
				a[find(y)] += a[find(x)]/2;
				p[find(x)] = find(y);
				printf("%d\n",find(y));
			}
		}
		else if(a[find(x)] < a[find(y)])
		{
			a[find(y)] += a[find(x)]/2;
			p[find(x)] = find(y);
			printf("%d\n",find(y));
		}
		else if(a[find(x)] > a[find(y)])
		{
			a[find(x)] += a[find(y)]/2;
			p[find(y)] = find(x);
			printf("%d\n",find(x));
		}
	}
	return 0;
}
