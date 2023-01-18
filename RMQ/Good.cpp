/*
	Author	: KongCXA
	Language: C++
	Algo	: Range Minimum Query
*/
#include <bits/stdc++.h>
using namespace std;

int RMQ[20][100100];
int main()
{
	int n,q,i,j,x,y,k;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&RMQ[0][i]);
	}
	
	for(i=1;i<=log2(n);i++)
	{
		for(j=0;j+(1<<i)-1<n;j++)
		{
			RMQ[i][j]=max(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
		}
	}
	while(q--)
	{
		scanf("%d %d",&x,&y);
		k=log2(y-x+1);
		printf("%d\n",max(RMQ[k][x],RMQ[k][y-(1<<k)+1]));
	}
	return 0;
}
