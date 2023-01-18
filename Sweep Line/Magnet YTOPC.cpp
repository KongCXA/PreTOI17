/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> b;

int main()
{
	int n,m,q,s,e,i;
	scanf("%d %d %d",&n,&m,&q);
	while(m--)
	{
		scanf("%d %d",&s,&e);
		mp[s]++; mp[s+e]++;	
	}
	for(auto x:mp) if(x.second%2==1) b.push_back(x.first);
	while(q--)
	{
		scanf("%d",&s);
		if(s<b[0]) printf("%d\n",b[0]-1);
		else if(s>=b[b.size()-1]) printf("%d\n",n-b[b.size()-1]+1);
		else
		{
			auto up = lower_bound(b.begin(),b.end(),s)-b.begin();
			if(s!=b[up]) printf("%d\n",b[up]-b[up-1]);
			else printf("%d\n",b[up+1]-b[up]);
		}
	}
	return 0;
}
