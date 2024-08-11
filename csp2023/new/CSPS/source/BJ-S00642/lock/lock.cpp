#include<iostream>
#include<cstdio>
using namespace std;
int a[10][10],d[10],n,ans;
void check()
{
	int i,j;
	bool flag=false;
	for(i=1;i<=n;i++)
	{
		bool ok1=false,ok2=false;
		int pos[30],t=0;
		for(j=1;j<=5;j++)
		{
			if(d[j]!=a[i][j])
				pos[t++]=j;
		}
		if(t==2&&pos[0]+1==pos[1]&&(d[pos[1]]-d[pos[0]]==a[i][pos[1]]-a[i][pos[0]]||d[pos[1]]-d[pos[0]]==a[i][pos[1]]-a[i][pos[0]]+10||d[pos[1]]-d[pos[0]]+10==a[i][pos[1]]-a[i][pos[0]]))
			ok1=1;
		t=0;
		for(j=1;j<=5;j++)
			if(d[j]!=a[i][j]) t++;
		if(t==1) ok2=true;
		if(ok1||ok2) flag=true;
		else 
		{
			flag=false;
			break;
		}
	}
	if(flag) ans++;
}
void dfs(int x)
{
	if(x==6){
		check();
		return;
	}
	int i;
	for(i=0;i<=9;i++)
	{
		d[x]=i;
		dfs(x+1);
		d[x]=0;
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=5;j++)
			cin>>a[i][j];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
