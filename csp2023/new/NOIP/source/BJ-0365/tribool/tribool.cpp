#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1e5 + 5;
//T2
int c, T;
int n, m, a[N], fa[2*N];
bool vis[2*N], vis2[2*N];
void init() {
    for(int i = 1; i <= 2*n+10; i++) fa[i] = i;
}
int fd(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = fd(fa[x]);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) a[i] = i;
        for(int i = 1; i <= m; i++) {
            char opt;
            int x, y;
            cin >> opt;
            if(opt == '-') {
                scanf("%d%d", &x, &y);
                a[x] = -a[y];
            } else if (opt == '+') {
                scanf("%d%d", &x, &y);
                a[x] = a[y];
            } else {
                scanf("%d", &x);
                if (opt == 'T') a[x] = n+1;
                else if (opt == 'F') a[x] = n+2;
                else a[x] = n+3;
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis2));
        init();
        for(int i = 1; i <= n; i++) {
            if (a[i] == n+3) {
                vis[i] = vis[n+i] = 1;
            } else {
                int fx, fy, fz, ft;
                if (a[i] < 0) {
                    a[i] = -a[i];
                    fx = fd(i), fy = fd(n+a[i]), fz = fd(a[i]), ft = fd(i+n);
                    if (fx == fz || fy == ft) {
                        vis[i] = vis[a[i]] = vis[i+n] = vis[n+a[i]] = 1;
                    } else {
                        fa[fx] = fy;
                        fa[fz] = ft;
                    }
                } else if (a[i] <= n) {
                    fx = fd(i), fy = fd(a[i]), fz = fd(a[i]+n), ft = fd(i+n);
                    if (fx == fz || fy == ft) {
                        vis[i] = vis[a[i]] = vis[i+n] = vis[n+a[i]] = 1;
                    } else {
                        fa[fx] = fy;
                        fa[fz] = ft;
                    }
                }
            }
        }
        LL cnt = 0;
        for(int i = 1; i <= 2*n; i++) {
            if (vis[i]) {
                vis2[fd(i)] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            if (vis2[fd(i)] == 1 || vis2[fd(i+n)] == 1) cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
