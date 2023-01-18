/*
	Author	: KongCXA
	Language: C++
	Algo	: Hemiltonian(Depth First Search)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[30];
int deg[30],n,ans[310],mark[30][30];
char s[5];

void dfs(int u,int state)
{
	ans[state] = u;
	if(state == n)
	{
		for(int i=0;i<=n;i++) printf("%c ",ans[i]+'A');
		exit(0);
	}
	for(auto x:g[u])
	{
		if(mark[u][x]) continue;
		mark[u][x] = mark[x][u]=1;
		dfs(x,state+1);
		mark[u][x] = mark[x][u]=0;
	}
}

int main()
{
	int i,idx=1e9,st=30,c;
	char u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %s",s);
		g[s[0]-'A'].push_back(s[1]-'A'); deg[s[0]-'A']++;
		g[s[1]-'A'].push_back(s[0]-'A'); deg[s[1]-'A']++;
	}
	
	for(i=0;i<26;i++) sort(g[i].begin(),g[i].end());
	for(i=0;i<26;i++)
	{
		if(deg[i]%2==1)
		{
			st = i;
			break;
		}
		else if(deg[i]>0) idx=min(idx,i);
	}
	if(st==30) st = idx;
	dfs(st,0);
	return 0;
}
