/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x&-(x))
const int FEN = 300300;
int fenwick[FEN];
map<int,int> mp;
vector<pair<int,int>> vec;


int main()
{
	int n,i,l,r,cou,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		vec.push_back({l,r});
		mp[r]=1;
	}
	cou=1;
	for(auto x:mp) mp[x.first] = cou++;
	for(auto x:vec)
	{
		if(x.first==1) for(i=mp[x.second];i<=FEN;i+=LSB(i)) fenwick[i]+=1;
		if(x.first==2)
		{
			for(i=mp[x.second],ans=0;i>=1;i-=LSB(i)) ans+=fenwick[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
