/*
	Author	: KongCXA
	Language: C++
	Algo	: Math
*/
#include <bits/stdc++.h>
using namespace std;


bool mark[10000000];
vector<int> ans;

int main()
{
	int i,j,n;
	for(i=2;i<=8000000;i++)
	{
		if(mark[i]) continue;
		for(j=i*2;j<=8000000;j+=i) mark[j]=true;
		ans.push_back(i); 
	}
	scanf("%d",&n);
	printf("%d\n",ans[n-1]);
	return 0;
}
