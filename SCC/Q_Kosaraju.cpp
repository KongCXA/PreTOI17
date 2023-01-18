/*
	Author	: KongCXA
	Language: C++
	Algo	: Strongly Connected Components
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100],gt[100100];
int now,mark[100100],comp[100100];
stack<int> st;
void dfs(int u)
{
	mark[u]=1;
	for(auto x:g[u])
	{
		if(!mark[x]) dfs(x);
	}
	st.push(u);
}
void dfs2(int u)
{
	comp[u]=now;
	mark[u]=2;
	for(auto x:gt[u])
	{
		if(mark[x]!=2) dfs2(x);
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
			gt[v].push_back(i);
		}
	}
	for(i=1;i<=n;i++) if(!mark[i]) dfs(i);
	while(!st.empty())
	{
		if(mark[st.top()]==2)
		{
			st.pop();
			continue;
		}
		dfs2(st.top());
		st.pop();
		now++;
	}

	while(k--)
	{
		scanf("%d %d",&u,&v);
		if(comp[u]==comp[v]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
