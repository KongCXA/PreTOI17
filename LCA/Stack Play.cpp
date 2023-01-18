/*
	Author	: KongCXA
	Language: C++
	Algo	: Lowest Common Ancestor
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> g[300300];
int level[300300],dp[20][300300],pa[300300];

int find(int u)
{
	if(pa[u]==u) return u;
	return pa[u]=find(pa[u]);
}


int main()
{
	int n,i,p,q,j;
	char op;
	scanf("%d",&n);
	dp[0][0]=0;
	level[0]=0;
	for(i=1;i<=n;i++)
	{
		pa[i]=i;
		scanf(" %c %d",&op,&p);
		p=find(p);
		if(op=='a')
		{
			g[i].push_back(p);
			level[i]=level[p]+1;
			
			dp[0][i]=p;
			for(j=1;j<20;j++)
			{
				dp[j][i] = dp[j-1][dp[j-1][i]];
			}	
		}
		if(op=='b')
		{
			p=find(p);
			if(i==1)
			{
				printf("-1\n");
				continue;
			}
			pa[i]=pa[find(dp[0][p])];
			for(j=0;j<20;j++) dp[j][i] = dp[j][dp[0][p]];
			printf("%d\n",find(p));
		}
		if(op=='c')
		{
			scanf("%d",&q);
			q=find(q);
			p=find(p);
			pa[i]=pa[p];
			for(j=0;j<20;j++) dp[j][i] = dp[j][p];
			//q --> i
			if(level[p]>level[q]) swap(p,q);
			for(j=19;j>=0;j--)
			{
				if(level[dp[j][q]]<level[p]) continue;
				q=dp[j][q];
			}
			if(p==q)
			{
				printf("%d\n",level[q]);
				continue;
			}
			for(j=19;j>=0;j--)
			{
				if(dp[j][q]==dp[j][p]) continue;
				q=dp[j][q];
				p=dp[j][p];
			}
			printf("%d\n",level[dp[0][q]]);
			
		}
	}
	return 0;
}
