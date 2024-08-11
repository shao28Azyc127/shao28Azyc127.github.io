

#include <iostream>

#define int long long
#define endl '\n'

using namespace std;

const int MAXI = 8 + 9;
int n, a[MAXI][9];
int b[9], mod = 10;
int ans = 0;

int FuDu (int one, int two) {
    return (one - two + mod) % mod;
}

bool Check (int id) {
    int id1 = -1, id2 = -1;
    for (int i = 0; i < 5; i++) {
        if (a[id][i] != b[i]) {
            if (id1 == -1) id1 = i;
            else if (id2 == -1) id2 = i;
            else return 0;
        }
    }
    if (id1 == -1) return 0;
    if (id2 == -1) return 1;
    if (id1 + 1 == id2 && FuDu(a[id][id1], b[id1]) == FuDu(a[id][id2], b[id2])) return 1;
    return 0;
}

void Dfs (int u) {
    if (u == 5) {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (!Check(i)) flag = 0;
        if (flag) ans++;
        return;
    }
    for (int i = 0; i < 10; i++) b[u] = i, Dfs(u + 1);
}

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++) cin >> a[i][j];

    if (n == 1) return cout << 81 << endl, 0;

    Dfs(0);

    cout << ans << endl;

    return 0;
}
