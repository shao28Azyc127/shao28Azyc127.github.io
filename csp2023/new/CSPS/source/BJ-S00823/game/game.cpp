#include <bits/stdc++.h>
using namespace std;
int dp[8010][8010],ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,i,j,k;
	string s;
	cin>>n>>s;
	for(i=2;i<=n;i+=2)
	{
		for(j=0;j<=n-i;j++)
		{
			if((dp[i-2][j+1]||i==2)&&(s[j]==s[j+i-1]))
			{
				ans++;
				dp[i][j]=1;
				continue;
			}
			for(k=j+2;k<=j+i-2;k++)
			{
				if(dp[k-j][j]&&dp[j+i-k][k])
				{
					ans++;
					dp[i][j]=1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
