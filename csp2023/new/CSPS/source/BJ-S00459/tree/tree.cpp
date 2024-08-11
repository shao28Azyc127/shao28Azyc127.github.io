#include <iostream>
#include <vector>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
vector <int> vec[100005];
bool vis[100005];
int h[100005],num,ans=1e9;
int tot=0;
int check()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			return -1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]<a[i])
		{
			return 0;
		}
	}
	return 1;
}
void update(int day)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)
		{
			h[i]+=max(b[i]+day*c[i],1);
		}
	}
}
void reverse(int day)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)
		{
			h[i]-=max(b[i]+day*c[i],1);
		}
	}
}
int updater(int day)
{
	if(check()==1)
	{
		return 0;
	}
	else
	{
		update(day);
		int temp=updater(day+1)+1;
		reverse(day);
		return temp;
	}
}
void dfs(int u,int day)
{
	int ck=check();
	if(ck==1)
	{
		ans=min(ans,day);
		return ;
	}
	else if(ck==0)
	{
		ans=min(ans,day+updater(day));
		return ;
	}
	for(auto v:vec[u])
	{
		if(vis[v]==false)
		{
			vis[v]=true;
			h[v]=0;
			update(day);
			dfs(v,day+1);
			reverse(day);
			vis[v]=false;
		}
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		h[i]=-1;
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	vis[1]=true;
	h[1]=max(b[1]+1*c[1],1);
	if(check()==1) 
	{
		cout<<1<<endl;
		return 0;
	}
	dfs(1,2);
	cout<<ans;
}
