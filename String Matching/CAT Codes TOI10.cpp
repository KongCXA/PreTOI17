/*
	Author	: KongCXA
	Language: C++
	Algo	: String Matching
*/
#include <bits/stdc++.h>
using namespace std;
const int HASHSZ = 1e6+3;
const int M = 1e9+7;

struct HASH{
	int mp[HASHSZ],val[HASHSZ];
	void insert(int idx,int value)
	{
		int it = value % HASHSZ;
		while(mp[it]) it = (it+1)%HASHSZ;
		mp[it] = idx;
		val[it] = value;
		
	}
	int find(int value)
	{
		int it = value%HASHSZ;
		int idx = 0;
		while(mp[it])
		{
			if(val[it]==value)
			{
				idx = mp[it];
				break;
			}
			it = (it+1)%HASHSZ;
		}
		return idx;
	}
};

HASH mp;
int  mark[100010];
char a[40],text[1000100];

int main()
{
	int k,sz,i,j,pat,q,n,len,ch,idx,ht;
	scanf("%d %d",&k,&sz);
	for(i=1;i<=k;i++)
	{
		scanf(" %s",a);
		
		for(j=0,pat=0;j<sz;j++)
		{
			pat = ((pat<<1)|(a[j]-'0'));
		}
		mp.insert(i,pat);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		scanf(" %s",text);
		for(i=0,ht=0;i<sz;i++) ht = (ht<<1)|(text[i]-'0');
		len = strlen(text);
		ch=0;
		for(i=0;i<len-sz+1;i++)
		{
			idx = mp.find(ht);
			if(idx && !mark[idx])
			{
				ch=1;
				mark[idx]=1;
			}
			ht = ((ht<<1)-((text[i]-'0')<<(sz))) | (text[i+sz]-'0');
		}
		if(!ch)
		{
			printf("OK\n");
			continue;
		}
		for(i=1;i<=k;i++)
		{
			if(mark[i]) printf("%d ",i);
			mark[i]=0;
		}
	}
	return 0;
}
