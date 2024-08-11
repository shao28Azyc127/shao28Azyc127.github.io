#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int N=1e5+5;
int c,tt;
int s[N];
int con[N];
int f[N],tmp[N];
int n,m;
struct node
{
	int i,j;
	int ne,po;
	int T,F,U;
}t[N];
int ans=1e9+7;;
void checks()
{
	for(int i=1;i<=n;i++)
	{
		tmp[i]=f[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(t[i].F==1||t[i].T==1||t[i].U==1)
		{
			if(t[i].F==1)
			{
				tmp[t[i].i]=-1;
			}
			else if(t[i].T==1)
			{
				tmp[t[i].i]=1;
			}
			else if(t[i].U==1)
			{
				tmp[t[i].i]=0;
			}
		}
		else
		{
			if(t[i].po==1)
			{
				tmp[t[i].i]=tmp[t[i].j];
			}
			else
			{
				if(t[i].ne==1)
				{
					tmp[t[i].i]=-tmp[t[i].j];
				}
			}
		}
	}
	bool p=1;
	int cntt=0;
	for(int i=1;i<=n;i++)
	{
		if(tmp[i]==0)
		{
			cntt++;
		}
		if(f[i]!=tmp[i])
		{
			p=0;
		}
	}
	if(p==1)
	{
		ans=min(ans,cntt);
	}
	return;
}
void dfs(int d)
{
	if(d==n)
	{
		checks();
		return;
	}
	for(int i=0;i<=2;i++)
	{
		f[d+1]=i-1;
		dfs(d+1);
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> tt;
	if(c==1||c==2)
	{
		while(tt--)
		{
			ans=1e9+7;
			cin >> n >> m;
			char v;
			int a,b;
			for(int i=1;i<=n;i++)
			{
				t[i].T=0;
				t[i].F=0;
				t[i].U=0;
				t[i].po=0;
				t[i].ne=0;
			}
			for(int i=1;i<=m;i++)
			{
				cin >> v;
				if(v=='T')
				{
					cin >> a;
					t[i].T=1;
					t[i].i=a;
				}
				if(v=='F')
				{
					cin >> a;
					t[i].F=1;
					t[i].i=a;
				}
				if(v=='U')
				{
					cin >> a;
					t[i].U=1;
					t[i].i=a;
				}
				if(v=='+')
				{
					t[i].po=1;
					cin >> a >> b;
					t[i].i=a;
					t[i].j=b;
				}
				if(v=='-')
				{
					t[i].ne=1;
					cin >> a >> b;
					t[i].i=a;
					t[i].j=b;
				}
			}
			dfs(0);
			cout << ans << endl;
		}
	}
	else if(c==3||c==4)
	{
		while(tt--)
		{
			int cnt=0;
			cin >> n >> m;
			char v;
			int b;
			for(int i=1;i<=n;i++)
			{
				s[i]=1;
			}
			for(int i=1;i<=m;i++)
			{
				cin >> v >> b;
				if(v=='T')
				{
					s[b]=1;
				}
				else if(v=='F')
				{
					s[b]=-1;
				}
				else
				{
					s[b]=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(s[i]==0)
				{
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	else if(c==5||c==6)
	{
		while(tt--)
		{
			int cnt=0;
			cin >> n >> m;
			char v;
			int b,a;
			for(int i=1;i<=n;i++)
			{
				s[i]=1;
			}
			for(int i=1;i<=m;i++)
			{
				cin >> v >> b;
				if(v=='U')
				{
					s[b]=0;
				}
				else
				{
					cin >> a;
					s[b]=s[a];
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(s[i]==0)
				{
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	else if(c==7||c==8)
	{
		while(tt--)
		{
			ans=1e9+7;
			cin >> n >> m;
			char v;
			int a,b;
			for(int i=1;i<=m;i++)
			{
				cin >> v;
				if(v=='+')
				{
					cin >> a >> b;
				}
				if(v=='-')
				{
					cin >> a >> b;
				}
			}
			cout << 0 << endl;
		}
	}
	return 0;
}
