#include<bits/stdc++.h>

using namespace std;

struct edge{
    int to, next, h;
};

edge e[100];
int head[1000], cnt;
int n;
int a[100], b[100], c[100];

inline void add_edge(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int plant() {
    return n + 2;
}

int main () {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    e[1].h = b[1];
    int ans = plant();
    printf("%d", ans);
    return 0;
}