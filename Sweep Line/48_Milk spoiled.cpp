/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp,mp3;
struct A{
	int idx,val;
	bool operator <(const A& o)const{
		if(idx==o.idx) return val<o.val;
		return idx<o.idx;
	}
};
vector<A> v;

int main()
{
	int q,n,x,y,z,a,s,e,sum,ans,cold,i;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d %d",&n,&x,&y,&z);
		
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&s,&e);
			v.push_back({s,1});
			v.push_back({e+1,-1});
		}
		sort(v.begin(),v.end());
		
		for(i=0,ans=0,sum=0,cold=n;i<v.size();i++)
		{	
			if(v[i].val==1) cold--;
			sum += v[i].val;
			ans = max(ans, cold*x + sum*y + (n-cold-sum)*z);
		}

		ans=max({ans,n*x,n*z});
		printf("%d\n",ans);
		v.clear();
	}
	return 0;
}
