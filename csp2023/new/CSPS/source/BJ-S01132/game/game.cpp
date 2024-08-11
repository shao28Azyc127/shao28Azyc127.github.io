#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[2000010];
bool dp[805][805];
bool pd[2000010][15];
ll ans=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n>800)
	{
		for(int i=1;i<=n;i++) pd[i][0]=1,pd[i][1]=0;
		for(int k=2;k<=10;k+=2)
		{
			for(int i=1;i+k-1<=n;i++)
			{
				int j=i+k-1;
				if(s[i]==s[j]) pd[i][k]|=pd[i+1][k-2];
				for(int p=i+1;p<j;p+=2) pd[i][k]|=(pd[i][p-i+1]&pd[p+1][j-p]);
				if(pd[i][k]) ans++;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++) dp[i][i]=0,dp[i][i-1]=1;
		for(int k=2;k<=n;k+=2)
		{
			for(int i=1;i+k-1<=n;i++)
			{
				int j=i+k-1;
				if(s[i]==s[j]) dp[i][j]|=dp[i+1][j-1];
				for(int p=i+1;p<j;p+=2) dp[i][j]|=(dp[i][p]&dp[p+1][j]);
				if(dp[i][j]) ans++;
			}
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}