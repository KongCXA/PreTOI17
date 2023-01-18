/*
	Author	: KongCXA
	Language: C++
	Algo	: STL
*/
#include <bits/stdc++.h>
using namespace std;
set<int> s;
set<int>::iterator t,t2;

int main()
{
	int n,k,i,num;
	scanf("%d %d",&n,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&num);
		
		if(s.empty()) printf("%d\n",n);
		else
		{
			t = t2 = s.lower_bound(num);
			t2--;
			if(t==s.begin()) printf("%d\n",(*t)-num);
			else if(t==s.end()) printf("%d\n",num-(*t2));
			else printf("%d\n",min((*t)-num,num-(*t2)));
		}
		s.insert(num);
	}
	return 0;
}
