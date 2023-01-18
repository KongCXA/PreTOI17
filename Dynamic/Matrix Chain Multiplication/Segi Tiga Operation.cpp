/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Matrix Chain Multiplication)
*/
#include <bits/stdc++.h>
using namespace std;

char s[300];

int check[3][3] = {{2,1,0},{2,1,1},{1,2,1}},dp[300][300][4];

int main()
{
	
	int q = 20,n,i,j,k,a,b,c;
	while(q--)
	{
		memset(dp,0,sizeof dp);
		scanf("%d %s",&n,&s);
		
		if(s[0]!='0') printf("no\n");
		else
		{
		
		for(c=0;c<n;c++)
		{
			i=0;
			for(j=c;j<n;j++)
			{
				if(i==j) dp[i][j][s[i]-'0'] = 1;
				else
				{
					for(k=i;k<j;k++)
					{
						for(a=0;a<3;a++)
						{
							for(b=0;b<3;b++)
							{
								if(dp[i][k][a] && dp[k+1][j][b]) dp[i][j][check[a][b]] = 1;
							}
						}
					}
				}
				i++;
			}
		}
		if(dp[0][n-1][0]==1) printf("yes\n");
		else printf("no\n");
		}
		
	}
	return 0;
}
