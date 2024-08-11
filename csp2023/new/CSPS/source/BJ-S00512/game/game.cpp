#include<bits/stdc++.h>
using namespace std;
int n,dp[8005][4005],cnt;string s;
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> s;
	s="#"+s;
	for(int i=1;i<n;i++)if(s[i]==s[i+1])dp[i][1]=1,ans++;
	for(int i=2;i<=n/2;i++){
		for(int j=1;j+i*2-1<=n;j++){
			if(dp[j+1][i-1]&&s[j]==s[j+i*2-1]){
				dp[j][i]=1;
				ans++;
				continue;
			}
			for(int k=1;k<i;k++){
				if(dp[j][k]&&dp[j+2*k][i-k]){
					dp[j][i]=1;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}