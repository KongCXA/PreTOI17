/*
	Author	: KongCXA
	Language: C++
	Algo	: Sliding Window
*/
#include <bits/stdc++.h>
using namespace std;

long long a[1000100],n;

long long play(long long q)
{
	long long i,cou=0,last=0;
	deque<long long> mid,mad;
	for(i=1;i<=n;i++)
	{
		while(!mad.empty()&&a[i]>a[mad.back()]) mad.pop_back();
		mad.push_back(i);
		while(!mid.empty()&&a[i]<a[mid.back()]) mid.pop_back();
		mid.push_back(i);
		while(!mid.empty() && !mad.empty()&&a[mad.front()]-a[mid.front()]>q)
		{
			if(mad.front() < mid.front())
			{
				last = mad.front();
				mad.pop_front();
			}
			else
			{
				last = mid.front();
				mid.pop_front();
			}
		}
		cou += i-last;
	}
	
	return cou;
}

int main()
{
	long long m,c,i,p,q;
	scanf("%lld %lld %lld",&n,&p,&q);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	printf("%lld\n",play(q)-play(p-1));
	return 0;
}
