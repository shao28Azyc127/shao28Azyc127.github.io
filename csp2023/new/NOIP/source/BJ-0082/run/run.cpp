#include <iostream>

#define int long long

using namespace std;

constexpr int N = 5e5 + 5, M = N;

int p[N];

int pos[M], req[M], rew[M];
int n, m, k, d;

int ans;

void proc() {
    int r;
#define q(i) (r & (1 << (i - 1)))
    //auto q = [=](int i) -> bool { return (bool)(r & (1 << i)); };
    //r = 1;
    //cout << q(0) << endl;
    //return;
    for (r = 0; r < (1 << (n)); r++) {
        int res = 0;
        p[0] = 0;
        bool t = true;
        for (int i = 1; i <= n; i++) {
            if (q(i)) {
                p[i] = p[i - 1] + 1;
                res -= d;
            } else {
                if (p[i] > k) {
                    t = false;
                    break;
                }
                p[i] = 0;
            }
        }
        if (p[n] > k)   continue;
        if (!t) continue;
        for (int i = 0; i < m; i++) {
            if (p[pos[i]] >= req[i])
                res += rew[i];
        }
        //cout << r << ' ' <<  res << endl;
        ans = max(ans, res);
    }
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, t;
    cin >> c >> t;
    if (c == 17 || c == 18) {
        while (t--) {
            ans = 0;
            cin >> n >> m >> k >> d;
            for (int i = 0; i < m; i++) {
                int pos, req, rew;
                cin >> pos >> req >> rew;
                if (req > k)
                    continue;
                const int t = rew - req * d;
                if (t > 0)
                    ans += t;
            }
            cout << ans << '\n';
        }
    } else {
        while (t--) {
            ans = 0;
            cin >> n >> m >> k >> d;
            for (int i = 0; i < m; i++)
                cin >> pos[i] >> req[i] >> rew[i];
            proc();
            cout << ans << '\n';
        }
    }
    return 0;
}
