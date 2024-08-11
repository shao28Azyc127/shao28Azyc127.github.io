#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005;
char s[N][N];
char mx[N], mn[N];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		mn[i] = 'z';
		mx[i] = 'a';
		for (int j = 1; j <= m; j++) {
			mx[i] = max(mx[i], s[i][j]);
			mn[i] = min(mn[i], s[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int f = 1;
		for (int j = 1; j <= n; j++)
			if (j != i && mx[j] <= mn[i]) {
				f = 0;
				break;
			}
		printf("%d", f);
	}
	return 0;
}
