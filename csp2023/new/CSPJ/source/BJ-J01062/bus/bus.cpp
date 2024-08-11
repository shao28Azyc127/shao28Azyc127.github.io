#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<int> mp[10005];
int a[10005][10005];

bool bfs(int st) {
    int u, t;
    queue<int> q;
    queue<long long> qt;
    q.push(1), qt.push(st);

    while (!q.empty()) {
        u=q.front(), q.pop();
        t=qt.front(), qt.pop();

        if (u == n) {
            if (t%k == 0) {
                printf("%lld\n", t);
                return 0;
            }
            continue;
        }

        for (auto v : mp[u]) {
            if (t >= a[u][v]) {
                q.push(v);
                qt.push(t+1);
            }
        }
    }

    return 1;
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int u, v, ta;

    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d%d", &u, &v, &ta);
        mp[u].emplace_back(v);
        a[u][v]=ta;
    }

    bool flag=0;
    for (int i=0; i<=10000; i+=k) {
        if (!bfs(i)) {
            flag=1;
            break;
        }
    }

    if (!flag) printf("-1\n");
    return 0;
}
