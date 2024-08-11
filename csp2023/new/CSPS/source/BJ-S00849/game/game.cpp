#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+5;
using namespace std;
int n,dp[MAXN],lst[26][MAXN],f[MAXN];
ll ans;
string s;
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		char c=s[i-1];
		int j=lst[c-'a'][f[i-1]];
		if(!j)
		{
			f[i]=i,lst[c-'a'][f[i]]=i;
			continue;
		}
		dp[i]=dp[j-1]+1,f[i]=f[j-1];
		ans+=dp[i],lst[c-'a'][f[i]]=i;
		// cout<<i<<' '<<dp[i]<<" "<<f[i]<<endl;
	}
	cout<<ans;
	return 0;
}