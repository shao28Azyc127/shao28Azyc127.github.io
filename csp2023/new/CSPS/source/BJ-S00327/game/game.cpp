#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n;
char ts[N];
int s[N];
int to[N];
ll dp[N];
ll ans=0;
int get_fa(int x){ return to[x]==x?x:get_fa(to[x]);}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	int i,j; 
	scanf("%s",ts+1);
	for(i=1;i<=n;i++) s[i]=ts[i]-'a'+1; 
	for(i=1;i<=n+2;i++) to[i]=i;
	s[n+1]=s[n+2]=-1;
	dp[n+1]=dp[n+2]=0;
	for(i=n;i>=1;i--)
	{
		j=to[i];
		for(;j<n&&s[j+1]!=s[i];j=to[j+1]);
		if(s[j+1]==s[i]) {
			to[i]=j+1;
			dp[i]=1+dp[j+2];
		}
		else {
			to[i]=n+1;
			dp[i]=0;
		}
	}
	for(i=1;i<=n;i++) ans+=dp[i];
	printf("%lld\n",ans);
	return 0;
}