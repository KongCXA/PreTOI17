/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;
char a[1101][1101];
int dis[1101][1101],di[5]={0,0,1,-1},dj[5]={1,-1,0,0};
queue<pair<int,int>> bfs;


int main()
{
	int q,r,c,i,j,d,ans,ii,jj,k;
	scanf("%d",&q);
	while(q--)
	{
		memset(dis,-1,sizeof(dis));
		d=-1,ans=0;
		scanf("%d %d",&r,&c);
		
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				scanf(" %c",&a[i][j]);
				if(a[i][j]=='E') bfs.push({i,j}),dis[i][j]=0;
			}
		}
		
		while(!bfs.empty())
		{
			i=bfs.front().first; j=bfs.front().second; bfs.pop();
			for(k=0;k<4;k++)
			{
				ii=i+di[k],jj=j+dj[k];
				if(ii>0&&ii<=r&&jj>0&&jj<=c&&a[ii][jj]!='#'&&dis[ii][jj]==-1) 
				{
				dis[ii][jj]=dis[i][j]+1;
				if(a[ii][jj]=='S') d=dis[ii][jj];
				bfs.push({ii,jj});
				}
			}
		}
		for(i=1;i<=r;i++) for(j=1;j<=c;j++) if(dis[i][j]!=-1&&dis[i][j]<=d&&isdigit(a[i][j])) ans+=a[i][j]-'0';
		if(d==-1) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}

