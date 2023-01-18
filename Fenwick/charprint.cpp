/*
	Author	: KongCXA
	Language: C++
	Algo	: Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;
const long long FEN = 300300;
#define LSB(x) (x&-(x))

long long fenwick[FEN];
char a[FEN],b[100100];
vector<long long> vec[30];

long long query(long long idx)
{
	long long sum=0,i;
	for(i=idx;i>=1;i-=LSB(i)) sum+=fenwick[i];
	return sum;
}

int main()
{
	long long op,lena,lenb,i,j,ans=0;
	scanf("%lld %s %s",&op,a+1,b+1);
	lena = strlen(a+1);lenb = strlen(b+1);
	for(i=1;i<=lena;i++) vec[a[i]-'a'].push_back(i);

	if(op==0)
	{
		for(i=1;i<=lenb;i++)
		{
			if(vec[b[i]-'a'].empty())
			{
				ans=-1;
				break;
			}
			ans += vec[b[i]-'a'][0];
			vec[b[i]-'a'].erase(vec[b[i]-'a'].begin(),vec[b[i]-'a'].begin()+1);
		}
	}
	
	if(op==1)
	{
		for(i=1;i<=lenb;i++)
		{
			if(vec[b[i]-'a'].empty())
			{
				ans=-1;
				break;
			}
			ans += vec[b[i]-'a'][0]-query(vec[b[i]-'a'][0]);
			for(j=vec[b[i]-'a'][0];j<=FEN;j+=LSB(j)) fenwick[j]+=1;
			vec[b[i]-'a'].erase(vec[b[i]-'a'].begin(),vec[b[i]-'a'].begin()+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
