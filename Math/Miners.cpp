/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;

char a[100100],b[100100];
char s[100100];
int playa(int n,int now)
{
	if(n==0) return 1;
	if(n==1)
	{
		if(s[now]!=a[n-1]) return 2;
		else return 1;
	}
	if(n>=2)
	{
		if(s[now]!=a[n-1] && s[now]!=a[n-2] && a[n-1]!=a[n-2]) return 3;
		else if(s[now]==a[n-1] && s[now]==a[n-2]) return 1;
		else return 2;
	}
}

int playb(int n,int now)
{
	if(n==0) return 1;
	if(n==1)
	{
		if(s[now]!=b[n-1]) return 2;
		else return 1;
	}
	if(n>=2)
	{
		if(s[now]!=b[n-1] && s[now]!=b[n-2] && b[n-1]!=b[n-2]) return 3;
		else if(s[now]==b[n-1] && s[now]==b[n-2]) return 1;
		else return 2;
	}
}

int main()
{
	int n,i,cnta=0,cntb=0,kong=0;
	scanf("%d",&n);
	scanf(" %s",&s);
	for(i=0;i<n;i++)
	{
		kong += max(playa(cnta,i),playb(cntb,i));
		if(playa(cnta,i) == playb(cntb,i)) 
		{
			if(s[i]==a[max(0,cnta-1)]) b[cntb++] = s[i];
			else if(s[i]==b[max(0,cntb-1)]) a[cnta++] = s[i];
			else a[cnta++] = s[i];
		}
		else if(playa(cnta,i) > playb(cntb,i)) a[cnta++] = s[i];
		else b[cntb++] = s[i];
	}
	printf("%d\n",kong);
	return 0;
}
