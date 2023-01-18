/*
	Author	: KongCXA
	Language: C++
	Algo	: Binary Search
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long q,s,p,l,c,r,b,mid;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld",&s,&p);
		l=c=0; r=s/2;
		mid = (l+r)/2;
		while(l<=r)
		{
			mid = (l+r)/2;
			b = s-mid;
			
			if(mid*b > p || mid*b/b!=mid) r= mid-1;//check floating point
			else if(mid*b < p) l = mid+1;
			else
			{
				c = 1;
				break;
			}
		}
		if(!c) printf("No answer");
		else printf("%lld %lld\n",mid,b);
	}
	return 0;
}
