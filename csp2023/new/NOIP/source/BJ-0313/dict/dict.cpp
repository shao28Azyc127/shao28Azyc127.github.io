#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3010;
int n, m;
char s[N][N];
string a[N];
string su[N], sum[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	if (n == 1) {
		puts("1");
		return 0;
	}
	for (int i = 1; i <= n; i ++ ) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j ++ ) a[i] += s[i][j];
		sort(a[i].begin(), a[i].end());
		reverse(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i ++ ) {
		if (i == 1) su[i] = a[i];
		else su[i] = min(su[i - 1], a[i]);
	}
	for (int i = n; i; i -- ) {
		if (i == n) sum[i] = a[i];
		else sum[i] = min(sum[i + 1], a[i]);
	}
	for (int i = 1; i <= n; i ++ ) {
		string t = a[i];
		reverse(t.begin(), t.end());
		string f;
		if (i > 1 && i < n) f = min(su[i - 1], sum[i + 1]);
		else if (i == 1) f = sum[i + 1];
		else f = su[i - 1];
		if (f <= t) cout << '0';
		else cout << '1';
	}
	return 0;
}
