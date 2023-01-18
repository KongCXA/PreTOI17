/*
	Author	: KongCXA
	Language: C++
	Algo	: Priority Queue
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int x,y;
	bool operator < (const A& o)const{
	if(x==o.x) return y<o.y;
	return x>o.x;
	}
};
priority_queue< A > h;
int a[500500];

int main()
{
	int n,k,kong,i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=1;i<=k;i++) h.push({a[0]+a[i],i});
	for(i=k+1;i<n;i++)
	{
		while(i-h.top().y>k) h.pop();
		kong = h.top().x;
		if(i==n-1)
		{
			printf("%d\n",a[n-1]+kong);
			return 0;
		}
		h.push({a[i]+kong,i});
	}
	return 0;
}
