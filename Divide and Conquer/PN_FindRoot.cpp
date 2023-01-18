/*
	Author	: KongCXA
	Language: C++
	Algo	: Divide and Conquer
*/
#include <bits/stdc++.h>
using namespace std;
int n,k;
struct A{
	int a,b,c,d;
	
};
A p[70],ans;
A mul(A a,A b)
{
	A tmp;
	tmp.a = ((a.a*b.a)%k + (a.b*b.b*2)%k + (a.c*b.c*3)%k + (a.d*b.d*6)%k)%k;
	tmp.b = ((a.a*b.b)%k + (b.a*a.b)%k + (a.d*b.c*3)%k + (b.d*a.c*3)%k )%k;
	tmp.c = ((a.a*b.c)%k + (b.a*a.c)%k + (a.d*b.b*2)%k + (b.d*a.b*2)%k )%k;
	tmp.d = ((a.b*b.c)%k + (b.b*a.c)%k + (a.a*b.d)%k  + (b.a*a.d)%k   )%k;
	return tmp;
}

int main()
{
	int q,a,b,c,i;
	A tmp;
	scanf("%d",&q);
	while(q--)
	{
		
		scanf("%d %d %d %d %d",&a,&b,&c,&n,&k);//1 1 1 2 10
		if(n==0)
		{
			printf("1 0 0 0\n");
			continue;
		}

		p[1].a = a,p[1].b = b,p[1].c = c;
		
		for(i=2;i<=30;i++) p[i] = mul(p[i-1],p[i-1]);
		ans.a=1,ans.b=ans.c=ans.d=0;
		for(i=1;i<=30;i++)
		{
			if((1<<(i-1))&n)
			{
				tmp = mul(ans,p[i]);
				ans =tmp;
			}
		}
		printf("%d %d %d %d\n",ans.a,ans.b,ans.c,ans.d);
		memset(p,0,sizeof p);
	}
	return 0;
}
