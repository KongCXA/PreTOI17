/*
	Author	: KongCXA
	Language: C++
	Algo	: Greedy
*/
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> heap;

int main()
{
	int n,k,i,q,c,ma;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1,c=1,ma=0;i<=n;i++)
		{
			scanf("%d",&k);
			heap.push(k);
		}
		while(!heap.empty())
		{
			ma = max(ma,heap.top()+c);
			heap.pop();
			c++;
		}
		printf("%d\n",ma);
	}
	return 0;
}
