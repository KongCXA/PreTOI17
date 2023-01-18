/*
	Author	: KongCXA
	Language: C++
	Algo	: Strongly Connected Components
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[5050],gt[5050],dag[5050];
int now=1,mark[5050],comp[5050],szcomp[5050],cou[5050],in[5050];
stack<int> st;
queue<pair<int,int>> topo;

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
	szcomp[now]++;
	mark[u]=2;
	for(auto x:gt[u])
	{
		if(mark[x]!=2) dfs2(x);
	}
}


int main()
{
	int n,m,k,i,x,v,u,idx,lv,ans;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		u++;v++;
		g[u].push_back(v);
		gt[v].push_back(u);
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
	for(i=1;i<=n;i++)
	{
		for(auto x:g[i])
		{
			if(comp[i]==comp[x]) continue;
			dag[comp[i]].push_back(comp[x]);
			in[comp[x]]++;
		}
	}

	for(i=1;i<=now-1;i++)
	{
		if(in[i]==0) topo.push({i,1});
	}
	k=0;
	while(!topo.empty())
	{
		idx = topo.front().first; lv = topo.front().second;
		topo.pop();
		if(comp[1]==idx) ans = lv;
		cou[lv] += szcomp[idx];
		k = max(k,lv);
		for(auto x:dag[idx])
		{
			in[x]--;
			if(in[x]==0) topo.push({x,lv+1});
		}
		
	}
	
	for(i=1;i<=k;i++) printf("%d ",cou[i]);
	printf("\n%d\n",ans);
	return 0;
}
