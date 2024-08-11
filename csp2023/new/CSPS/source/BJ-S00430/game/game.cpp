#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;

int dp[N],r[N],nex[N][30];
char s[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin >> n;
	scanf("%s",s+1);
	for(int i=n;i>=1;i--)
	{
		r[i]=nex[i+1][s[i]-'a'];
		nex[i][s[i]-'a']=i;
		if(!r[i])
			continue;

		for(int c=0;c<26;c++)
			if(c!=s[i]-'a')
				nex[i][c]=nex[r[i]+1][c];
	}

	for(int i=n;i>=1;i--)
		if(r[i])
			dp[i]=dp[r[i]+1]+1;

	long long ans=0;
	for(int i=1;i<=n;i++)
		ans += dp[i];
	printf("%lld\n",ans);
	return 0;
}