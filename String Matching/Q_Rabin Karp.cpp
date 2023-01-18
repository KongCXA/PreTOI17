/*
	Author	: KongCXA
	Language: C++
	Algo	: String Matching
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1000003;

char a[1000100],b[1000100];

int ch(char c)
{
	if(isalpha(c)) return (c-'a'+10);
	else return (c-'0');
}

int main()
{
	int lena,lenb,i,ha=0,hb=0,j,tmp,cut;
	scanf(" %s",a);
	scanf(" %s",b);
	lena = strlen(a);
	lenb = strlen(b);
	
	for(i=0,cut=1;i<lenb;i++)
	{
		ha = ((ha*37)+ch(a[i]))%M;
		hb = ((hb*37)+ch(b[i]))%M;
		if(i!=lenb-1)cut = (cut*37)%M;
	}
	
	
	for(i=0;i<lena-lenb;i++)
	{
		if(ha==hb)
		{
			for(j=0;j<lenb;j++) if(a[i+j]!=b[j]) break;
			if(j==lenb)
			{
				printf("Lucky\n");
				return 0;
			}
		}
		ha-=(ch(a[i])*cut)%M;
		ha= (ha+M)%M;
		ha=(((ha-tmp)*37)+ch(a[i+lenb]))%M;
	}
	printf("Unlucky\n");
	return 0;
}
