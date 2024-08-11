#include <iostream>
#include <cstdio>

using namespace std;
struct Code {
	short c[5];
	int to_int() {
		return c[0] * 10000 + c[1] * 1000 + c[2] * 100 + c[3] * 10 + c[4];
	}
} code[8];
int n;
int cnt[100000];
int mod(int i, int p) {
	return (i >= p) ? (i - 10) : (i);
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> code[i].c[j];
		}
		cnt[code[i].to_int()] = -100;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 5; k++) {
			for (int j = 0; j < 10; j++) {
				code[i].c[k] = mod(code[i].c[k] + 1, 10);
				cnt[code[i].to_int()]++;
			}
		}
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 10; j++) {
				code[i].c[k] = mod(code[i].c[k] + 1, 10);
				code[i].c[k + 1] = mod(code[i].c[k + 1] + 1, 10);
				cnt[code[i].to_int()]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100000; i++) {
		if (cnt[i] == n) {
			ans++;
		//	cout << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
1 1 1 1 1
1 1 3 1 1
1 1 6 1 1
1 1 8 1 4
1 1 8 2 6
1 1 0 1 5
1 1 8 1 9
1 1 8 0 4

*/