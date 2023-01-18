/*
	Author	: KongCXA
	Language: C++
	Algo	: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int i2,j2,state;
};
queue< A > bfs;

int di[4]={0,0,1,-1},dj[4]={1,-1,0,0};
int dii[8]={0,1,1,1,0,-1,-1,-1},djj[8]={1,1,0,-1,-1,-1,0,1};
int r,c,dis[310][310],mark[310][310][4];
char las[310][310][4];
char a[310][310];
char ti[4] = {'|','/','-','\\'};

int check(char c)
{
	if(c=='-') return 2;
	if(c=='\\')return 3;
	if(c=='|') return 0;
	if(c=='/') return 1;
}

void add(int st,int ii,int jj,int lay)
{
	if(ii<0||jj<0||ii>=r||jj>=c) return;
	if(las[ii][jj][lay]=='-'||las[ii][jj][lay]=='\\'||las[ii][jj][lay]=='|'||las[ii][jj][lay]=='/') return;
	if(las[ii][jj][lay]=='S'||las[ii][jj][lay]=='E'||las[ii][jj][lay]=='#') return;
	las[ii][jj][lay] = '*';
	add(st,ii+dii[st-1],jj+djj[st-1],lay);
}

void gen(int ii,int jj,int lay)
{
	
	if(las[ii][jj][lay] == '-')
	{
		if(las[ii][jj+1][lay] != '#') add(1,ii,jj+1,lay);
		if(las[ii][jj-1][lay] != '#') add(5,ii,jj-1,lay);
	}
	if(las[ii][jj][lay] == '\\')
	{
		if(las[ii-1][jj-1][lay] != '#') add(6,ii-1,jj-1,lay);
		if(las[ii+1][jj+1][lay] != '#') add(2,ii+1,jj+1,lay);
	}
	if(las[ii][jj][lay] == '|')
	{
		if(las[ii+1][jj][lay] != '#') add(3,ii+1,jj,lay);
		if(las[ii-1][jj][lay] != '#') add(7,ii-1,jj,lay);
	}
	if(las[ii][jj][lay] == '/')
	{
		if(las[ii+1][jj-1][lay] != '#') add(4,ii+1,jj-1,lay);
		if(las[ii-1][jj+1][lay] != '#') add(8,ii-1,jj+1,lay);
	}
}

int main()
{
	
	int q,i,j,si,sj,ei,ej,ii,jj,k,tem,s,che,ss;
	scanf("%d",&q);
	while(q--)
	{
		memset(mark,-1,sizeof mark);
		che = 0;
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++)
		{	
			scanf(" %s",a[i]);
			for(j=0;j<c;j++)
			{ 
			
				las[i][j][0] = las[i][j][1] = las[i][j][2] = las[i][j][3] = a[i][j];
				if(a[i][j]=='S') si=i,sj=j;
				if(a[i][j]=='E') ei=i,ej=j;
				if(a[i][j]=='\\'||a[i][j]=='/'||a[i][j]=='-'||a[i][j]=='|')
				{
					for(k=0;k<4;k++)
					{
						tem = check(a[i][j]);
						las[i][j][k] = ti[(tem+k)%4];
					}
				}
			}
		}
		
		for(k=0;k<4;k++)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{ 
					if(las[i][j][k]=='-'||las[i][j][k]=='\\'||las[i][j][k]=='|'||las[i][j][k]=='/') gen(i,j,k);
				}
			}
		}
		
		bfs.push({si,sj,0});
		mark[si][sj][0] = 0;
		while(!bfs.empty())
		{
			i = bfs.front().i2 ; j = bfs.front().j2 ; s = bfs.front().state;
			bfs.pop();
			
			if(i==ei&&j==ej)
			{
				che = 1;
				printf("%d\n",mark[i][j][s]);
				break;
			}
			
			for(k=0;k<4;k++)
			{
				ii = i+di[k] ; jj = j+dj[k] ; ss = (s+1)%4;
				if(ii<0||ii>=r||jj<0||jj>=c) continue;
				if(mark[ii][jj][ss]!=-1) continue;
				if(las[ii][jj][ss]=='.'||las[ii][jj][ss]=='S'||las[ii][jj][ss]=='E')
				{
				
				mark[ii][jj][ss] = mark[i][j][s%4]+1;
				dis[ii][jj] = dis[i][j]+1;
				bfs.push({ii,jj,ss});
				
				}
			}
		}
		
		if(!che) printf("-1\n");
		while(!bfs.empty()) bfs.pop();
		memset(mark,-1,sizeof mark);
		memset(dis,0,sizeof dis);
		memset(las,0,sizeof las);
	}
	return 0;
}


