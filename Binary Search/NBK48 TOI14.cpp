/*
	Author	: KongCXA
	Language: C++
	Algo	: Binary Search + Quick Sum
*/
#include <bits/stdc++.h>
using namespace std;
int a[100100];

int main()
{
	int n,q,i,num;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i] = a[i]+a[i-1];
	}
	for(i=n;i>=1;i--) a[i-1] = min(a[i],a[i-1]);
	
	while(q--)
	{
		scanf("%d",&num);
		printf("%d\n",upper_bound(a+1,a+1+n,num)-a-1);
	}
	return 0;
}
