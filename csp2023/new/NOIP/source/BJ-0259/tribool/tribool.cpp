#include <bits/stdc++.h>
using namespace std;
int xx[100010],yy[100010],b[100010],c[100010],ans,n,m;
char a[100010],oo[100010];
void f(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
			c[i]=b[i];
		for(int i=1;i<=m;i++)
		{
			if(oo[i]=='+')
				b[xx[i]]=b[yy[i]];
			if(oo[i]=='-')
			{
				if(b[yy[i]]==2)
					b[xx[i]]=2;
				else
					b[xx[i]]=(b[yy[i]]+1)%2;
			}
			if(oo[i]=='U')
				b[i]=2;
			if(oo[i]=='T')
				b[i]=1;
			if(oo[i]=='F')
				b[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=c[i])
				return;
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==2)
				s++;
		}
		ans=min(ans,s);
		return;
	}
	for(int i=0;i<3;i++)
	{
		b[x]=i;
		f(x+1);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==1||c==2)
	{
		while(t--)
		{
			int i;
			cin>>n>>m;
			for(i=1;i<=m;i++)
			{
				cin>>oo[i]>>xx[i];
				if(oo[i]=='+'||oo[i]=='-')
					cin>>yy[i];
			}
			ans=0x3f3f3f3f;
			f(1);
			cout<<ans<<'\n';
		}
	}
	else if(c==3||c==4||c==5||c==6)
	{
		while(t--)
		{
			char o;
			int x,y,i;
			cin>>n>>m;
			for(i=1;i<=n;i++)
				a[i]='F';
			for(i=1;i<=m;i++)
			{
				cin>>o>>x;
				if(o=='+')
				{
					cin>>y;
					a[x]=a[y];
				}
				else
					a[i]=o;
			}
			ans=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]=='U')
					ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
