#include <iostream>
#include <cstdio>
#include <set>
#define iter set<int>::iterator
using namespace std;
int n, a[9];
set<int> s, ss, now;
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
        int dd, aa, rr, kk, oo;
        cin >> dd >> aa >> rr >> kk >> oo;
        a[i] = a[i] * 10 + dd;
        a[i] = a[i] * 10 + aa;
        a[i] = a[i] * 10 + rr;
        a[i] = a[i] * 10 + kk;
        a[i] = a[i] * 10 + oo;
	}
    for (int i = 1; i <= n; i++) {
        now.clear();
        int b[6];
        b[1] = a[i] / 10000;
        b[2] = a[i] % 10000 / 1000;
        b[3] = a[i] % 1000 / 100;
        b[4] = a[i] % 100 / 10;
        b[5] = a[i] % 10;
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 10; j++) {
                if (b[i] == 9) {
                    b[i] = 0;
                    if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                } else {
                    b[i]++;
                    if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                }
            }
            for (int j = 1; j <= 10; j++) {
                if (b[i] == 0) {
                    b[i] = 9;
                    if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                } else {
                    b[i]--;
                    if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                }
            }
        }
        for (int i = 1; i < 5; i++) {
            int l = i, r = i + 1;
            for (int j = 1; j <= 10; j++) {
                if (b[l] == 9) {
                    b[l] = 0;
                    if (b[r] == 9) {
                        b[r] = 0;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    } else {
                        b[r]++;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    }
                } else {
                    b[l]++;
                    if (b[r] == 9) {
                        b[r] = 0;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    } else {
                        b[r]++;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    }
                }
            }
            for (int j = 1; j <= 10; j++) {
                if (b[l] == 0) {
                    b[l] = 9;
                    if (b[r] == 0) {
                        b[r] = 9;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    } else {
                        b[r]--;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    }
                } else {
                    b[l]--;
                    if (b[r] == 0) {
                        b[r] = 9;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    } else {
                        b[r]--;
                        if (j < 10) now.insert(b[1] * 10000 + b[2] * 1000 + b[3] * 100 + b[4] * 10 + b[5]);
                    }
                }
            }
        }
        if (i == 1) {
            s = now;
            continue;
        }
        ss.clear();
        for (iter it = now.begin(); it != now.end(); it++) {
            int num = *it;
            if (s.count(num)) ss.insert(num);
        }
        s = ss;
    }
    cout << s.size() << '\n';
	return 0;
}
