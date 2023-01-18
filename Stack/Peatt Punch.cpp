/*
	Author	: KongCXA
	Language: C++
	Algo	: Stack
*/
#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> st;
int ans[100100];

int main()
{
	int l,q,i,h,num;
	scanf("%d %d",&l,&q);
	for(i=0;i<l;i++)
	{
		scanf("%d",&h);
		
		while(!st.empty() &&  h <= st.top().first ) st.pop();
		if(st.empty()) num = 0;
		else num = max(h-st.top().first,st.top().second);
		ans[i] = num;
		st.push({h,num});
	}
	
	sort(ans,ans+l);
	while(q--)
	{
		scanf("%d",&h);
		printf("%d\n",l-(upper_bound(ans,ans+l,h)-ans));
	}
	return 0;
}
