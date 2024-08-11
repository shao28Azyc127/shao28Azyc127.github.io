#include<bits/stdc++.h>
using namespace std;
int u[10005];
int v[10005];
int a[10005];
int vis[10005];
int ans=10000005;
int n,m,k;
void dfs(int t, int pos)
{
	//cout<<pos<<" "<<t<<" "<<endl;
	if(pos==n)
	{
		if(t%k==0)
		{
			ans=min(ans,t);
		}
		return;
	}
	if(vis[pos]==1)
	{
		return;
	}
	for(int i=1;i<=m;i++)
	{
		vis[i]=1;
		if(u[i]==pos&&t>=a[i])dfs(t+1,v[i]);
		vis[i]=0;
	}
	return;
}
int main()
{
	//freopen("bus.in","r",stdin);
	//freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	int largest=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>a[i];
		largest=max(largest,a[i]);
	}
	for(int i=0;i<=largest;i+=k)
	{
		dfs(i,1);
	}
	if(ans==10000005)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}
