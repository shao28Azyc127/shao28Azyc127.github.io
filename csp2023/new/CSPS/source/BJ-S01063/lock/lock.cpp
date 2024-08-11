#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;

vector<int> a[MAXN];
set<vector<int> > st[MAXN], all, tmp;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i].resize(5);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            vector<int> b(5);
            for (int k = 0; k < 5; k++) {
                b[k] = a[i][k];
            }
            for (int k = 1; k < 10; k++) {
                b[j] = (b[j] + 1) % 10;
                st[i].insert(b);
            }
        }
        for (int j = 0; j < 4; j++) {
            vector<int> b(5);
            for (int k = 0; k < 5; k++) {
                b[k] = a[i][k];
            }
            for (int k = 1; k < 10; k++) {
                b[j] = (b[j] + 1) % 10;
                b[j + 1] = (b[j + 1] + 1) % 10;
                st[i].insert(b);
            }
        }
    }
    for (auto x: st[1]) all.insert(x);
    for (int i = 2; i <= n; i++) {
        tmp.clear();
        for (auto x: all) {
            if (st[i].find(x) == st[i].end()) 
                tmp.insert(x);
        }
        for (auto x: st[i]) {
            if (all.find(x) == all.end())
                tmp.insert(x);
        }
        for (auto x: tmp) all.erase(x);
    }
    printf("%d\n", (int)all.size());
}

// g++ lock.cpp -o lock && ./lock
// expected 100pts

// Good Luck.