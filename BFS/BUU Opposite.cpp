/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int i,j,ii,jj;
};

queue< pair<int,int> > que;
queue< A > bfs;
char a[35][35];
int di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
int dis[35][35][35][35],dis2[35][35][35][35];


int main()
{
	int q,r,c,i,j,ei,ej,ni,nj,nii,njj,is,ie,js,je,si,sj,k,ii,jj,mi,miwalk;
	scanf("%d",&q);
	while(q--)
	{
		memset(dis,-1,sizeof dis);
		memset(dis2,-1,sizeof dis2);
		scanf("%d %d",&r,&c);
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				scanf(" %c",&a[i][j]);
				if(a[i][j]=='A') si=i,sj=j;
				if(a[i][j]=='B') ei=i,ej=j;
			}
		}
		
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				dis[i][j][i][j] = 0;
				que.push({i,j});
				while(!que.empty())
				{
					ni=que.front().first; nj=que.front().second;
					que.pop();
					for(k=0;k<4;k++)
					{
						ii = ni+di[k]; jj = nj+dj[k];
						if(ii<1||jj<1||ii>r||jj>c) continue;
						if(dis[i][j][ii][jj] != -1 ||a[ii][jj] == '#') continue;
						dis[i][j][ii][jj] = dis[i][j][ni][nj]+1;
						que.push({ii,jj});
					}
				}
			}
		}
		
		bfs.push({si,sj,ei,ej});
		dis2[si][sj][ei][ej] = 0;
		mi = 1e9, miwalk = 1e9;
		while(!bfs.empty())
		{
			ni = bfs.front().i; nj = bfs.front().j;
			nii = bfs.front().ii; njj = bfs.front().jj;
			if(mi > dis[ni][nj][nii][njj]) mi = dis[ni][nj][nii][njj],miwalk = dis2[ni][nj][nii][njj];
			else if(mi == dis[ni][nj][nii][njj]) miwalk = min(miwalk,dis2[ni][nj][nii][njj]);
			bfs.pop();
			for(k=0;k<4;k++)
			{
				is = ni+di[k]; js = nj+dj[k];
				ie = nii - di[k]; je = njj - dj[k];
				if(is<1||js<1||is>r||js>c||a[is][js]=='#') is = ni,js = nj;
				if(ie<1||je<1||ie>r||je>c||a[ie][je]=='#') ie = nii,je = njj;
				if(dis2[is][js][ie][je]!=-1) continue;
				dis2[is][js][ie][je] = dis2[ni][nj][nii][njj]+1;
				bfs.push({is,js,ie,je});
			}
		}
		if(dis[si][sj][ei][ej]==-1) printf("-1 0\n");
		else printf("%d %d\n",mi,miwalk);
	}
	return 0;
}
