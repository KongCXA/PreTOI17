/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;

int a[2020][2020],dpl[2020][2020],dpr[2020][2020],trl[2020][2020],trr[2020][2020];
int main()
{
	int m,n,k,i,j,kong=-1e9;
	scanf("%d %d %d",&m,&n,&k);
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			dpl[i][j] = a[i][j]+dpl[i-1][j]+dpl[i][j-1]-dpl[i-1][j-1];
			trl[i][j] = dpl[i][j] + trl[i-1][j-1] - dpl[i-1][j];
		}
	}

	for(i=1;i<=m;i++)
	{
		for(j=n;j>=1;j--)
		{
			dpr[i][j] = a[i][j]+dpr[i-1][j]+dpr[i][j+1]-dpr[i-1][j+1];
			trr[i][j] = dpr[i][j] + trr[i-1][j+1] - dpr[i-1][j];
		}
	}
	
	for(i=k;i<=m;i++) for(j=k;j<=n;j++) kong = max(kong,trl[i][j] - trl[i-k][j-k] - dpl[i][j-k] + dpl[i-k][j-k]);
	for(i=k;i<=m;i++) for(j=n-k+1;j>=1;j--) kong = max(kong,trr[i][j] - trr[i-k][j+k] - dpr[i][j+k] + dpr[i-k][j+k]);
	
	printf("%d\n",kong);
	return 0;
}
