#include<iostream>
#include<cstdio>
using namespace std;
bool dp[805][805];
string s;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,n,j,k;
	cin>>n>>s;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(s[i-1]==s[j-1])
			{
				if((j-i+1)%2==0) dp[i][j]=1;
			}
			else break;
		}
	for(i=n-1;i>=1;i--)
		for(j=i+2;j<=n;j++)
		{
			if(s[i-1]==s[j-1])
				dp[i][j]=dp[i+1][j-1];
			for(k=i;k<j;k++)
				if(dp[i][k]&&dp[k+1][j]) dp[i][j]=1;
		}
	long long ans=0;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(dp[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}
