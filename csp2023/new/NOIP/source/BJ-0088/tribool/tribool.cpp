#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,m;
int a[100010];
int fa[200020];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x+=n+2; y+=n+2;
	int t1=find(x),t2=find(y);
	if(t1!=t2) fa[t1]=t2;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char c; cin>>c;
		if(c=='T')
		{
			scanf("%d",&x);
			a[x]=n+1;
		}
		else if(c=='F')
		{
			scanf("%d",&x);
			a[x]=-n-1;
		}
		else if(c=='U')
		{
			scanf("%d",&x);
			a[x]=0;
		}
		else if(c=='+')
		{
			scanf("%d%d",&x,&y);
			a[x]=a[y];
		}
		else
		{
			scanf("%d%d",&x,&y);
			a[x]=-a[y];
		}
	}
	for(int i=1;i<=2*n+3;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		merge(i,a[i]);
		merge(-i,-a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=i+n+2,y=-i+n+2;
		int t1=find(x),t2=find(y);
		if(t1==t2) ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--) solve();
	return 0;
}