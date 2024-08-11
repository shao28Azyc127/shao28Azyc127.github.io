#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

vector<int> e[10100];
vector<int> a[10100];
int versions[10100][100];
int k, n, m;
int q[1010000];
int qtail, qhead;
int version = 0;
int check(int end_time) {
    ++version;
    versions[n - 1][end_time % k] = version;

    qtail = 2;
    qhead = 0;
    q[0] = n - 1;
    q[1] = -1;
    int dis = 0;
    while (qhead < qtail) {
        if (q[qhead] < 0) {
            ++dis;
            q[qtail++] = -1;
            ++qhead;
            continue;
        }
        int x = q[qhead];
        ++qhead;
        if (x == 0 && dis % k == 0) return end_time - dis;
        for (int i = 0; i < e[x].size(); ++i) {
            int y = e[x][i];
            int new_t = (dis + k - 1) % k;
            if (versions[y][new_t] == version) continue;
            versions[y][new_t] = version;

            int start_time = end_time - dis - 1;
            if (start_time < a[x][i]) continue;

            q[qtail++] = y;
        }
    }
    return -1;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v, ax;
        cin >> u >> v >> ax;
        e[v - 1].push_back(u - 1);
        a[v - 1].push_back(ax);
    }
    int l = 0, r = 2030001 / k;
    bool ok = false;
    while (r - l > 1) {
        // cout << l << " " << r << endl;
        int c = (r + l) / 2;
        int result = check(c * k);
        if (result < 0) {
            l = c;
        } else {
            ok = true;
            r = c;
        }
    }
    if (!ok) cout << -1 << endl;
    else cout << r * k << endl;
    return 0;
}
