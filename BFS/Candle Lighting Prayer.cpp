/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

char a[2020][2020];
int mark[2020][2020],di[8]={1,1,1,0,0,-1,-1,-1},dj[8]={-1,0,1,1,-1,-1,0,1};
queue< pair<int,int> > bfs;

int main()
{
	int m,n,i,j,kong=0,ii,jj,k,i2,j2;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&a[i][j]);
			if(a[i][j]=='0') mark[i][j] = 1;
		}
	}
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!mark[i][j])
			{
				kong++;
				bfs.push({i,j});
				while(!bfs.empty())
				{
					i2 = bfs.front().first ; j2 = bfs.front().second;
					bfs.pop();
					for(k=0;k<8;k++)
					{
						ii = i2+di[k] ; jj = j2+dj[k];
						if(ii<1||jj<1||ii>m||jj>n) continue;
						if(mark[ii][jj]) continue;
						mark[ii][jj] = 1;
						bfs.push({ii,jj});
					}
					
				}
				
			}
		}
	}
	
	printf("%d\n",kong);
	return 0;
}
