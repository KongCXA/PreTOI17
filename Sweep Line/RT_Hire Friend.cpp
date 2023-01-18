/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
map<int,long long> mp;

int main()
{
	long long n,s,e,temp,sum=0,ans=0;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld %lld",&s,&e);
		mp[s]++; mp[e+1]--;
	}
	
	for(auto x:mp)
	{
		if(sum>1) ans+= (sum-1) * (x.first-temp);
		sum += x.second;
		temp=x.first;
		
	} 
	printf("%lld\n",ans);
	return 0;
}
