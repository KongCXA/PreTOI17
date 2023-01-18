/*
	Author	: KongCXA
	Language: C++
	Algo	: Binary Search
*/
#include <bits/stdc++.h>
using namespace std;
long long a[1010];

int main()
{
	long long q,i,n,k,l,r,mid,bush,mak,temp;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		sort(a,a+n);
		l=0; r=2e9;
		while(l<r)
		{
			mid = (l+r)/2;
			bush = (mid+1)*(mid+1);
			for(i=1;i<n;i++)
			{
				if(a[i]==a[i-1]) continue;
				temp = a[i]-a[i-1];
				
				if((temp)%2==1)
				{
					if(temp/2<=mid) mak = (mid-(temp/2))*(mid-(temp/2)+1);
					else mak = 0;
				}
				if((temp)%2==0)
				{
					if(temp/2-1<=mid) mak = (mid-(temp/2-1))*(mid-(temp/2-1)+1) - (mid-(temp/2-1));
					else mak = 0;
				}
				bush += (mid+1)*(mid+1)-mak;	
			}
			if(bush>=k) r = mid;
			else if(bush<k) l = mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
