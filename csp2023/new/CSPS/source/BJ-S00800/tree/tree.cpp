// O(nlog^2n), 别卡我别卡我别卡我
#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 100005;
struct edge {
    int to, next;
} e[MAXN*2];
int head[MAXN], last;
struct node {
    LL a;
    int b, c;
} val[MAXN];
struct node2 {
    int id;
    int limit;
} a[MAXN];
int n, fa[MAXN], limit[MAXN];
bool vis[MAXN];

inline void Insert(int u, int v) {
    ++last;
    e[last].next = head[u];
    head[u] = last;
    e[last].to = v;
}

void DFS(int x, int f) {
    fa[x] = f;
    for(int i = head[x]; ~i; i = e[i].next) {
        int v = e[i].to;
        if(v != f)
            DFS(v, x);
    }
}

bool check(LL a, int b, int c, int x, int y) {
    LL a1 = b + 1LL*c*x, an = b + 1LL*c*y;
    if(an >= 1)
        return (a*2 - 1)/(y - x + 1) + 1 <= (a1 + an);
    if(a1 < 1)
        return a <= y - x + 1;
    // assert(c < 0);
    int z = x + (a1 - 1)/(-c); //最后一个不用与1取max的时间
    // assert(x <= z && z < y);
    int az = b + 1LL*c*z;
    return ((a - (y - z))*2 - 1)/(z - x + 1) + 1 <= (a1 + az);
}

int calc(LL a, int b, int c, int x) {
    int l = 1, r = x;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(a, b, c, mid, x))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

inline bool cmp(const node2& x, const node2& y) {
    return x.limit < y.limit;
}

bool check(int x) {
    for(int i = 1; i <= n; ++i) {
        a[i].id = i;
        a[i].limit = calc(val[i].a, val[i].b, val[i].c, x);
        // std::cout << a[i].limit << ' ';
    }
    std::sort(a + 1, a + n + 1, cmp);
    int now = 0;
    memset(vis, 0, sizeof(bool)*(n + 1));
    vis[0] = 1;
    for(int i = 1; i <= n; ++i) {
        int v = a[i].id;
        while(!vis[v])
            vis[v] = 1, v = fa[v], ++now;
        if(now > a[i].limit)
            return 0;
    }
    return 1;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(head, -1, sizeof(head));
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
        std::cin >> val[i].a >> val[i].b >> val[i].c;
    for(int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        Insert(u, v), Insert(v, u);
    }
    DFS(1, 0);
    int l = 1, r = 1000000000;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << l;
    return 0;
}