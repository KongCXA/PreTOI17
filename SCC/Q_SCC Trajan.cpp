/*
	Author	: KongCXA
	Language: C++
	Algo	: Strongly Connected Components
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int cou=1,coucomp=1,mark[100100],comp[100100],idx[100100],low[100100],onstack[100100];
stack<int> st;

void dfs(int u)
{
	idx[u]=low[u]=cou++;
	onstack[u]=1; st.push(u);
	mark[u]=1;
	for(auto x:g[u])
	{
		if(!mark[x])
		{
			dfs(x);
			low[u] = min(low[u],low[x]);
		}
		else if(onstack[x])
		{
			low[u] = min(low[u],idx[x]);
		}
		
	}
	if(idx[u]==low[u])
	{
		while(!st.empty() && st.top()!=u)
		{
			onstack[st.top()]=0;
			comp[st.top()]=coucomp;
			st.pop();
		}
		comp[u]=coucomp++;
		onstack[u]=0;
		st.pop();
	}
}

int main()
{
	int n,m,k,i,x,v,u;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&v);
			g[i].push_back(v);
		}
	}
	for(i=1;i<=n;i++) if(!mark[i]) dfs(i);
	while(k--)
	{
		scanf("%d %d",&u,&v);
		if(comp[u]==comp[v]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
