/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
#define LSB(x) (x & -(x))
const int FEN = 1e6;
struct A{
	int idx,high,val;
	bool operator <(const A& o)const{
		return idx<o.idx;
	}
};
vector<A> v;
int a[1000100];
int fenwick[FEN+10];

int point(int n)
{
	int j,temp=0;
	for(j=n;j>0;j-=LSB(j)) temp += fenwick[j];
    return temp;
}


int lbs(int n)
{
	int l=1,r=1000000,mid;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(point(mid)<=n) r=mid;
		else l=mid+1;
	}
	return l;
}



int ubs(int n)
{
	int l=1,r=1000000,mid;
	while(l!=r)
	{
		mid=(l+r+1)/2;
		if(point(mid)>=n) l=mid;
		else r=mid-1;
	}
	
	return l;
}

int findsum(int n)
{
	int l = lbs(n), r = ubs(n);
	if(point(l)==n) return r-l+1;
	else return 0;
}

int main()
{
	int n,t,s,h,w,o,i,j,cou=0,temp=0,sum;
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&s,&h,&w,&o);
		v.push_back({s  ,h, o});
		v.push_back({s+w,h,-o});
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		if(i) cou += findsum(t)*(v[i].idx-v[i-1].idx);
		for(j=1           ;j<=FEN ;j+=LSB(j)) fenwick[j] += v[i].val;
		for(j=v[i].high+1 ;j<=FEN ;j+=LSB(j)) fenwick[j] -= v[i].val;	
	}
	printf("%d\n",cou);
	return 0;
}
