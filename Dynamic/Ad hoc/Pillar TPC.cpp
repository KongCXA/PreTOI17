/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int r[100100],l[100100],a[100100];

int main()
{
	int t,n,i,c,add,ans,ma,id,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			l[i] = r[i] =1;
		}
		if(n==1)
		{
			printf("1 0\n");
			continue;
		}
		for(i=n-2;i>=0;i--) if(a[i]-a[i+1]<=2 && a[i]-a[i+1]>=1) r[i] += r[i+1];
		for(i=n-2;i>=0;i--) if(a[i+1]-a[i]<=2 && a[i+1]-a[i]>=1) l[i] += l[i+1];

		for(i=0,sum=0,ma=0;i<n;i++)
		{
			if(i<n-1 && l[i+1]+1 > ma) ma=l[i+1]+1,id=i;
			if(i>0 && sum+1>ma) ma=sum+1,id=i;
			if(i>0 && i<n-1 && a[i+1]-a[i-1] <=4 && a[i+1]-a[i-1] >=2 && sum+l[i+1]+1>ma) ma =sum+l[i+1]+1,id=i;
			
			if(i>0 && a[i]-a[i-1]>=1 && a[i]-a[i-1]<=2) sum++;
			else sum=1;
		}

		for(i=0,sum=0;i<n;i++)
		{
			if(i<n-1 && r[i+1]+1 >= ma)
			{
				if(r[i+1]+1==ma) id=min(id,i);	
			 	else ma=r[i+1]+1,id=i;
			}
			if(i>0 && sum+1>=ma)
			{ 
				if(sum+1==ma) id=min(id,i);	
			 	else ma=sum+1,id=i;
			}
			if(i>0 && i<n-1 && a[i-1]-a[i+1] <=4 && a[i-1]-a[i+1] >=2 && sum+r[i+1]+1>=ma)
			{ 
				if(sum+r[i+1]+1==ma) id=min(id,i);	
			 	else ma =sum+r[i+1]+1,id=i;
			}
			
			if(i>0 && a[i-1]-a[i]>=1 && a[i-1]-a[i]<=2) sum++;
			else sum=1;
		
		}
		
		printf("%d %d\n",ma,id);
		memset(a,0,sizeof a);
		memset(r,0,sizeof r);
		memset(l,0,sizeof l);
		
	}
	return 0;
}
