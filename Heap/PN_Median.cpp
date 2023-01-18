/*
	Author	: KongCXA
	Language: C++
	Algo	: Priority Queue
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	double a;
	bool operator <(const A& o)const{
		return a>o.a;
	}
};

priority_queue<double> s;
priority_queue<double,vector<double>,greater<double>> g;

int main()
{
	int n,i;
	double med,x;
	
	scanf("%d %lf",&n,&med);
	s.push(med);
	printf("%.1lf\n",med);
	
	for(i=1;i<n;i++)
	{
		scanf("%lf",&x);
		if(s.size()>g.size())
		{
			if(x<med) g.push(s.top()) , s.pop() , s.push(x);
			else g.push(x);
			med = (s.top()+g.top())/2.0;
		}
		else if(s.size()==g.size())
		{
			if(x<med) s.push(x),med=(double) s.top();
			else g.push(x),med=(double) g.top();
		}
		
		else
		{
			if(x>med) s.push(g.top()) , g.pop() , g.push(x);
			else s.push(x);
			med = (s.top()+g.top())/2.0;
		}
		printf("%.1lf\n",med);
	}
	return 0;
}
