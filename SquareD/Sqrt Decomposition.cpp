/*
	Author	: KongCXA
	Language: C++
	Algo	: Sqrt Decomposition
*/
#include <bits/stdc++.h>
using namespace std;

int a[100100],group[320];
int main()
{
	int n,q,sq,id,x,i,ans;
	char op;
	scanf("%d %d",&n,&q);
	sq = sqrt(n);
	while(q--)
	{
		scanf(" %c %d %d",&op,&id,&x);
		id--;
		if(op=='U')
		{
			a[id]=x;
			group[id/sq]=-1e9;
			for(i=(id/sq)*sq;i<min((id/sq)*sq+sq,n);i++)
			{
				group[id/sq] = max(group[id/sq],a[i]);
			}
		}
		if(op=='P')
		{
			x--;
			for(i=id,ans=-1e9;i<=x;)
			{
				if(!(i%sq) && i+sq-1<=x)
				{
					ans = max(ans,group[i/sq]);
					i+=sq;
				}
				else
				{
					ans = max(ans,a[i]);
					i+=1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
