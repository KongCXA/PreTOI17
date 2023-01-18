/*
	Author	: KongCXA
	Language: C++
	Algo	: Topological
*/
#include <bits/stdc++.h>
using namespace std;

char s[110][11];
int g[30][30];
vector<pair<int,int>> ans;
set<char> st;

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf(" %s",s[i]);
	for(i=0;i<n;i++)
	{
		for(char *p = s[i];*p;p++) st.insert(*p);
		
	}
	for(i=0;i<n-1;i++)
	{
		char *a = s[i];
		char *b = s[i+1];
		while(*a && *b && *a==*b) a++,b++;
		if(*a && *b) g[*a-'a'][*b-'a'] = 1;
		if(*a && !*b)
		{
			printf("!\n");
			return 0;
		}
	}
	for(k=0;k<26;k++) for(i=0;i<26;i++) for(j=0;j<26;j++) g[i][j] |= g[i][k]&g[k][j];
	for(i=0;i<26;i++)
	{
		if(g[i][i])
		{
			printf("!\n");
			return 0;
		}
	}
	for(i=0;i<26;i++)
	{
		int out=0,in=0;
		for(j=0;j<26;j++)
		{
			out+=g[i][j];
			in +=g[j][i];
		}
		if(out+in == st.size()-1) ans.push_back({out,'a'+i});
	}
	sort(ans.begin(),ans.end());
	if(ans.size()!=st.size())
	{
		printf("?\n");
		return 0;
	}
	else for(i=ans.size()-1;i>=0;i--) printf("%c",ans[i].second);
	return 0;
}
