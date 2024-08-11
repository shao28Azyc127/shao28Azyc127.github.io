#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3005;
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
int n,m,cnt[N][30];
string w[N],maxx[N],minn[N];
priority_queue<char> q;
void solve()
{
	n=read(),m=read();char l;

	for(int i=1;i<=n;i++)
	{
        cin>>w[i];
        for(int j=0;j<m;j++)cnt[i][w[i][j]-'a'+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=26;j>=1;j--)
		{
			for(int k=1;k<=cnt[i][j];k++)
			{
				maxx[i]+=(j+'a'-1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			minn[i]+=maxx[i][m-j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(minn[i]>maxx[j])
			{
				flag=1;break;
			}
		}
		cout<<(flag+1)%2;
	}
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	solve();
	return 0;
}
