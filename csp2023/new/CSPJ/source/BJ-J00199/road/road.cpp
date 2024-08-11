#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int v[MAXN], a[MAXN], f[MAXN], sv[MAXN];
int n, d;
int mn = 0x1f1f1f1f, mnidx, s = 0;
int tot = 0, remain = 0;

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

void solve()
{
    int curidx = 1, i = 0;
    for (int useless = 1; useless < n; useless++) {
        if (curidx == n - 1|| i == n - 1) break;
        for (i = curidx; i < n; i++) {
            if (a[i] < a[curidx]) break;
        }
        // 每次加油加到够跑到下一个比当前站点便宜的站点
        int litter = DIV_ROUND_UP(sv[i] - sv[curidx] - remain, d);
        tot += litter * a[curidx];
        remain += litter * d - (sv[i] - sv[curidx]);
        curidx = i;
    }
    int litter = DIV_ROUND_UP(v[n - 1] - remain, d);
    tot += litter * a[curidx];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        sv[i] = sv[i - 1] + v[i];
        s += v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mn > a[i]) {
            mn = a[i];
            mnidx = i;
        }
    }
    // 若站点1油价最低，则直接在站点1买够跑完全程的油
    if (mnidx == 1) {
        // 多少油够跑完全程？
        cout << a[1] * DIV_ROUND_UP(s, d) << endl;
    }
    // 贪心 拿不了多少分（甚至可能拿不到）但能拿多少是多少
    solve();
    cout << tot << endl;
    return 0;
}