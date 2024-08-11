#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010;
int n;
string s;
bool f[N][N];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	if (n <= 1000) {
		for (int i = 0; i < s.size() - 1; i ++ )
			if (s[i] == s[i + 1]) f[i][i + 1] = 1;
		long long ans = 0; 
		for (int len = 3; len <= n; len ++ )
			for (int i = 0; i + len - 1 < n; i ++ ) {
				int j = i + len - 1;
				if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
				for (int k = i + 1; k < j; k += 2)
					f[i][j] |= (f[i][k] && f[k + 1][j]);
			}
		for (int i = 0; i < n; i ++ )
			for (int j = i; j < n; j ++ ) {
				ans += f[i][j];
			}
		cout << ans << endl;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i ++ ) 
			if (s[i] == s[i + 1]) cnt ++;
		cout << cnt << endl;
	}
	return 0;
}
