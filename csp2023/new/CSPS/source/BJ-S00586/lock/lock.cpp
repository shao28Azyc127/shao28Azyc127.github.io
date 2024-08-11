# include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;
int n, a[MAXN][10], t[10];
int ans = 0;
bool check() {
	for (int i = 1; i <= n; i++) {
		int cnt = 0, delta = -1, flag = 1, id = -1;
		for (int j = 1; j <= 5; j++) {
			if (t[j] != a[i][j]) {
				cnt++;
				if (delta == -1) delta = (a[i][j] - t[j] + 10) % 10;
				else if (delta != (a[i][j] - t[j] + 10) % 10) flag = 0;
                if (id == -1) id = j;
                else if (id != j - 1) flag = 0; 
            }
		}
		if (cnt > 2 || !flag) return 0;
        if (!cnt) return 0;
	}
   // for (int i = 1; i <= 5; i++) {
    //    cout << t[i] << " " ;
   // }
    cout << endl ;
	return 1;
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= 5; j++) {
		for (int k = 1; k <= 5; k++) t[k] = a[1][k];
		for (int k = 0; k < 10; k++) {
			if (k != a[1][j]) {
				t[j] = k;
				ans += check();
			}
		}
	}
	for (int i = 1; i < 5; i++) {
		for (int k = 1; k < 10; k++) {
			for (int j = 1; j <= 5; j++) t[j] = a[1][j];
			t[i] = (t[i] + k) % 10;
			t[i + 1] = (t[i + 1] + k) % 10;
			ans += check();
		}
	}
	cout << ans << endl ;
	return 0;
}