#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct lock {
    int s[5];
};

int bkt[10][10][10][10][10];

void getst(lock x) {
    vector<lock> p;
    lock c = x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j != c.s[i]) {
                int t = c.s[i];
                c.s[i] = j;
                p.push_back(c);
                c.s[i] = t;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 9; j++) {
            int t1 = c.s[i], t2 = c.s[i + 1];
            c.s[i] = (t1 + j) % 10;
            c.s[i + 1] = (t2 + j) % 10;
            p.push_back(c);
            c.s[i] = t1;
            c.s[i + 1] = t2;
        }
    }
    for (int i = 0; i < p.size(); i++) {
        bkt[p[i].s[0]][p[i].s[1]][p[i].s[2]][p[i].s[3]][p[i].s[4]]++;
    }
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        lock l;
        for (int j = 0; j < 5; j++) {
            cin >> l.s[j];
        }
        getst(l);
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int o = 0; o < 10; o++) {
                        if (bkt[i][j][k][l][o] == n) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}