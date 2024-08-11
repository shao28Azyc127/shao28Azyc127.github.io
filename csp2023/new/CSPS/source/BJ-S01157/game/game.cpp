#include<iostream>
#include<cstdio>
using namespace std;
long long n,hehe[8010],ans;
bool dp[8005][8005];
char c[8010];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		dp[i+1][i]=true;
	}
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++) {
			if(c[i]==c[j])
				dp[i][j]|=dp[i+1][j-1];
			if(hehe[i])
				dp[i][j]|=dp[hehe[i]+1][j];
			if(dp[i][j]&&!hehe[i])
				hehe[i]=j;
			if(dp[i][j])
				ans++;
		}
	cout<<ans<<"\n";
	return 0;
}