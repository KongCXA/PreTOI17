/*
	Author	: KongCXA
	Language: C++
	Algo	: String Matching(KMP)
*/
#include <bits/stdc++.h>
using namespace std;

char a[10000100];
int pi[10000100];
int main()
{
	int n,m,i,j=0,cou=0;
	scanf("%d %s",&n,a+1);
	for(i=n+1;i<=n*2;i++) a[i]=a[i-n];

	for(i=2;i<=n*2;i++)
	{
		while(j>0 && a[j+1]!=a[i]) j = pi[j];
		if(a[j+1]==a[i]) j++;
		pi[i]=j;
		
		if(i>n) if(pi[i]==n) printf("%d ",i-n);
	}
	return 0;
}
