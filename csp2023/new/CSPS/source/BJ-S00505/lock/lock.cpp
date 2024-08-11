#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n;
ll a[8 + 5][5 + 5], b[5 + 5];
bool chk1() {
    for (ll i = 2; i <= n; i++) {
        ll cnt = 0;
        for (ll j = 1; j <= 5; j++) {
            if (a[i][j] != b[j]) cnt++;
        }
        if (cnt != 1) return 0;
    }
    return 1;
}
bool chk2() {
    for (ll i = 2; i <= n; i++) {
        ll cnt = 0;
        for (ll j = 1; j < 5; j++) {
            if (a[i][j] != b[j] && a[i][j] == a[i][j + 1]) cnt++;
        }
        if (cnt != 1) return 0;
    }
    return 1;
}
inline ll dis(ll x, ll y) {
    return (y - x + 10) % 10;
}
bool check() {
    for (ll i = 2; i <= n; i++) {
        ll cnt1 = 0;
        for (ll j = 1; j <= 5; j++) {
            if (a[i][j] != b[j]) cnt1++;
        }
        if (cnt1 == 1) continue;
        ll cnt2 = 0, pos;
        for (ll j = 1; j < 5; j++) {
            ll t1 = dis(a[i][j], b[j]), t2 = dis(a[i][j + 1], b[j + 1]);
            if (a[i][j] != b[j] && t1 == t2) cnt2++, pos = j;
        }
        if (cnt2 != 1) return 0;
        for (ll j = 1; j <= 5; j++) {
            if (j != pos && j != pos + 1 && a[i][j] != b[j]) return 0;
        }
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= 5; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= 5; i++) b[i] = a[1][i];
    for (ll i = 1; i <= 5; i++) {
        for (ll j = 0; j <= 9; j++) {
            if (b[i] == j) continue;
            b[i] = j;
            if (check()) ans++;
            b[i] = a[1][i];
        }
    }
    for (ll i = 1; i < 5; i++) {
        for (ll j = 0; j <= 9; j++) {
            if (b[i] == j) continue;
            b[i] = j;
            b[i + 1] = (b[i + 1] + j) % 10;
            if (check()) ans++;
            b[i] = a[1][i];
            b[i + 1] = a[1][i + 1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
