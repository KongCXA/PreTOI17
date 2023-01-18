/*
	Author	: KongCXA
	Language: C++
	Algo	: Topological
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[50050],ans;
priority_queue<int,vector<int>,greater<int>> heap;
int deg[50050];

int main()
{
	int q,n,m,i,u,v,idx,ch,tmp;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&v,&u);
			g[u].push_back(v); deg[v]++;
		}
		
		for(i=1,ch=0;i<=n;i++) if(!deg[i]) heap.push(i);
		while(!heap.empty())
		{
			idx = heap.top();
			if(heap.size()>=2) tmp=ans.size(),ch=1;
			heap.pop();
			ans.push_back(idx);
			for(auto x:g[idx])
			{
				deg[x]--;
				if(!deg[x]) heap.push(x);
			}
		}
		if(ans.size()!=n) printf("Never");
		else
		{
			if(ch) printf("Different "),swap(ans[tmp],ans[tmp+1]);
			else printf("Same ");
			for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
		}
		printf("\n");
		ans.clear();
		for(i=1;i<=n;i++) g[i].clear(),deg[i]=0;
		
	}
	return 0;
}
