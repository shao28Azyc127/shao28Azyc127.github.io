#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define put(x) printf("%d ", x)
#define putl(x) printf("%lld ", x)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, k = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c & 15), c = getchar();
    return x * k;
}

const int N = 1e6 + 10;

int a[10], n, ans;
int s[10][10];
set<int> mp;

int d[10];
bool check(int a[10], int b[10]) {
    rep(i, 1, 5) d[i] = (a[i] - b[i] + 10) % 10;
    int cnt = 0;
    rep(i, 1, 5) if(d[i]) cnt ++;
    if(cnt == 0) return 0;
    if(cnt == 1) return 1;
    if(cnt >= 3) return 0;
    int p = 0;
    rep(i, 1, 5) if(d[i]) p = i;
    rep(i, 1, 5) if(d[i] == d[p] && i != p) return abs(p - i) == 1;
    return 0;
}

int hsh() {
    int res = 0;
    rep(i, 1, 5) res = res * 10 + a[i];
    return res;
}

void solve() {
    int x = hsh();
    if(mp.count(x)) return;
    bool flag = 1;
    rep(i, 1, n) flag &= check(a, s[i]);
    if(!flag) return;
    ans ++;
    mp.insert(x);
    //    rep(j, 1, 5) put(a[j]); endl();
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    n = read();
    rep(i, 1, n) rep(j, 1, 5) s[i][j] = read();
    rep(i, 1, 1) {
        rep(j, 1, 5) a[j] = s[i][j];
        rep(j, 1, 5) rep(k, 0, 9) {
            a[j] = (a[j] + k) % 10;
            solve();
            a[j] = (a[j] - k + 10) % 10;
        }
        rep(j, 1, 4) rep(k, 0, 9) {
            a[j] = (a[j] + k) % 10;
            a[j+1] = (a[j+1] + k) % 10;
            solve();
            a[j] = (a[j] - k + 10) % 10;
            a[j+1] = (a[j+1] - k + 10) % 10;
        }
    }
    put(ans);
    return 0;
}

