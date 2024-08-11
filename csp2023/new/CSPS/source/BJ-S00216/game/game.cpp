#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return f*ret;
}
int n,dp[2005][2005];
string s;
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=true;
		}
	}
	for(int len=4;len<=n;len+=2)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(s[i]==s[j]&&dp[i+1][j-1])
			{
				dp[i][j]=1;
			}
			else
			{
				for(int k=i+1;k<j;k++)
				{
					if(dp[i][k]&&dp[k+1][j])
					{
						dp[i][j]=1;break;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans+=dp[i][j];
		}
	}
	cout<<ans;
	return 0;
}
