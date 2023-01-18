/*
	Author	: KongCXA
	Language: C++
	Algo	: STL
*/
#include <bits/stdc++.h>
using namespace std;

map<set<pair<int,int>>,int> mp;
set<pair<int,int>> s;

int main()
{
	int t,q,n,x,y;
	scanf("%d %d",&t,&q);
	while(t--)
	{
		scanf("%d",&n);n--;
		while(n--)
		{
			scanf("%d %d",&x,&y);
			if(x>y) swap(x,y);
			s.insert({x,y});
		}
		mp[s]++;
		s.clear();
	}
	while(q--)
	{
		scanf("%d",&n);n--;
		while(n--)
		{
			scanf("%d %d",&x,&y);
			if(x>y) swap(x,y);
			s.insert({x,y});
		}
		printf("%d\n",mp[s]);
		s.clear();
	}
	return 0;
}
