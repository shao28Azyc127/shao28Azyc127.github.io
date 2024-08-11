#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[3005][3005];
int cnt[3005][30];

int mx[3005], mn[3005]; // yu chu li
void pd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt[i][s[i][j] - 'a']++;
			mx[i] = max(mx[i], s[i][j] - 'a');
			mn[i] = min(mn[i], s[i][j] - 'a');
		}
	}
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    // Bao Li Chu Qi Ji
    // LLCMZ, hope it will not be kachang.
    // fuzadu O(n2), 100pts
    memset(mn, 0x3f, sizeof(mn));
    memset(mx, -1, sizeof(mx));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	pd();
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			// tongji
		    if (mx[j] > mn[i]) continue; // jian zhi
		    if (mx[j] < mn[i]) {
				flag = false;
				// cout << i << " " << j << endl;
				break;
			}
			flag = false;
			// cout << i << " " << j << endl;
			break;
		}
		if (flag) {
			putchar('1');
		} else {
			putchar('0');
		}
	}
	putchar('\n');
    return 0;
}
