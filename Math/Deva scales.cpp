/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;
long long a[20];

int main()
{
	long long n,c=0,i,add=0,cnt=0,m;
	scanf("%lld",&n);
	m = n;
	while(n>1)
	{
		a[c++] = n%3;
		n/=3;
	}
	if(n!=0) a[c++] = n;

	for(i=0;i<=c;i++)
	{
		if(a[i]==3) a[i+1]+=1;
		else if(a[i]==2)
		{
			add += pow(3,i);
			cnt++;	
			a[i+1]+=1;
		}
		else if(a[i]==1) cnt++;
	}
	
	printf("%lld %lld",cnt,m+add);
	return 0;
}
