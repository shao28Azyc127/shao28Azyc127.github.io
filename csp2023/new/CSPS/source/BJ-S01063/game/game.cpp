#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

typedef long long ll;
const ll base = 131, mod[2] = {1000000000 + 7, 1000000000 + 9};

char s[MAXN];
int n;

inline bool ok(int l, int r) {
    string t;
    for (int i = l; i <= r; i++) {
        t += s[i];
    }
    while (t.size() > 0) {
        vector<int> vis(n + 1, 0);
        bool flag = 0;
        for (int i = 0; i < t.size() - 1; i++) {
            if (t[i] == t[i + 1]) 
                vis[i] = vis[i + 1] = 1, i++, flag = 1;
        }
        if (!flag) return false;
        string p;
        for (int i = 0; i < t.size(); i++) {
            if (vis[i]) continue;
            p += t[i];
        }
        t = p;
    }
    return true;
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    if (n <= 800) {
        int ans = 0;
        for (int l = 1; l <= n; l++) {
            int cnt = 0;
            for (int r = l + 1; r <= n; r++) {
                if (ok(l, r)) {
                    ans++, cnt++;
                }
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}

// g++ game.cpp -o game && ./game