/*
	Author	: KongCXA
	Language: C++
	Algo	: Depth First Search
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int op,u;
};
int mark[100100],mark2[100100],close[100100];
stack<A> st;
vector<int> g[100100],re[100100],ans;

void dfs(int u,int pa)
{
	mark[u]=1;
	for(auto x:g[u])
	{
		if(mark[x] || x==pa || close[x]) continue;
		dfs(x,u);
	}
}

void dfs2(int u,int pa)
{
	mark2[u]=1;
	for(auto x:re[u])
	{
		if(mark2[x] || x==pa || close[x]) continue;
		dfs2(x,u);
	}
}

int main()
{
	int n,m,q,i,u,v,op;
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		re[v].push_back(u);
	}
		
	while(q--)
	{
		scanf("%d %d",&op,&u);
		if(op==1) close[u]=1;
		st.push({op,u});
	}
	dfs(1,0);
	dfs2(n,0);
	while(!st.empty())
	{
		op = st.top().op; u = st.top().u;
		st.pop();
		if(op==1)
		{
			close[u]=0;
			for(auto x:re[u])
			{
				if(mark[x]) dfs(x,0);
			}
			for(auto x:g[u])
			{
				if(mark2[x]) dfs2(x,0);
			}
		}
		else ans.push_back(mark[u]&mark2[u]);
	}
	for(i=ans.size()-1;i>=0;i--) printf("%d\n",ans[i]);
	return 0;
}
