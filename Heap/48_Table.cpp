/*
	Author	: KongCXA
	Language: C++
	Algo	: Priority Queue
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int i,j,v,idx;
	bool operator <(const A& o)const{
		return v>o.v;
	}
};

struct B{
	int v,idx;
};

B a[330][50050];
priority_queue<A> h;

int main()
{
	int r,c,m,i,op,x,idx,ch=0,j,ans,cc;
	scanf("%d %d %d",&r,&c,&m); cc = c;
	for(i=1;i<=r;i++) for(j=1;j<=c;j++) h.push({i,j,0,0});
	for(i=1;i<=m;i++)
	{
		ch=0,ans=0;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %d %d",&r,&c,&x);
			a[r][c].v=x;
			a[r][c].idx=i;
			h.push({r,c,x,i});
		}
		if(op==2)
		{
			scanf("%d %d",&r,&x);
			a[r][0].v=x;
			a[r][0].idx=i;
			h.push({r,0,x,i});
		}
		if(op==3)
		{
			scanf("%d %d",&r,&c);
			if(a[r][0].idx<a[r][c].idx) printf("%d\n",a[r][c].v);
			else printf("%d\n",a[r][0].v);
		}
		if(op==4)
		{
			
			while(!h.empty())
			{
				r = h.top().i;
				c = h.top().j;
				x = h.top().v;
				idx = h.top().idx;
				if(c!=0)
				{
					if(a[r][c].idx != idx||a[r][0].idx>a[r][c].idx)
					{
						h.pop();
						continue;
					}
					printf("%d\n",x);
					ans = 1;
					break;
					
				}
				else
				{
					
					if(a[r][0].idx > idx)
					{
						
						h.pop();
						continue;
					}
					for(j=1;j<=cc;j++)
					{
						
						if(a[r][j].idx<a[r][0].idx)
						{
							ch=1;
							break;
						}
					}
					
					if(ch) 
					{
						printf("%d\n",x);
						ans=1; break;
					}
					else h.pop();
				}
			}
			if(!ans) printf("0\n");
		}
	}
	return 0;
}
