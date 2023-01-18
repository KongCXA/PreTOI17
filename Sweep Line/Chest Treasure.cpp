/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	long long idx,val;
	bool operator <(const A& o)const{
		if(idx==o.idx) return val<o.val;
		return idx<o.idx;
	}
};
vector<A> v;
long long fac[10];

void fact(int n)
{
	int ch=0;
	if(n<0) ch=1,n*=-1;
	while(n>1)
	{
		for(int i=2;i<=7;i++)
		{
			if(n%i==0)
			{
				if(ch) fac[i]--;
				else fac[i]++;
				n/=i;
				break;
			}
		}
	}
}

int main()
{
	long long n,m,x,s,e,i,factor,temp,ma=0,idx;
	scanf("%lld %lld",&m,&n);
	while(m--)
	{
		scanf("%lld %lld %lld",&x,&s,&e);
		v.push_back({s,x});
		v.push_back({e+1,-x});
	}
	fac[2]=fac[3]=fac[5]=fac[7]=1;
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		if(v[i].val > 0)
		{
			fact(v[i].val);
			temp = v[i].idx;
		}
		else
		{
			factor = fac[2]*fac[3]*fac[5]*fac[7];
			if(factor > ma) ma=factor,idx = v[i].idx - temp;
			else if(factor==ma) idx+=v[i].idx-temp;
			fact(v[i].val);
		}	
	}
	printf("%lld %lld\n",ma,idx);
	return 0;
}
