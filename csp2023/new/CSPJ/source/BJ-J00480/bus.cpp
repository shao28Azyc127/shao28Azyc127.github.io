#include <bits/stdc++.h>
using namespace std;

struct node {
    int v, t;
};
vector<node> gh[20005];
int n, m, k;
queue<pair<int, int>> q;
vector<int> ans;

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        node tmp = {v, a};
        gh[u].push_back(tmp);
    }
    q.push({1, 0});
    while (!q.empty()) {
        int pos = q.front().first, cnt = q.front().second;
        q.pop();
        if (pos == n) {
            ans.push_back(cnt);
            continue;
        }
        for (node i : gh[pos]) {
            q.push({i.v, cnt+1});
        }
    }
    int minst = INT_MAX;
    for (int i : ans) {
        if (i % k == 0 && i < minst)
            minst = i;
    }
    cout << (minst == INT_MAX ? -1 : minst) << endl;
    return 0;
}