/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

int di[4]={0,0,1,-1},dj[4]={1,-1,0,0},a[35][35],mark[35][35];

struct A{
	
	int i,j,w;
};

queue< A > bfs;
int main()
{
	int q,r,c,t,si,ei,ej,sj,i,j,jj,ii,k,w;
	scanf("%d",&q);
	while(q--)
	{
		int ans = 1e9;
		memset(mark,0,sizeof mark);
		scanf("%d %d %d",&r,&c,&t);
		for(i=1;i<=r;i++) for(j=1;j<=c;j++) scanf(" %c",&a[i][j]);

		scanf("%d %d %d %d",&si,&sj,&ei,&ej);
		
		bfs.push({si,sj,0});
		
		while(!bfs.empty())
		{
			i=bfs.front().i ; j=bfs.front().j ;  w=bfs.front().w; 
			bfs.pop();
			if(i==ei && j==ej) ans = min(ans,w);
			for(k=0;k<4;k++)
			{
				ii = i+di[k] ; jj = j+dj[k];
				if(ii<1||ii>r||jj<1||jj>c) continue;
				if(mark[ii][jj]==1||a[ii][jj]=='#') continue;
				mark[ii][jj] = 1;
				bfs.push({ii,jj,w+1});
			}
		}
		
		int left = t - ans,cou=0;
		for(i=1;i<=r;i++) for(j=1;j<=c;j++) if(mark[i][j]) cou++;
		if(t<ans)
		{
			printf("-1\n");
			continue;
		}
		else if((cou-(ans+1))*2<=left) printf("%d\n",cou);
		else printf("%d\n",ans+1+(left/2));
		
	}
	return 0;
}
