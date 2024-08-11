#include<iostream>
#include<cstdio>
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int n, a[10][10], cnt[100005], nxt[105][10], nn, ans;

void add(int a, int b, int c, int d, int e) {
    nn++;
    nxt[nn][1] = a, nxt[nn][2] = b, nxt[nn][3] = c, nxt[nn][4] = d, nxt[nn][5] = e;
}

signed main() {
    fopen("lock");
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int j = 1; j <= 9; j++) {
        add(j, 0, 0, 0, 0);
        add(j, j, 0, 0, 0);
        add(0, j, 0, 0, 0);
        add(0, j, j, 0, 0);
        add(0, 0, j, 0, 0);
        add(0, 0, j, j, 0);
        add(0, 0, 0, j, 0);
        add(0, 0, 0, j, j);
        add(0, 0, 0, 0, j);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
        for(int j = 1; j <= nn; j++) {
            ans = 0;
            for(int k = 1; k <= 5; k++) {
                ans *= 10;
                ans += (a[i][k] + nxt[j][k]) % 10;
            }
            cnt[ans]++;
        }
    }
    ans = 0;
    for(int i = 0; i <= 99999; i++) {
        ans += (cnt[i] == n);
    }
    cout << ans << '\n';
}