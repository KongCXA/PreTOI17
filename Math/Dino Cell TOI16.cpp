/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;

int a[1000100],sum[10000200];
int main()
{
	int z,k,n,i,j,ans,ii,jj,sz,pos,neg,mi,now,temp,idx,ma;
	scanf("%d %d %d",&z,&k,&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(i=2;i<=k;i++)
	{
		if(k%i!=0) continue;
		for(j=i;j<=k;j+=i) sum[j]=1;
	}
	for(i=1;i<=k;i++)
	{
		if(sum[i]==1)sum[i]+=sum[i-1];
		else sum[i]+=sum[i-1]-1;
	}
	
	mi = sum[(a[1]-1)%k] ; mi += (a[1]-1)/k *sum[k]; idx=1;
	ma = sum[(a[1]-1)%k] ; ma += (a[1]-1)/k *sum[k];
	for(i=2;i<=n;i++)
	{
			now = sum[(a[i])%k] ; now += (a[i])/k *sum[k];
			ans = max(ans,abs(now-mi));
			ans = max(ans,abs(now-ma));	
			temp =sum[(a[i]-1)%k] ; temp += (a[i]-1)/k *sum[k];	
			mi=min(mi,temp);
			ma=max(ma,temp);
	}
	
	printf("%d\n",ans);
	return 0;
}
