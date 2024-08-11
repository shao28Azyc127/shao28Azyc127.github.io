#include<bits/stdc++.h>
using namespace std;
const int MX = 2e6 + 7;
int n;char s[MX];
int to[MX],dep[MX];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> s + 1;
	to[n] = n + 1;
	long long ans = 0;
	for(int i = n - 1;i >= 1;i--){
		int j = i + 1;
		while(j <= n && s[j] != s[i])j = to[j] + 1;
		to[i] = j;
		if(to[i] > n)continue;
		else{
			dep[i] = dep[to[i] + 1] + 1;
			ans += dep[i];
		}
	}
	cout << ans << '\n';
	return 0;
}