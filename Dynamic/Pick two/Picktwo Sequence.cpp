/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Pick Two)
*/
#include <bits/stdc++.h>
using namespace std;
int a[100100],l[100100],r[100100];

int main()
{
	int q,n,i,sum,ans;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		l[0] = 0; r[n+1] = 0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1,sum=0;i<=n;i++)
		{
			sum += a[i];
			sum = max(sum,0);
			l[i] = max(sum,l[i-1]);
		}
		for(i=n,sum=0;i>=1;i--)
		{
			sum += a[i];
			sum = max(sum,0);
			r[i] = max(sum,r[i+1]);
		}
		for(i=1,ans=-1e9;i<=n;i++) ans = max(ans,l[i]+r[i+1]);
		printf("%d\n",ans);
	}
	return 0;
}
