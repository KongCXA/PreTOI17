/*
	Author	: KongCXA
	Language: C++
	Algo	: Greedy
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
	int idx,val;
	bool operator <(const A& o)const{
		return val < o.val;
	}
};
A a[100100];
int mark[100100];

int main()
{
	int n,m,i,j,ans,num,cnt;
	scanf("%d %d",&n,&m);
	cnt = n;
	for(i=1;i<=n;i++) scanf("%d",&a[i].val),a[i].idx=i;
	sort(a+1,a+1+n);
	
	for(i=1;i<=m;i++)
	{
		scanf("%d",&num);
		ans = 0;
		for(j=cnt;j>=1;j--)
		{
			if(a[j].val<=num)
			{
				cnt = j;
				break;
			}
			if(mark[a[j].idx]&&mark[a[j].idx]!=i) continue;
			if(mark[a[j].idx]!=i) ans++,mark[a[j].idx]=i;
			if(a[j].idx+1<=n&&!mark[a[j].idx+1]) ans++,mark[a[j].idx+1]=i;
			if(a[j].idx-1>=1&&!mark[a[j].idx-1]) ans++,mark[a[j].idx-1]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
