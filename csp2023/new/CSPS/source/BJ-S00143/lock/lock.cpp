#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 15;
const int M = 8;
int n;
int a[N][M];
int b[M];
int ans = 0;
void dfs(int u) {
    if(u == 6) {
        int lst = 0;
        int pos = 0;
        int now = 0;
        bool ok = 1;
        for(int i = 1; i <= n; i++) {
            lst = 0, pos = 0, now = 0;
            for(int j = 1; j <= 5; j++) {
                now = b[j] - a[i][j];
                if(now < 0) {
                    now += 10;
                }
                if(now != 0) {
                    if(pos == 0) {
                        pos = j;
                        lst = now;
                    } else if(pos == j - 1 && lst == now) {
                        pos = -1;
                    } else {
                        ok = false;
                    }
                }
            }
            if(pos == 0) {
                ok = false;
            }
        }
        if(ok) {
            ans++;
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        b[u] = i;
        dfs(u + 1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
