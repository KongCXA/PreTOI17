/*
	Author	: KongCXA
	Language: C++
	Algo	: Sliding Window
*/
#include <bits/stdc++.h>
using namespace std;

deque<int> mid,mad;
int ma[1000100],mi[1000100],a[1000100];
int main()
{
	int n,m,c,i,ch=0;
	scanf("%d %d %d",&n,&m,&c);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++)
	{
		while(!mad.empty()&&a[i]>a[mad.back()]) mad.pop_back();
		mad.push_back(i);
		while(!mid.empty()&&a[i]<a[mid.back()]) mid.pop_back();
		mid.push_back(i);
		if(i<m) continue;
		while(!mad.empty()&&mad.front()<=i-m) mad.pop_front();
		while(!mid.empty()&&mid.front()<=i-m) mid.pop_front();
		if(a[mad.front()]-a[mid.front()]<=c) printf("%d\n",i-m+1),ch=1;
	}

	if(!ch) printf("NONE\n");
	return 0;
}
