#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
char a[N];

int n;

namespace solve1{
	int dp[N];
	int getlast(int idx){
		stack<char> sta;
		sta.push(a[idx]);
		int i = idx;
		while(!sta.empty()){
			i--;
			if(i==0) return 0;
			char t = sta.top();
			if(t==a[i]) sta.pop();
			else sta.push(a[i]);
		}
		return i;
	}
	void solve(){
		long long ans = 0;
		dp[1] = 0;
		for(int i=2;i<=n;i++){
			int t = getlast(i);
			if(t==0) continue;
			else{
				dp[i] = dp[t-1]+1;
			}
		}
		for(int i=1;i<=n;i++) ans += dp[i];
		cout << ans << endl;
	}
};

namespace solution{
	int fa[30][N];
	int dp[N];
	inline int decode(char c){
		return c-'a'+1;
	}
	void solve(){
		long long ans = 0;
		for(int i=1;i<=n;i++){
			int d = decode(a[i]);
			int last = fa[d][i-1];
			fa[d][i] = i;
			if(!last) continue;
			for(int j=1;j<=26;j++){
				if(j!=d){
					fa[j][i] = fa[j][last-1];
				}
			}
			dp[i] = dp[last-1]+1;
		}
		for(int i=1;i<=n;i++){
			ans += dp[i];
		}
		cout << ans << endl;
	}
};

int main(){
	const bool debug = 0;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	cin >> n;
	cin >> a+1;
	
	if(n<=9000 && !debug) solve1::solve();
	else solution::solve();
	
	return 0;
}
