/*
	Author	: KongCXA
	Language: C++
	Algo	: Hash Table
*/
#include <bits/stdc++.h>
using namespace std;

#define hs 5000011
int ht[hs],keep[2][hs],x[4][1510],y[4][1510];
 
int main()
{
	int i,j,t,n,kk,q,xt,yt,ox,oy;
	scanf("%d %d %d",&xt,&yt,&n);
	for(i=0;i<4;i++) for(j=0;j<n;j++) scanf("%d %d",&x[i][j],&y[i][j]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ox = x[0][i]+x[1][j] , oy = y[0][i]+y[1][j];
			t= ((ox+(3*oy)%hs)%hs+hs)%hs;
			while(ht[t]!=0) t++,t%=hs;
		
		ht[t]=(1500*i)+j+1;
		keep[0][t]=ox,keep[1][t]=oy;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ox=xt-(x[2][i]+x[3][j]),oy=yt - (y[2][i]+y[3][j]);
			t= ((ox+(3*oy)%hs)%hs+hs)%hs;
			while(ht[t]!=0)
			{
				if(keep[0][t]==ox&&keep[1][t]==oy)
				{
					kk=ht[t]-1;
					printf("%d %d\n",x[0][kk/1500],y[0][kk/1500]);
					printf("%d %d\n",x[1][kk%1500],y[1][kk%1500]);
					printf("%d %d\n",x[2][i],y[2][i]);
					printf("%d %d\n",x[3][j],y[3][j]);
					return 0;
				}
				t++;t%=hs;
				
			}
		}
	}
	return 0;
}
