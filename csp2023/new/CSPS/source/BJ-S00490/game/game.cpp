#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, ans = 0;
	string a;
	cin >> n >> a;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			stack<char> s;
			for (int k = i; k <= j; k++){
				if (!s.empty() && a[k] == s.top()) s.pop();
				else s.push(a[k]);
			}
			if (s.empty()) ans++;
		}
	}
	cout << ans;
	return 0;
}