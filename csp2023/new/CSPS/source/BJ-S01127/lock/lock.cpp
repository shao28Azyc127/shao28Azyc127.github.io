// I am Chen, a junior middle school student.
// My favourite teacher is Su***.
// Ad: Welcome to BJDX! 
#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int ans = 0;
int b[10];
bool cmp(int x) {
	int cnt = 0, pos;
	for (int i = 1; i <= 5; i++) {
		if (b[i] != a[x][i]) {
			cnt++;
			pos = i;
		}
		if (cnt > 2) return true; // Turn more than 2 circle
	}
	if (cnt == 0) return true; // Turn le ge mao
	if (cnt == 1) return false; // Only turned one circle
	if (b[pos - 1] == a[x][pos - 1]) return true; // turned the disnearly circle
	// calc the fudu of the turning
	int f = (b[pos] + 10 - a[x][pos]) % 10;
	int g = (b[pos - 1] + 10 - a[x][pos - 1]) % 10;
	return f != g;
}
bool test() {
	for (int i = 1; i <= n; i++) {
		if (cmp(i)) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i <= 9; i++) {
		b[1] = i;
		for (int j = 0; j <= 9; j++) {
			b[2] = j;
			for (int k = 0; k <= 9; k++) {
				b[3] = k;
				for (int l = 0; l <= 9; l++) {
					b[4] = l;
					for (int m = 0; m <= 9; m++) {
						b[5] = m;
						if (test()) {
							ans++;
						}
				    }
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
