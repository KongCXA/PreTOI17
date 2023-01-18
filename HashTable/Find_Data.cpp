/*
	Author	: KongCXA
	Language: C++
	Algo	: Hash Table
*/
#include <bits/stdc++.h>
using namespace std;
#define M 99999989
#define hs 10000019
int h[hs];
long long pw[2][5050];
 
int main()
{
	int i,j,a,b,n,m,x,y,key,num,ans=0;
	scanf("%d %d %d %d",&a,&b,&n,&m);
	for(i=0;i<=5000;i++)
	{
		pw[0][i] = (i*i)%M;
		pw[1][i] = (pw[0][i]*i)%M;
	}
	
	for(i=0;i<a;i++)
	{
		scanf("%d",&x);
		for(j=0;j<b;j++)
		{
			num = (x+pw[0][j])%M;
			key = num % hs;
			while(h[key]) key++,key%=hs;
			h[key] = num;
		}
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&y);
		for(j=0;j<m;j++)
		{
			num = (y+pw[1][j])%M;
			key = num%hs;
			while(h[key])
			{
				if(h[key]==num)
				{
					ans++;
					break;
				}
				key++;
				key%=hs;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
