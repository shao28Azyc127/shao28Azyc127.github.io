#include <bits/stdc++.h>
const int MAXN = 100005;
int n, m;
int fa[MAXN*4], last[MAXN], tot;

int Find(int x) {
    if(fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}

void Merge(int x, int y) {
    if(Find(x) != Find(y))
        fa[Find(y)] = Find(x);
}

void connect(int x, int y, bool d) {
    //std::cout << tot << ' ' << y << ' ' << d << '\n';
    Merge(x, y ^ d);
    Merge(x ^ 1, y ^ d ^ 1);
}

void solve() {
    std::cin >> n >> m;
    for(int i = 0; i < (n + m)*2; ++i)
        fa[i] = i;
    for(int i = 0; i < n; ++i)
        last[i + 1] = i*2;
    tot = n*2;
    int id[2] = {};
    while(m--) {
        char opt;
        int x, y;
        std::cin >> opt >> x;
        if(opt == '+' || opt == '-') {
            std::cin >> y;
            connect(tot, last[y], opt == '+' ? 0 : 1);
        }
        else {
            if(opt == 'U')
                Merge(tot, tot ^ 1);
            else {
                int t = (opt == 'T' ? 0 : 1);
                if(id[t])
                    connect(tot, id[t], 0);
                if(id[t ^ 1])
                    connect(tot, id[t ^ 1], 1);
                id[t] = tot;
            }
        }
        last[x] = tot, tot += 2;
    }
    for(int i = 1; i <= n; ++i)
        connect(i*2 - 2, last[i], 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(Find(last[i]) == Find(last[i] ^ 1))
            ++ans;
    std::cout << ans << '\n';
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int sid, T;
    std::cin >> sid >> T;
    while(T--)
        solve();
    return 0;
}