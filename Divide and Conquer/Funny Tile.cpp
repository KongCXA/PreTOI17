/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int a,b,c;
	bool operator <(const A& o)const{
		if(a!=o.a) return a<o.a;
		else if(b!=o.b) return b<o.b;
		return c<o.c;
	}	
};

vector<A> ans;
void play(int n,int im,int jm,int x,int y)
{
	int q;
	if(x<im && y<jm) q=1;
	if(x<im && y>=jm) q=2;
	if(x>=im && y<jm) q=3;
	if(x>=im && y>=jm) q=4;
	
	ans.push_back({q-1,jm-1,im-1});
	if(n<=2) return;
	
	if(q==1) play(n/2,im-n/4,jm-n/4,x,y);
	else     play(n/2,im-n/4,jm-n/4,im-1,jm-1);
	
	if(q==2) play(n/2,im-n/4,jm+n/4,x,y);
	else     play(n/2,im-n/4,jm+n/4,im-1,jm);
	
	if(q==3) play(n/2,im+n/4,jm-n/4,x,y);
	else     play(n/2,im+n/4,jm-n/4,im,jm-1);
	
	if(q==4) play(n/2,im+n/4,jm+n/4,x,y);
	else     play(n/2,im+n/4,jm+n/4,im,jm);
	
}


int main()
{
	int l,x,y,n,i;
	scanf("%d %d %d",&n,&y,&x);
	play(n,n/2,n/2,x,y);
	sort(ans.begin(),ans.end());
	printf("%d\n",n*n/3);
	for(i=0;i<ans.size();i++)
	{
		printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
	}
	return 0;
}
