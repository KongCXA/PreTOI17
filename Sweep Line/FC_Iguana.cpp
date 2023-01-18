/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;

int main()
{
	int n,m,s,e,ch,temp=1,ans=0,sum=0;
	char c;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&s,&e);
		mp[s]++; mp[e+1]--;
	}
	
	scanf(" %c",&c);
	if(c=='R') ch=0;
	if(c=='G') ch=1;
	if(c=='B') ch=2;
	mp[n+1] += 0;
	for(auto x:mp)
	{
		ans += (x.first - temp) * ((ch-sum+3)%3);
		sum = (sum + x.second)%3;
		temp=x.first;
	}
	
	printf("%d\n",ans);
	return 0;
}
