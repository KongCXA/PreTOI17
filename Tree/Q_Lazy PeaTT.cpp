/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming on Tree
*/
#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> mp;

int main()
{
	int n,q,i,num,a,c,l,r;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		mp[num].push_back(i);
	}
	while(q--)
	{
		scanf("%d %d %d",&l,&r,&c);
		a = upper_bound(mp[c].begin(),mp[c].end(),r) - lower_bound(mp[c].begin(),mp[c].end(),l);
		printf("%d\n",a);
	}
	return 0;
}
