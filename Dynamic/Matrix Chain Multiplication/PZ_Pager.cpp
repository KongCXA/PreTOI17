/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

long long r[405],l[405],c[405],dp[405][405],cost[405][405];
unordered_map<long long , long long> mp;
vector<long long> g;

long long play(long long l,long long r)
{
	if(dp[l][r] != -1) return dp[l][r];
	if(l+1==r) return dp[l][r] = cost[l][r];
	long long mx = 0;
	
	for(long long k=l+1;k<=r-1;k++)
	{
		mx = max(mx,play(l,k)+play(k,r));
	}
	return dp[l][r] = mx+cost[l][r];
}

int main()
{
	long long n,i,q;
	scanf("%lld",&q);
	while(q--)
	{
		memset(dp,-1,sizeof dp);
		memset(cost,0,sizeof cost);
		
		scanf("%lld",&n);
		for(i=0;i<n;i++) 
		{
		
			scanf("%lld %lld %lld",&l[i],&r[i],&c[i]);
			if(mp[l[i]] != 1) 
			{
				mp[l[i]] = 1;
				g.push_back(l[i]);
			}
			if(mp[r[i]] != 1) 
			{
				mp[r[i]] = 1;
				g.push_back(r[i]);
			}
		}
		sort(g.begin(),g.end());
		long long cnt = 0;
		for(auto x:g) mp[x] = cnt++;
		for(i=0;i<n;i++) cost[mp[l[i]]][mp[r[i]]] = c[i];
		
		
		printf("%lld\n",play(0,cnt-1));
		mp.clear();
		g.clear();
	}
	return 0;
}

