#include <iostream>
#include <cstring>

constexpr int N = 805;
using namespace std;

char a[N];
bool valid[N];

int nxt(int x, int n) {
    for (; x < n; x++)
        if (valid[x])
            return x;
    return -1;
}

int main() {

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin >> a;
    int ans = 0;
    memset(valid, true, n + 3);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cnt = 0;
            while (true) {
                bool good = false;
                char last = 'A';
                int last_pos = -1;
                //if (i == 0 && j == 4)
                //    cout << nxt(i, j) << endl;
                for (int k = nxt(i, j); k != -1; k = nxt(k + 1, j)) {
                    if (a[k] == last) {
                        valid[k] = valid[last_pos] = false;
                        cnt += 2;
                        good = true;
                        last = 'A';
                    } else {
                        last = a[k];
                        last_pos = k;
                    }
                    //if (i == 0 && j == 4)
                    //    cout << '\t' << k << ' ' << nxt(k + 1, j) << ' ' << cnt << endl;
                }
                if (cnt == j - i) {
                    ans++;
                    //cout << i << ' ' << j << endl;
                    break;
                }
                if (!good)
                    break;
            }
            memset(valid, true, n + 3);
        }
    }
    cout << ans << endl;
    return 0;
}
