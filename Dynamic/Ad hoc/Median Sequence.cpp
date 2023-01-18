/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
const int OFF = 100000;

int a[100100],qs[100100],cour[200200],coul[200200];

int main()
{
	int n,z,i,j,ans,st;
	scanf("%d %d",&n,&z);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<z) qs[i]=-1;
		else if(a[i]>z) qs[i]=1;
		else if(a[i]==z) st=i;
	}
	for(i=st+1;i<=n;i++)
	{
		qs[i]=qs[i]+qs[i-1];
		cour[OFF+qs[i]]++;
	}
	for(i=st-1;i>=1;i--)
	{
		qs[i]=qs[i]+qs[i+1];
		coul[OFF+qs[i]]++;
	}
	ans=cour[OFF]+coul[OFF]+cour[OFF]*coul[OFF];
	for(i=1;i<=n/2;i++)
	{
		ans+= cour[i+OFF]*coul[OFF-i];
		ans += cour[OFF-i]*coul[i+OFF];
	}
	printf("%d\n",ans+1);
	return 0;
}
