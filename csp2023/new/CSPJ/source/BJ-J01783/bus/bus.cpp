// 100pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 9;
struct node {
    int v, w;
};
vector<node> G[N];
int n, m, k;
struct NODE {
    int u, tim;
};
bool operator < (const NODE &x, const NODE &y) {
    return (x.u == y.u ? x.tim < y.tim : x.u < y.u);
}
int d[N][109];
set<NODE> st;
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }
    memset(d, 0x3f, sizeof(d));
    d[1][0] = 0, st.insert({1, 0});
    while (!st.empty()) {
        int u = st.begin()->u, t = st.begin()->tim;
        st.erase(st.begin());
        for (auto e : G[u]) {
            int v = e.v, w = e.w, nw;
            if (w > t)
                nw = t + (w - t + k - 1) / k * k + 1;
            else nw = t + 1;
            if (d[v][nw % k] > nw) {
                st.erase({v, d[v][nw % k]});
                d[v][nw % k] = nw;
                st.insert({v, d[v][nw % k]});
            }
        }
    }
    printf("%d\n", d[n][0] > 1e9 ? -1 : d[n][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
