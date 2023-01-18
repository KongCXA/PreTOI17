/*
	Author	: KongCXA
	Language: C++
	Algo	: Binary Search
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,num,ans=0,prev=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		if(num<=ans) continue;
		if(!prev) prev = num;
		else
		{
			if(num==prev) prev = 0;
			else if(num<prev) ans = num;
			else
			{
				ans = max(ans,prev);
				prev = num;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
