/*
	Author	: KongCXA
	Language: C++
	Algo	: Minimum Spanning Tree
*/
//prim O(15000*15000) tun
#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[15100];
int ans[15100],dp[15100],mark[15100];


int main()
{
	int n,k,i,j,now,cost,sum=0,idx,mi;

	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].first,&a[i].second);
		ans[i] = dp[i] = 1e9;
		mark[i] = i;
	}
	
	idx = dp[0] = 0;
	for(i=0;i<n;i++)
	{
		now = mark[idx];
		ans[i] = dp[now];
		swap(mark[idx],mark[n-1-i]);
		mi = 1e9;
		for(j=0;j<n-1-i;j++)
		{
			cost = abs(a[now].first-a[mark[j]].first) + abs(a[now].second-a[mark[j]].second);
			if(cost<dp[mark[j]]) dp[mark[j]] = cost;
			if(mi > dp[mark[j]])
			{
				mi = dp[mark[j]];
				idx = j;
			}
		}
	}
	sort(ans+1,ans+n);
	for(i=1;i<=n-k;i++) sum += ans[i];
	printf("%d\n",sum);
	
	return 0;
}
