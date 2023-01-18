/*
	Author	: KongCXA
	Language: C++
	Algo	: Sliding Window
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int idx;
	long long val;
};
deque<A> deq;
long long a[6000600];
int main()
{
	int i,range=0;
	long long n,w,ans,sum=0,ma=0;
	scanf("%lld %lld",&n,&w);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		while(!deq.empty() && i - deq.front().idx > w) deq.pop_front();
		
		sum+=a[i];
		ans = sum-deq.front().val;
		if(ma < ans) ma = ans,range=i-deq.front().idx;
		if(ma==ans) range=min(i-deq.front().idx,range);
		
		
		while(!deq.empty() && sum <= deq.back().val ) deq.pop_back();
		deq.push_back({i,sum});
	}
	printf("%lld\n%d\n",ma,range);
	return 0;
}
