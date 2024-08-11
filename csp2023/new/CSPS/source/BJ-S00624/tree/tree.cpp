#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int b[100005],c[100005],u,v,ans[100005];
int head[100005],tnt,ans1,maxa,maxi;
int q[500005],headq=1,tail,n;
struct node
{
	int to,nxt;
}nde[100005];
void add(int x,int y)
{
	nde[++tnt].to=y;
	nde[tnt].nxt=head[x];
	head[x]=tnt;
}
void dfs(int st)
{
	if(ans1==n)
	{
		ans1+=maxa;
		return ;
	}
	int i;
	for(i=head[st];i;i=nde[i].nxt)
		q[++tail]=i;
	for(i=headq;i<=tail;i++)
	{
		if(q[i]>maxa)
		{
			maxa=q[i];
			maxi=i;
		}
	}
	cout<<maxi<<" ";
	headq--;
	ans1++;
	maxa--;
	dfs(maxi);
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		long long anss=0;
		while(anss>=a[i])
		{
			ans[i]++;
			anss+=max(b[i]+ans[i]*c[i],1);
		}
	}
	for(i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	q[++tail]=1;
	dfs(1);
	cout<<ans1;
	return 0;
}
