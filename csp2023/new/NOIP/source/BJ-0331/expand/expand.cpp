#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int c, n, m, q;

int x[500001];
int y[500001];
int tx[500001];
int ty[500001];

int stx[11];
int sty[11];
int ttx[11];
int tty[11];
bool dfs(int d, int lx, int ly) {
    if(d > n && d > m) {
        int f = tx[n] - ty[m];
        if(f > 0) f = 1;
        else f = -1;
        stx[n] = sty[m] = n * n + m * m;
        memcpy(ttx, stx, sizeof(ttx));
        memcpy(tty, sty, sizeof(tty));
        int opt[101] = {};
        for(int i = 1, j = 1, t = 1;t <= lx || t <= ly;t++) {
            --ttx[i];
            --tty[j];
            if((tx[i] - ty[j]) * f <= 0) return false;
            opt[t] = tx[i] - ty[j];
            if(i == n && j == m) break;
            if(ttx[i] == 0) i++;
            if(tty[j] == 0) j++;
        }/*
        printf("\n{");
        for(int i = 1;i <= n;i++) printf("%lld,", stx[i]);
        printf("}\n{");
        for(int i = 1;i <= m;i++) printf("%lld,", sty[i]);
        printf("}\n{");
        for(int i = 1;i <= lx && i <= ly;i++) printf("%lld,", opt[i]);
        printf("}");*/
        return true;
    }
    if(d == 1 && x[n] == y[m]) return false;
    for(int i = 1;i <= n;i++) {
        if(lx + i > n * 2) break;
        stx[d] = i;
        for(int j = 1;j <= m;j++) {
            if(ly + j > m * 2) break;
            sty[d] = j;
            if(dfs(d + 1, lx + i, ly + j)) return true;
        }
    }
    return false;
}

struct Node {
    int v, i;

    Node(int x = 0, int y = 0) {
        v = x;
        i = y;
    }

    friend bool operator < (Node A, Node B) {
        return A.v < B.v || A.v == B.v && A.i > B.i;
    }
};

//set<int> s;

bool check() {
    bool flag = true;
    for(int j = 1;j <= n;j++) {
        if(tx[j] >= ty[m]) {
            flag = false;
            break;
        }
    }
    for(int j = 1;j <= m;j++) {
        if(tx[n] >= ty[j]) {
            flag = false;
            break;
        }
    }
    if(!flag) return false;
    for(int i = 1, r = 0;i <= m;i++) {
        while(r < n && tx[r + 1] < ty[i]) {
            r++;
        }
        if(r == n) return true;

    }
    return false;
}

signed main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if(c == 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d", (x != y));
        for(int i = 1, kx, ky, tx, ty, p, v;i <= q;i++) {
            scanf("%d%d", &kx, &ky);
            tx = x;
            ty = y;
            if(kx) {
                scanf("%d%d", &p, &v);
                tx = v;
            }
            if(ky) {
                scanf("%d%d", &p, &v);
                ty = v;
            }
            printf("%d", (tx != ty));
        }
    } else if(c <= 4) {
        for(int i = 1;i <= n;i++) scanf("%d", &x[i]);
        for(int i = 1;i <= m;i++) scanf("%d", &y[i]);
        memcpy(tx, x, sizeof(x));
        memcpy(ty, y, sizeof(y));
        memset(stx, 0, sizeof(stx));
        memset(sty, 0, sizeof(sty));
        printf("%d", dfs(1, 0, 0));
        for(int i = 1, kx, ky, p, v;i <= q;i++) {
            memcpy(tx, x, sizeof(x));
            memcpy(ty, y, sizeof(y));
            memset(stx, 0, sizeof(stx));
            memset(sty, 0, sizeof(sty));
            scanf("%d%d", &kx, &ky);
            while(kx--) {
                scanf("%d%d", &p, &v);
                tx[p] = v;
            }
            while(ky--) {
                scanf("%d%d", &p, &v);
                ty[p] = v;
            }
            printf("%d", dfs(1, 0, 0));
        }
    } else {
        for(int i = 1;i <= n;i++) scanf("%d", &x[i]);
        for(int i = 1;i <= m;i++) scanf("%d", &y[i]);
        memcpy(tx, x, sizeof(x));
        memcpy(ty, y, sizeof(y));
        printf("%d", check());
        for(int i = 1, kx, ky, p, v;i <= q;i++) {
            memcpy(tx, x, sizeof(x));
            memcpy(ty, y, sizeof(y));
            scanf("%d%d", &kx, &ky);
            while(kx--) {
                scanf("%d%d", &p, &v);
                tx[p] = v;
            }
            while(ky--) {
                scanf("%d%d", &p, &v);
                ty[p] = v;
            }
            printf("%d", check());
        }
    }
    return 0;
}
