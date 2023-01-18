/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Quick Sum)
*/
#include <bits/stdc++.h>
using namespace std;
int in[1000100],out[1000100];
int main()
{
	int n,q,s,f,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&s,&f);
		in[s]++,out[f]++;
	}
	for(i=1;i<=1000000;i++) in[i]+=in[i-1],out[i]+=out[i-1];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&s,&f);
		printf("%d\n",in[f]-out[s-1]);
	}
	return 0;
}

