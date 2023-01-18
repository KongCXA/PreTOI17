/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & -(x))
const int N=2020;
int fenwick[2020][2020];


int main()
{
	int op,n,x,y,c,xx,yy,i,j,ans;
	
	
	while(1)
	{
		scanf("%d",&op);
		if(op==0) scanf("%d",&n);
		if(op==1)
		{
			scanf("%d %d %d",&x,&y,&c);
			for(i=x+1;i<=N;i+=LSB(i)) for(j=y+1;j<=N;j+=LSB(j)) fenwick[i][j] += c;
		}
		if(op==2)
		{
			scanf("%d %d %d %d",&x,&y,&xx,&yy);
			for(i=xx+1,ans=0;i>0;i-=LSB(i)) for(j=yy+1;j>0;j-=LSB(j)) ans += fenwick[i][j];
			for(i=x;i>0;i-=LSB(i)) for(j=yy+1;j>0;j-=LSB(j)) ans -= fenwick[i][j];
			for(i=xx+1;i>0;i-=LSB(i)) for(j=y;j>0;j-=LSB(j)) ans -= fenwick[i][j];
			for(i=x;i>0;i-=LSB(i)) for(j=y;j>0;j-=LSB(j)) ans += fenwick[i][j];
			printf("%d\n",ans);
		}
		if(op==3) break;
	}
	return 0;
}
