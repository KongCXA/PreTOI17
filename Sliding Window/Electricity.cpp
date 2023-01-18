/*
	Author	: KongCXA
	Language: C++
	Algo	: Sliding Window
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int val,idx;
};
int a[500500];
deque<A> mid;

int main()
{
	int n,k,i,ans,st;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	mid.push_back({a[1],1});
	for(i=2;i<=n;i++)
	{
		while(!mid.empty()&& mid.front().idx<i-k) mid.pop_front();
		while(!mid.empty()&& mid.front().val+a[i] <= mid.back().val ) mid.pop_back();
		mid.push_back({mid.front().val+a[i],i}); 
	}

	printf("%d\n",mid.back().val);
	return 0;
}
