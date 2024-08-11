#include <fstream>

using namespace std;

ifstream cin("lock.in");
ofstream cout("lock.out");

int n;
int a[10][10];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		cout << 81 << endl;
	} else if (n == 2) {
		int cnt = 0, cn = 0;
		int w[10], m[10];
		for (int i = 1; i <= 5; i++) {
			if (a[1][i] != a[2][i]) {
				w[cnt] = i;
				cnt++;
			} else {
				m[cn] = i;
				cn++;
			}
		}
		if (cnt == 5) {
			cout << 0 << endl;
		} else if (cnt == 1) {
			if (w[0] == 1 || w[0] == 5) cout << 10 << endl;
			else cout << 12 << endl;
		} else if (cnt == 2) {
			int dis1 = a[1][w[0]] - a[1][w[1]], 
			dis2 = a[2][w[0]] - a[2][w[1]];
			if (w[0] + 1 == w[1]) {
				if (dis1 == dis2) {
					cout << 10 << endl;
				} else {
					cout << 2 << endl;
				}
			} else if (w[0] + 2 == w[1]) {
				int tmp1 = a[1][w[0]] - a[2][w[0]], 
				tmp2 = a[1][w[1]] - a[2][w[1]];
				if (tmp1 + tmp2 == 0 || tmp1 + tmp2 == 10) {
					cout << 4 << endl;
				} else {
					cout << 2 << endl;
				}
			} else {
				cout << 2 << endl;
			}
		} else if (cnt == 4) {
			if (m[0] == 2 || m[0] == 4) {
				cout << 0 << endl;
			} else {
				int dis1 = a[1][w[0]] - a[1][w[1]], 
				dis2 = a[2][w[0]] - a[2][w[1]],
				dis3 = a[1][w[2]] - a[1][w[3]], 
				dis4 = a[2][w[2]] - a[2][w[3]];
				if (dis1 == dis2 && dis3 == dis4) {
					cout << 2 << endl;
				} else cout << 0 << endl;
			}
		} else {
			if (m[0] == 2 && m[1] == 4) {
				cout << 0 << endl;
			} else {
				if (w[1] - w[0] == 1 && w[2] - w[1] == 1) {
					int dis1 = a[1][w[0]] - a[1][w[1]], 
					dis2 = a[2][w[0]] - a[2][w[1]],
					dis3 = a[1][w[1]] - a[1][w[2]], 
					dis4 = a[2][w[1]] - a[2][w[2]];
					int ans = 0;
					if (dis1 == dis2) ans += 2;
					if (dis3 == dis4) ans += 2;
					cout << ans << endl;
				} else if (w[1] - w[0] == 1) {
					int dis1 = a[1][w[0]] - a[1][w[1]], 
					dis2 = a[2][w[0]] - a[2][w[1]];
					if (dis1 == dis2) {
						cout << 2 << endl;
					} else {
						cout << 0 << endl;
					}
				} else {
					int dis1 = a[1][w[1]] - a[1][w[2]], 
					dis2 = a[2][w[1]] - a[2][w[2]];
					if (dis1 == dis2) {
						cout << 2 << endl;
					} else {
						cout << 0 << endl;
					}
				}
			}
		}
	} else if (n == 8) {
		int w[10][10], cnt[10] = {0};
		bool flag = true;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= 5; j++) {
				if (a[i][j] != a[i + 1][j]) {
					w[i][cnt[i]] = j;
					cnt[i]++;
					if (cnt[i] == 2) flag = false;
				}
			}
		}
		if (flag = true) {
			int ma[10] = {0};
			int tmp = w[1][cnt[1]];
			for (int i = 1; i <= n; i++) {
				ma[a[i][tmp]]++;
			}
			int sum = 0;
			for (int i = 0; i <= 9; i++) {
				if (ma[i]) sum++;
			}
			cout << 10 - sum << endl;
		} else {
			int tt;
			for (int i = 1; i < n; i++) {
				if (cnt[i] == 2) {
					tt = i;
					break;
				}
			}
			int b[2][10];
			bool fl = false;
			for (int i = 1; i < 5; i++) {
				if (a[tt][i] == a[tt + 1][i]) {
					b[0][i] = b[1][i] = a[tt][i];
				} else {
					if (fl == false) {
						b[0][i] = a[tt][i];
						b[1][i] = a[tt + 1][i];
						fl = true;
					} else {
						b[0][i] = a[tt + 1][i];
						b[1][i] = a[tt][i];
					}
				}
			}
			bool p0 = true, p1 = true;
			for (int i = 1; i <= n; i++) {
				if (i == tt || i == tt + 1) continue;
				int cmt1 = 0, cmt2 = 0;
				for (int j = 1; j <= 5; j++) {
					if (a[i][j] != b[0][i]) cmt1++;
					if (a[i][j] != b[1][i]) cmt2++;
				}
				if (cmt1 > 1) p0 = false;
				if (cmt2 > 1) p1 = false;
			}
			if (p0 == true && p1 == true) cout << 2 << endl;
			else if (p0 == true || p1 == true) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}