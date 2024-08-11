#include<bits/stdc++.h>
using namespace std;
const int N=8005;
int n;
string a;
int pre[N],mp[235];
int dp[N][N];
vector<int>vv;
map<pair<int,int>,bool>f;
bool chck(int l,int r)
{
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	if((r-l+1)%2==1)
	{
		return dp[l][r]=0;
	}
	else if(r-l==1)
	{
		if(a[l]==a[r])
		{
			return dp[l][r]=1;
		}
		else
		{
			return dp[l][r]=0;
		}
	}
	else if(r-l==-1)
	{
		return dp[l][r]=1;
	}
	else
	{
		if(a[l]==a[r])
		{
			if(chck(l+1,r-1))
			{
				return dp[l][r]=1;
			}
		}
		for(int k=l+1;k<r;k++)
		{
			if(chck(l,k-1)&&chck(k,r))return dp[l][r]=1;
		}
		return dp[l][r]=0;
	}
}
bool cchck(int l,int r)
{
	if(f.find({l,r})!=f.end())
	{
		return f[{l,r}];
	}
	if((r-l+1)%2==1)
	{
		return f[{l,r}]=0;
	}
	else if(r-l==1)
	{
		if(a[l]==a[r])
		{
			return f[{l,r}]=1;
		}
		else
		{
			return f[{l,r}]=0;
		}
	}
	else if(r-l==-1)
	{
		return f[{l,r}]=1;
	}
	else
	{
		if(a[l]==a[r])
		{
			if(cchck(l+1,r-1))
			{
				return f[{l,r}]=1;
			}
		}
		for(int k=l+1;k<r;k++)
		{
			if(cchck(l,k-1)&&cchck(k,r))return f[{l,r}]=1;
		}
		return f[{l,r}]=0;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>a;
	a="."+a;
	long long ans=0;
	if(n<=800)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(chck(i,j))
				{
					ans++;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=min(i+10,n);j+=2)
			{
				if(cchck(i,j))
				{
					ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
