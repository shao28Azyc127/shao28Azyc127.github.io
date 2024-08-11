#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 2e6 + 5;
const int B = 101;
const int mod = 998244853;
inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
const int invB = qpow(B, mod - 2);
int n, ans;
char s[N];
int stk[N], top = 0, hsh[N];
map<int, int> hshs;
void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    top = 0; hshs.clear();
    rep(i, mid + 1, r) {
        stk[++top] = s[i]; hsh[top] = (hsh[top - 1] * B + s[i]) % mod;
        while (top >= 2 && stk[top] == stk[top - 1]) top -= 2;
        ++hshs[(top << 31) + hsh[top]];
    }
    top = 0;
    per(i, mid, l) {
        stk[++top] = s[i]; hsh[top] = (hsh[top - 1] * B + s[i]) % mod;
        while (top >= 2 && stk[top] == stk[top - 1]) top -= 2;
        auto ii = hshs.find((top << 31) + hsh[top]);
        if (ii != hshs.end()) ans += ii -> second;
    }
}
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%lld%s", &n, s + 1);
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}