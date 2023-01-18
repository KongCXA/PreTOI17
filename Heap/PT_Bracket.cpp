/*
	Author	: KongCXA
	Language: C++
	Algo	: Priority Queue
*/
#include <bits/stdc++.h>
using namespace std;
char s[50500];
priority_queue<long long> h;

int main()
{
	long long len,i,cnt,x,y,ans,c,q;
	scanf("%lld",&q);
	while(q--)
	{
		scanf(" %s",s);
		len = strlen(s);
		for(i=0,c=0,ans=0,cnt=0;i<len;i++)
		{
			if(s[i]=='(') cnt++;
			else if(s[i]==')') cnt--;
			else if(s[i]=='?')
			{
				scanf("%lld %lld",&x,&y);
				ans += y;
				cnt--;
				h.push({y-x});
			}
			if(cnt<0)
			{
				if(h.empty())
				{
					c=1;
					continue;
				}
				ans -= h.top();
				h.pop();
				cnt += 2;
			}
		}
		if(!c && cnt==0)printf("%lld\n",ans);
		else printf("-1\n");
		while(!h.empty()) h.pop();
	}
	return 0;
}
