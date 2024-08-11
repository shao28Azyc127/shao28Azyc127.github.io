#include <bits/stdc++.h>
#define ll long long
#define y1 jiajia
using namespace std;
void read(int &x) {
	int f = 1; x = 0; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
};
int ans = 0;
int n;
int a[15][15];
int w[15];
void dfs(int u) {
	if (u == 6) {
		for (int i = 1; i <= n; i++) {
			int b[7];
			for (int j = 1; j <= 5; j++) {
				b[j] = (a[i][j] - w[j] + 10) % 10;
			}
			vector<int> vec;
			for (int j = 1; j <= 5; j++) {
				if (b[j] != 0) vec.push_back(j);
			}
			if (vec.size() > 2 || vec.size() == 0) goto end;
			if (vec.size() == 1) continue;
			if (vec[0] + 1 != vec[1]) goto end;
			if (b[vec[0]] != b[vec[1]]) goto end;
		}
		++ans;
		end:;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		w[u] = i;
		dfs(u + 1);
	}
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) cin >> a[i][j];
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}