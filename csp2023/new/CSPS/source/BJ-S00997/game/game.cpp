#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;

ll n,ans;
char s[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>(s+1);
	for (int i=1; i<=n; i++) {
		stack<int> sta;
		for (int j=i; j<=n; j++) {
			if (!sta.empty()&&s[sta.top()]==s[j]) sta.pop();
			else sta.push(j);
			if (sta.empty()) ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
