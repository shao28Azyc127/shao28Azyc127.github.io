#include<cstdio>
#include<cstring>
using namespace std;
#define NT 131072
#define T 100001
#define U 100002
#define F 231073
int val[231075];
int fa[231075];
int find(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
    fa[find(x)] = find(y);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int t;
    scanf("%*d%d", &t);
    while (t--) {
        memset(fa, 0, sizeof(fa));
        memset(val, 0, sizeof(val));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            fa[i ^ NT] = i ^ NT;
            val[i] = i;
            val[i ^ NT] = i ^ NT;
        }
        fa[T] = T;
        fa[F] = F;
        fa[U ^ NT] = fa[U] = U;
        while (m--) {
            char v;
            int i, j;
            scanf(" %c", &v);
            if (v == 'T') {
                scanf("%d", &i);
                val[i] = T;
            } else if (v == 'U') {
                scanf("%d", &i);
                val[i] = U;
            } else if (v == 'F') {
                scanf("%d", &i);
                val[i] = F;
            } else if (v == '+') {
                scanf("%d%d", &i, &j);
                val[i] = val[j];
            } else if (v == '-') {
                scanf("%d%d", &i, &j);
                val[i] = val[j] ^ NT;
            }
        }
        for (int i = 1; i <= n; ++i) {
            merge(i, val[i]);
            merge(i ^ NT, val[i] ^ NT);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (find(i) == find(i ^ NT)) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}