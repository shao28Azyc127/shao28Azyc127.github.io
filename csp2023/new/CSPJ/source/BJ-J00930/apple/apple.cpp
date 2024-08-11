#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, t = 0, p, tmp=3;
    bool vis[1000000005];
    cin >> n;
    while(n) {
        t++;
        for (int i=1; i<=n; i++) {
            if (vis[i])continue;
            if (tmp == 3) {
                if (i == n) p = t;
                vis[i] = true;
                tmp = 0;
            }
            tmp++;
        }
    }
    cout << t << p;
    return 0;
}
