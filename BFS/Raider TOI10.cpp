/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int i,j,w;
};

int a[110][110],di[2][6]={{0,0,-1,-1,1,1},{0,0,-1,-1,1,1}},dj[2][6]={{1,-1,0,-1,0,-1},{1,-1,0,1,0,1}},mark[110][110];
queue<A> bfs;

int main()
{
	int r,c,i,j,w,ii,jj,ww,k;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++) for(j=1;j<=c;j++) scanf("%d",&a[i][j]);

	
	if(a[r/2][1]!=0 )bfs.push({r/2,1,1});
	if(a[r/2+1][1]!=0) bfs.push({r/2+1,1,1});
	if(a[r/2+2][1]!=0) bfs.push({r/2+2,1,1});
	while(!bfs.empty())
	{
		i=bfs.front().i; j=bfs.front().j; w=bfs.front().w;
		bfs.pop();
		if(j==c && i==r/2+1)
		{
			printf("%d\n",w);
			break;
		}
		for(k=0;k<6;k++)
		{
			ii=i+di[i%2][k], jj=j+dj[i%2][k], ww=w+1;
			if(ii<1||jj<1||ii>r||jj>c) continue;
			if(a[ii][jj]==0 || ww%a[ii][jj]!=0 || mark[ii][jj]==ww) continue;
			mark[ii][jj]=ww;
			bfs.push({ii,jj,ww});
			
		}
	}
	return 0;
}
