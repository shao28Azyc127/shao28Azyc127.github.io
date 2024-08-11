#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
int read()
{
	int f=1,ret=0;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';c=getchar();
	}
	return ret*f;
}
int c,n,m,q,a[N],b[N],aa[N],bb[N],t1[N],t2[N],flag;
void dfs(int op,int dep,int sum1,int sum2)
{	
	if(op==2&&dep==m+1)
	{
		if(sum1==sum2)
		{
			int p=1;
			for(int i=1;i<=sum1;i++)
			{
				if(t1[i]<t2[i]) 
				{
					p=0;break;
				}
			}
			if(p) flag=1;
			return;
		}
		if(sum1<sum2)
		{
			int p=1;
			for(int i=1;i<=sum1;i++)
			{
				if(t1[i]<t2[i]) 
				{
					p=0;break;
				}
			}
			for(int i=sum1+1;i<=sum2;i++)
			{
				if(t1[sum1]<t2[i])
				{
					p=0;break;
				}
			}
			if(p) flag=1;
			return;
		}
		if(sum1>sum2)
		{
			int p=1;
			for(int i=1;i<=sum1;i++)
			{
				if(t1[i]<t2[i]) 
				{
					p=0;break;
				}
			}
			for(int i=sum2+1;i<=sum1;i++)
			{
				if(t1[i]<t2[sum2])
				{
					p=0;break;
				}
			}
			if(p) flag=1;
			return;
		}
	}
	if(op==1&&dep==n+1)
	{
		dfs(2,1,sum1,0);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(op==1) 
		{
			for(int j=1;j<=i;j++)
			{
				t1[sum1+j]=a[dep];
			}
			dfs(op,dep+1,sum1+i,sum2);
		}
		else 
		{
			for(int j=1;j<=i;j++)
			{
				t2[sum2+j]=b[dep];
			}
			dfs(op,dep+1,sum1,sum2+i);
		}
	}
}
void check()
{
	if(a[n]<b[m]||a[1]==b[1])
	{
		cout<<0;return;
	}
	flag=0;
	dfs(1,1,0,0);
	cout<<flag;
	return;
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	if(c==1)
	{
		aa[1]=read(),bb[1]=read();
		a[1]=aa[1],b[1]=bb[1];
		if(a[1]!=b[1]) cout<<1;
		else cout<<0;
		while(q--)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]=aa[i];
			}
			for(int i=1;i<=m;i++)
			{
				b[i]=bb[i];
			}
			int u,v;u=read(),v=read();
			for(int i=1;i<=u;i++)
			{
				int g,h;g=read(),h=read();
				a[g]=h;
			}
			for(int i=1;i<=v;i++)
			{
				int g,h;g=read(),h=read();
				b[g]=h;
			}
			a[1]=aa[1],b[1]=bb[1];
			if(a[1]!=b[1]) cout<<1;
		}
	}
	if(c==2)
	{
		for(int i=1;i<=n;i++) aa[i]=read();
		for(int i=1;i<=m;i++) bb[i]=read();
		if(n==2&&m==2)
		{
			if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
			else cout<<0;
		}
		if(n==1&&m==2)
		{
			if((a[1]-b[1])*(a[1]-b[2])>0) cout<<1;
			else cout<<0;
		}	
		if(n==2&&m==1)
		{
			if((a[1]-b[1])*(a[2]-b[1])>0) cout<<1;
			else cout<<0;
		}
		if(n==1&&m==1)
		{
			if(n!=m) cout<<1;
			else cout<<0;
		}
		while(q--)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]=aa[i];
			}
			for(int i=1;i<=m;i++)
			{
				b[i]=bb[i];
			}
			int u,v;u=read(),v=read();
			for(int i=1;i<=u;i++)
			{
				int g,h;g=read(),h=read();
				a[g]=h;
			}
			for(int i=1;i<=v;i++)
			{
				int g,h;g=read(),h=read();
				b[g]=h;
			}
			if(n==2&&m==2)
			{
				if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
				else cout<<0;
			}
			if(n==1&&m==2)
			{
				if((a[1]-b[1])*(a[1]-b[2])>0) cout<<1;
				else cout<<0;
			}	
			if(n==2&&m==1)
			{
				if((a[1]-b[1])*(a[2]-b[1])>0) cout<<1;
				else cout<<0;
			}
			if(n==1&&m==1)
			{
				if(n!=m) cout<<1;
				else cout<<0;
			}
		}
	}
	if(c==3||c==4)
	{
		for(int i=1;i<=n;i++) aa[i]=read();
		for(int i=1;i<=m;i++) bb[i]=read();
		if(aa[1]<bb[1])
		{
			for(int i=1;i<=max(n,m);i++)
			{
				swap(aa[i],bb[i]);
			}
			swap(n,m);
		}
		for(int i=1;i<=n;i++) a[i]=aa[i];
		for(int i=1;i<=m;i++) b[i]=bb[i];
		check();
		while(q--)
		{
			for(int i=1;i<=n;i++) a[i]=aa[i];
			for(int i=1;i<=m;i++) b[i]=bb[i];
			int u,v;u=read(),v=read();
			for(int i=1;i<=u;i++)
			{
				int g,h;g=read(),h=read();
				a[g]=h;
			}
			for(int i=1;i<=v;i++)
			{
				int g,h;g=read(),h=read();
				b[g]=h;
			}
			check();
		}
	}
	return 0;
}