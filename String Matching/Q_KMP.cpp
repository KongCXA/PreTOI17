/*
	Author	: KongCXA
	Language: C++
	Algo	: String Matching(KMP)
*/
#include <bits/stdc++.h>
using namespace std;

char a[1000100],b[1000100];
int pi[1000100];
int main()
{
	int n,m,i,j;
	scanf(" %s %s",a+1,b+1);
	n = strlen(a+1), m =strlen(b+1);
	for(i=2;i<=m;i++)
	{
		while(j>0 && b[j+1]!=b[i]) j = pi[j];
		if(b[j+1]==b[i]) j++;
		pi[i]=j;
	}
	
	for(i=1,j=0;i<=n;i++)
	{
		while(j>0 && b[j+1]!=a[i]) j = pi[j];
		if(b[j+1]==a[i]) j++;
		if(j==m)
		{
			printf("Lucky\n");
			return 0;
		}
	}
	printf("Unlucky\n");
	return 0;
}
