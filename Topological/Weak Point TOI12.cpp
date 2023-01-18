/*
	Author	: KongCXA
	Language: C++
	Algo	: Topological
*/
#include <bits/stdc++.h>
using namespace std;
int in[500500],dp[500500],mark[500500];
vector<int> g[500500];
queue<int> q;

int main() //dp[i] = how many leaves will be lost (check from cycle) if node i is cut 
{
	int n,m,i,u,v,pos=500500,ma=0,idx,cou=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
		in[u]++; in[v]++;
	}
	for(i=1;i<=n;i++) if(in[i]==1) mark[i]=1,q.push(i);
	
	while(!q.empty())
	{
		idx=q.front(); q.pop();
		for(auto x:g[idx])
		{
			if(mark[x]) continue;
			in[x]--;
			dp[x]+=dp[idx]+1;
			if(in[x]==1) mark[x]=1,q.push(x);
		}
	}
	
	if(!mark[m])
	{
		for(i=1;i<=n;i++)
		{
			if(i==m) continue;
			if(dp[i]>ma) ma=dp[i],pos=i;
			if(dp[i]==ma) pos = min(pos,i);
		}
		printf("%d\n%d\n",pos,ma);
	}
	
	else
	{
		for(auto x:g[m])
		{
			if(dp[x]>dp[m]) dp[x]=n-dp[m]-2;
			if(dp[x]>ma) ma=dp[x],pos=x;
			if(dp[x]==ma) pos = min(pos,x);
		}
		printf("%d\n%d\n",pos,ma);
	}
	return 0;
}
