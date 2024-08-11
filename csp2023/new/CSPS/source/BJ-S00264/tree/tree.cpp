#include<iostream>
using namespace std;
int n,a[505],b[505],c[505],list[505];
int t[505][505],cnt[505],cntt=1,anss=1e9;
bool flag[505];
void calc()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int h=0,x=i;
		while(h<a[list[i]])
		{
			x++;
			h+=max(b[list[i]]+x*c[list[i]],1);
		}
		x--;
		ans=max(ans,x);
	}
	anss=min(ans,anss);
	return;
}
void dfs(int p,int g)
{
	//cout<<p<<" "<<g<<endl;
	if(p>=n)
	{
		calc();
		return;
	}
	list[cntt]=g;
	for(int i=1;i<=cnt[g];i++)
	{
		flag[t[g][i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			cntt++;
			flag[i]=0;
			dfs(p+1,i);
			flag[i]=1;
			cntt--;
		}
	}
	for(int i=1;i<=cnt[g];i++)
	{
		flag[t[g][i]]=0;
	}
}
int main()
{
	freopen("r","tree.in",stdin);
	freopen("w","tree.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		++cnt[u];
		//++cnt[v];
		t[u][cnt[u]]=v;
		//t[v][cnt[v]]=u;
	}
	dfs(1,1);
	cout<<anss;
}
