

#include <iostream>
#define ll long long

const int MAXN = 1e5+9;
const ll inf = 1e18;
using namespace std;

int C, T, N, M, K, x[MAXN], y[MAXN], v[MAXN];
ll ans = -inf, d;

bool run[MAXN];
void dfs (int cur) {
    if (cur > N) {
        int cnt = 0;
        ll res = 0;
        for (int i = 1; i < N+1; i++) {
            if (run[i]) {
                cnt++;
                res -= d;
                if (cnt > K) return;
                for (int j = 1; j < M+1; j++) if (x[j] == i && cnt >= y[j]) res += v[j];
            }
            else cnt = 0;
        }
        ans = max(res, ans);
        return;
    }
    run[cur] = 1;
    dfs(cur+1);
    run[cur] = 0;
    dfs(cur+1);
}

int main () {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    cin >> C >> T;

    while (T--) {
        cin >> N >> M >> K >> d;
        for (int i = 1; i < M+1; i++) cin >> x[i] >> y[i] >> v[i];
        bool c18 = 1;
        for (int i = 1; i < M; i++) c18 &= (x[i] < x[i+1]-y[i+1]-1);
        if (!c18) dfs(1);
        else {
            ans = 0;
            for (int i = 1; i < M+1; i++) ans += max(0ll, v[i]-y[i]*d);
        }
        cout << ans;
    }

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}