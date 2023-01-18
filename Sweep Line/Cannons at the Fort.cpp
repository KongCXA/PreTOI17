/*
	Author	: KongCXA
	Language: C++
	Algo	: Sweep Line
*/
#include <bits/stdc++.h>
using namespace std;
int a[1000100];

int main()
{
	int n,m,k,l,i,x,low,up,ans,left,right;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while(k--)
	{
		for(i=1,ans=0;i<=m;i++)
		{
			scanf("%d",&x);
			if(i==1) left=x-l,right=x+l;
			if(x-l <= right) right = x+l;
			else
			{
				low = lower_bound(a+1,a+1+n,left)-a;
				up = upper_bound(a+1,a+1+n,right)-a;
				ans += up-low;
				left = x-l; right = x+l;
			}
		}
		low = lower_bound(a+1,a+1+n,left)-a;
		up = upper_bound(a+1,a+1+n,right)-a;
		ans += up-low;
		printf("%d\n",ans);
		
	}
	return 0;
}
