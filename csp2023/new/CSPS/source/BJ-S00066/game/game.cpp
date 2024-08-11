#include <bits/stdc++.h>
using namespace std;
int n, t[30], t2[30], ans;
string st;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> st;
	for (int i = 0; i < n; i++) {
		t[st[i] - 'a']++;
	}
	for (int i = 0; i < n - 1; i++) {
		int exit = 0, sit;
		if (t[st[i] - 'a'] == 1) continue;
		for (int j = i + 1; j < n; j++) {
			int exit2 = 0;
		    if (t[st[j] - 'a'] == 1) {
				sit = j;
				exit = 1;
				continue;
			}
            memset(t2, 0, sizeof(t2));
            for (int k = i; k <= j; k++) {
				t2[st[k] - 'a']++;
			}
			for (int k = 0; k < 26; i++)
			    if (t2[i] % 2 == 1) {
					exit2 = 1;
					break;
				}
			//start
			char son[9000], past;
			int son2[9000] = {0};
			int tot = 0, b = 0, pastsit;
			int m = j - i + 1;
			for (int k = 0; k < m; k++) {
				son[k] = st[i + k];
			}
			while (b++) {
				if (b == m) {
					b = 0;
				}
				if (b == 0) {
					past = son[b];
					pastsit = b;
					continue;
				}
				if (son2[b]) continue;
				if (past == son[b]) {
					tot += 2;
					son2[pastsit] = 1, son2[b] = 1;
				} else {
					past = son[b];
					pastsit = b;
				}
				if (tot == m) {
					ans++;
					break;
				}
			}
			//end
			if (exit2) continue;
	    }
	    if (exit) {
			i = sit;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}