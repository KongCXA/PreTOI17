/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;


char a[100100],key[110];
int dp[110][100100];

int main()
{
	int lena,lenkey,i,j,ch,ans;
	scanf(" %s %s",key+1,a+1);
	lena = strlen(a+1);
	lenkey = strlen(key+1);
	
	for(i=1;i<=lena;i++) a[i]=tolower(a[i]);
	for(i=1;i<=lenkey;i++) key[i]=tolower(key[i]);
	
	if(lenkey>lena)
	{
		printf("RIP ASIA\n");
		return 0;
	}
	
	for(i=1;i<=lenkey;i++)
	{
		for(j=1;j<i;j++) dp[i][j] = 1e9;
		for(j=i,ch=0;j<=lena;j++)
		{
			if(key[i]==a[j]) dp[i][j]=dp[i-1][j-1],ch=1;
			else if(ch) dp[i][j] = dp[i][j-1]+1;
			else dp[i][j] = 1e9;
		}
	}
	for(i=lenkey,ans=1e9;i<=lena;i++) ans=min(ans,dp[lenkey][i]);
	if(ans==1e9) printf("RIP ASIA\n");
	else printf("%d\n",ans);
	return 0;
}
