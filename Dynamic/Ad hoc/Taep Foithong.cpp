/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[5000500],power[12];
char s[110];

int play(int u)
{
	if(dp[u]!=-1) return dp[u];
	dp[u]=0;
	int t=u,num=0;
	while(t>0)
	{
		num+=power[t%10];
		t/=10;
	}
	if(num==u) return dp[u] = 1;
	return dp[u]=play(num);
}

int main()
{
	int q,k,i,j,num,num2,len;
	scanf("%d %d",&q,&k);
	for(i=0;i<=9;i++) for(j=1,power[i]=1;j<=k;j++) power[i]*=i;
	memset(dp,-1,sizeof dp);
	while(q--)
	{
		scanf(" %s",s);
		len = strlen(s);
		for(i=0;i<len;i++) num += power[s[i]-'0'];
		num2=0;
		while(num>0)
		{
			num2 += power[num%10];
			num/=10;
			
		}
		if(play(num2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
