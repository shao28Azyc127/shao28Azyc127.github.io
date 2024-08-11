#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;
const int MR = (1 << 20) + 5;

struct Node {
    int a, b, c;
} p[NR]; 

int n, anss;
vector < pair < int, int > > e;

inline int calc(int x, int y) {
    int a = p[x].a, b = p[x].b, c = p[x].c;
    int l = 1, r = 1e9;
    __int128 s = a, t;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (c > 0) t = (__int128)mid * b + (__int128)mid * (mid + 1) / 2 * c;
        else { 
            int z = min(mid, (int)(b - 1) / (-c));
            t = (__int128)z * b + (__int128)z * (z + 1) / 2 * c + (mid - z);
        }
        if (t >= s) r = mid;
        else l = mid;
    }
    if (c > 0) t = (__int128)l * b + (__int128)l * (l + 1) / 2 * c;
    else { 
        int z = min(l, (int)(b - 1) / (-c));
        t = (__int128)z * b + (__int128)z * (z + 1) / 2 * c + (l - z);
    }
    if (t >= s) return l;
    return r;
}

inline void line() {
    for (int i = 1; i <= n; ++i) cin >> p[i].a >> p[i].b >> p[i].c;
    for (int i = 1, _, __; i < n; ++i) cin >> _  >> __;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, calc(i, i));
    cout << ans << '\n';
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    line();
    return 0;
}