/*
	Author	: KongCXA
	Language: C++
	Algo	: Priority Queue
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int w,v,d,idx;
	bool operator < (const A& o)const{
		return w>o.w;
	}
};


struct B{
	int w,v,d,idx;
	bool operator < (const B& o)const{
		return d>o.d;
	}
};
priority_queue<A> heap;
priority_queue<B> timee;
int mark[200200];

int main()
{
	int n,m,i,op,k,w,v,d,x,c;
	scanf("%d %d",&n,&m);
	for(i=0;i<n+m;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&k);
			if(k==1)
			{
				scanf("%d %d",&w,&v);
				heap.push({w,v,300000,i});
			}
			if(k==2)
			{
				scanf("%d %d %d",&w,&v,&d);
				heap.push({w,v,d,i});
			}
			if(k==3)
			{
				scanf("%d %d %d %d",&w,&v,&d,&x);
				heap.push({w,v,d,i});
				timee.push({x,v,d,i});
			}
		}
		else if(op==2)
		{
			while(!timee.empty() && timee.top().d <= i)
			{
				heap.push({timee.top().w,timee.top().v,300000,timee.top().idx});
				timee.pop();
			}
			c=1;
			while(!heap.empty())
			{
				if(heap.top().d <= i)
				{
					heap.pop();
					continue;
				}
				if(mark[heap.top().idx])
				{
					heap.pop();
					continue;
				}
				printf("%d\n",heap.top().v);
				mark[heap.top().idx] = 1;
				heap.pop();
				c=0;
				break;
			}
			if(c) printf("0\n");
		}
	}
	return 0;
}
