/*
	Author	: KongCXA
	Language: C++
	Algo	: String Matching
*/
#include <bits/stdc++.h>
using namespace std;

char a[100100],b[1010][15],op[8];
int mark[(1<<11)],cou[(1<<11)];
int main()
{
	int k,n,m,i,sum,cut,j,q,l,r,ans,now,idx,ii,jj;
	scanf("%d %d %d %s",&k,&n,&m,a+1);
	cut = (1<<(n-1));
	for(i=1,sum=0;i<=m;i++)
	{
		sum *= 2;
		sum += (a[i]-'0');
		if(i>=n)
		{
			cou[sum]+=1;
			sum -= (a[i-n+1]-'0') * cut;	
		}	
	}
	
	for(i=1,ans=0;i<=k;i++)
	{
		scanf(" %s",b[i]+1);
		for(j=1,now=0;j<=n;j++)
		{
			now *= 2;
			now += (b[i][j]-'0');
		}
		ans += cou[now];
		mark[now] = 1;
	}
	
	scanf("%d",&q);
	while(q--)
	{
		scanf(" %s",op);
		if(op[1]=='i') printf("%d\n",ans);
		else
		{
			scanf("%d",&idx); idx++;
			l = max(idx+1-n,1);
			r = min(idx-1+n,m);
			for(i=l,now=0;i<=r;i++)
			{
				now *= 2;
				now += (a[i]-'0');
				if(i-l+1>=n)
				{
					if(mark[now]) ans--;
					now -= (a[i-n+1]-'0') * cut;
				}
			}
			
			if(a[idx]=='1') a[idx]='0';
			else a[idx]='1';
			for(i=l,sum=0;i<=r;i++)
			{
				sum *= 2;
				sum += (a[i]-'0');
				if(i-l+1>=n)
				{
					if(mark[sum]) ans++;
					sum -= (a[i-n+1]-'0') * cut;	
				}	
			}
			
		
		}
	}
	return 0;
}
