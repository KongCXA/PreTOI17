/*
	Author	: KongCXA
	Language: C++
	Algo	: Depth First Search
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int a[350][350],n,m,di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int next(int from,int now)
{
	if(from%2==0)
	{
		if(now==11||now==13) return 3;
		if(now==12||now==14) return 1;
		if(now==21||now==31) return (2-from);
	}
	else
	{
		if(now==11||now==12) return 0;
		if(now==13||now==14) return 2;
		if(now==22||now==31) return (4-from);
	}
}

void play(int i,int j,int from,int now,int cou)
{
	if(i<1||i>n||j<1||j>m)
	{
		ans.push_back(cou);
		return;
	}
	if(a[i][j]==31)
	{
		if(from%2==0) a[i][j] = 22;
		else a[i][j] = 21;
	}
	else a[i][j] = 0;
	int k = next(from,now);
	if(k%2==0) play(i+di[k],j+dj[k],2-k, a[i+di[k]][j+dj[k]],cou+1);
	else 	   play(i+di[k],j+dj[k],4-k, a[i+di[k]][j+dj[k]],cou+1);
}

int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
	{
		if(a[i][m]==22||a[i][m]==14||a[i][m]==12||a[i][m]==31) play(i,m,1,a[i][m],0);
		if(a[i][1]==22||a[i][1]==13||a[i][1]==11||a[i][1]==31) play(i,1,3,a[i][1],0);
	}
	for(j=1;j<=m;j++)
	{
		if(a[n][j]==13||a[n][j]==14||a[n][j]==21||a[n][j]==31) play(n,j,2,a[n][j],0);
		if(a[1][j]==11||a[1][j]==12||a[1][j]==21||a[1][j]==31) play(1,j,0,a[1][j],0);
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(auto x:ans) printf("%d ",x);
	return 0;
}
