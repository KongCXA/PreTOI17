/*
	Author	: KongCXA
	Language: C++
	Algo	: Brute Force
*/
#include <bits/stdc++.h>
using namespace std;
int n;
void play(int state,int bw,int bs)
{
	if(state==n)
	{
		printf("%d %d\n",bw,bw+bs+1);
		return;
	}
	play(state+1,bs+bw+1,bw);
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
	    play(0,1,0);
	}
	return 0;
}



