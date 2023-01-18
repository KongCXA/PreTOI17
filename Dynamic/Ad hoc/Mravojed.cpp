/*
	Author	: KongCXA
	Language: C++
	Algo	: Dynamic Programming(Ad Hoc)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[110][110],a[110][110],dp2[110][110],dp3[110][110],dp4[110][110];

struct A{
	int i,j,w;
	bool operator <(const A& o)const{
		if(i!=o.i) return i<o.i;
		if(j!=o.j) return j<o.j;
		return w<o.w;
	}
};

vector<A> ans;

int main()
{
	int r,c,i,j,ch,ma=0,mai=0,maj=0,mii=200,mij=200,ansi,ansj,size=0;
	char cc;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf(" %c",&cc);
			if(cc=='x') a[i][j]=1;
			if(cc=='.') a[i][j]=0;
		}
	}
	
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(a[i][j]) a[i][j] = min({a[i-1][j],a[i][j-1],a[i-1][j-1]})+1;
			if(ma<a[i][j])
			{
				ma = a[i][j];
				mai = i;
				maj = j;
			}

		}
	}
	
	
	ans.push_back({mai-ma+1,maj-ma+1,ma});
	ansi = mai-ma+1;
	ansj = maj-ma+1;
	for(i=mai;i>=mai-ma+1;i--) for(j=maj;j>=maj-ma+1;j--) a[i][j] = 0;
	
	for(i=1,mai=0,maj=0,ch=0;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(a[i][j])
			{
				if(!ch)
				{
					ansi=i;
					ansj=j;
					ch=1;
					
				}
				mii = min(mii,i);
				mij = min(mij,j);
				mai = max(mai,i);
				maj = max(maj,j);
			}
		}
	}
	size = max(maj-mij+1,mai-mii+1);
	
	if(!ch)
	{
		printf("%d %d 1\n%d %d %d\n",ansi,ansj,ansi,ansj,ma);
		return 0;
	}
	
	if(mai-size+1<ansi && mai-size+1>=1) ansi = mai-size+1;
	if(maj-size+1<ansj && maj-size+1>=1) ansj = maj-size+1;
	ans.push_back({ansi,ansj,size});
	sort(ans.begin(),ans.end());
	for(i=0;i<2;i++) printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].w);
	return 0;
}
