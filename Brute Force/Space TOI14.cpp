/*
	Author	: KongCXA
	Language: C++
	Algo	: Brute Force
*/
#include <bits/stdc++.h>
using namespace std;

char a[2][10010];
int h[2][10010],l[2][10010],n[2][10010];
int main()
{
	int c,r,i,j,cou,sum,mid,k,square,diamond,triangle;
	scanf("%d %d",&c,&r);
	cou=square=diamond=triangle=0;
	for(i=0;i<=r;i++)
	{
		if(i!=r) scanf(" %s",a[i%2]+1);
		else for(j=1;j<=c;j++) a[i%2][j]='0';
		memset(h[i%2],0,sizeof h[i%2]);
		memset(l[i%2],0,sizeof l[i%2]);
		memset(n[i%2],0,sizeof n[i%2]);
		for(j=1;j<=c;j++)
		{
			if(a[i%2][j]=='1')
			{
				cou++;
				if(a[i%2][j+1]!='1')
				{
					sum=cou;
					cou=0;
					mid=(j+j-sum+1)/2;
					
					for(k=j-sum+1;k<=j;k++)
					{
						h[i%2][k]=h[1-i%2][mid]+1;
						l[i%2][k]=sum;
						n[i%2][k]=n[1-i%2][mid]+sum;
					}	
				}
			}
			else if(a[i%2][j]=='0')
			{
				if(a[1-i%2][j]=='1'&&a[i%2][j+1]=='0'&&a[i%2][j-1]=='0') cou++;
				if(a[1-i%2][j]=='1'&&a[1-i%2][j+1]!='1'&&a[i%2][j+1]!='1'&&a[i%2][j-1]!='1')
				{
					sum=cou;
					cou=0;
					mid=(j+j-sum+1)/2;
					if(h[1-i%2][mid]*h[1-i%2][mid]==n[1-i%2][mid] && h[1-i%2][mid]==l[1-i%2][mid]) square++;
					else if(h[1-i%2][mid]+2*((h[1-i%2][mid]/2)*(h[1-i%2][mid]/2))==n[1-i%2][mid] && n[1-i%2][mid]%2==1) diamond++;
					else triangle++;
				}
				
			}
		}
		
	}
	printf("%d %d %d\n",square,diamond,triangle)
	return 0;
}
