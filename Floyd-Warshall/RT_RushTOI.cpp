/*
	Author	: KongCXA
	Language: C++
	Algo	: Floyd-Warshall
*/
#include <bits/stdc++.h>
using namespace std;

int kong[350][350];
int main()
{
	int n,m,s,e,w,i,j,k;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) kong[i][j] = 1e9;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&s,&e,&w);
		kong[s][e] = min(kong[s][e],w);
	}
	
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				kong[i][j] = min(kong[i][j],kong[i][k]+kong[k][j]); 
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) 
		{
			if (kong[i][j]==1e9) printf("0 ");
			else printf("%d ",kong[i][j]);
		}
		printf("\n");
	}
	return 0;
}
