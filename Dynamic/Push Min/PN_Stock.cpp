/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Push Min)
*/
#include <bits/stdc++.h>
using namespace std;


int a[1000100],dpl[1000100],dpr[1000100];
int main()
{
	int q,n,i,mi,ma,ans;
	scanf("%d",&q);
	while(q--)
	{
		ans=0;
		memset(dpl,0,sizeof dpl);
		memset(dpr,0,sizeof dpr);
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		mi = a[1], ma = a[n];
		for(i=2;i<=n;i++) 
		{
			dpl[i] = max(dpl[i-1],a[i]-mi);
			mi = min(mi,a[i]);	
		}
		for(i=n-1;i>=1;i--) 
		{
		
			dpr[i] = max(dpr[i+1],ma-a[i]);
			ma = max(ma,a[i]);	
		}	
		for(i=1;i<=n;i++) ans = max(ans,dpl[i]+dpr[i+1]);	
		printf("%d\n",ans);
	}
	return 0;
}
