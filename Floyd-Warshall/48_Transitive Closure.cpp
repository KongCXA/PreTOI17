/*
	Author	: KongCXA
	Language: C++
	Algo	: Floyd-Warshall
*/
#include <bits/stdc++.h>
using namespace std;

int kong[550][550];
int main()
{
	int n,m,s,e,w,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&kong[i][j]);
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(kong[i][k]==1 && kong[k][j]==1) kong[i][j] = 1;
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) 
		{
			printf("%d ",kong[i][j]);
		}
		printf("\n");
	}
	return 0;
}
