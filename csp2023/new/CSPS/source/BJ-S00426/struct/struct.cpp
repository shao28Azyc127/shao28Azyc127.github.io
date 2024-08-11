#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 9;  // !!!!
const int K = 104;
int n, op, k, cur = 1, rcur = 0;
// cursor for all nodes, cursor for root
string s, type[K], name[K];
map<string, int> m;  // which son is struct xxx in
struct Node {
    int type, bar;
    ll start, sz;
    string name;
};
vector<Node> v;  // information
vector<int> G[N];   // index only
ll makest(ll &x, int bar, bool changestart) {
    if (x == 0) {
        x = bar;
        return 0;
    }
    ll ret = (x - 1) / bar * bar + bar;
    if (changestart) x = (x - 1) / bar * bar + 2 * bar;
    return ret;
}
void dfs(int x, int xfrom, int from) {
    for (int i = 0; i < G[x].size(); ++i) {
        if (G[x][i] != from) {
            G[0].push_back(cur);
            G[cur++].push_back(0);
            dfs(G[x][i], x);
        }
    }
}
void dupestruct(int root, int id, ll &start) {
    v.push_back({0, v[G[0][id]].bar, start, v[G[0][id]].sz, v[G[0][id]].name});
    dfs(G[0][id], 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    v.push_back({0, 0, 0, 0, ""});  // root
    for (int i = 1; i <= n; ++i) {
        cin >> op;
        if (op == 1) {  // define a struct
            int tbar = 0, tsz = 0;
            cin >> s >> k;
            m[s] = rcur++;
            G[0].push_back(cur);
            G[cur++].push_back(0);
            for (int j = 1; j <= k; ++j) {
                cin >> type[j] >> name[j];
                if (type[j] == "byte") tbar = max(tbar, 1);
                else if (type[j] == "short") tbar = max(tbar, 2);
                else if (type[j] == "int") tbar = max(tbar, 4);
                else if (type[j] == "long") tbar = max(tbar, 8);
                else tbar = max(tbar, v[G[0][rcur-2]].bar);
            }
            ll start = v[G[0][rcur-2]].start + v[G[0][rcur-2]].sz;
            ll tstart = makest(start, tbar, 0);
            start = tstart;
            for (int j = 1; j <= k; ++j) {
                if (type[j] == "byte") {
                    G[0].push_back(cur);
                    G[cur++].push_back(0);
                    v.push_back({1, 1, makest(start, 1, 1), 1, name[j]});
                } else if (type[j] == "short") {
                    tbar = max(tbar, 2);
                    G[0].push_back(cur);
                    G[cur++].push_back(0);
                    v.push_back({2, 2, makest(start, 2, 1), 2, name[j]});
                } else if (type[j] == "int") {
                    tbar = max(tbar, 4);
                    G[0].push_back(cur);
                    G[cur++].push_back(0);
                    v.push_back({3, 4, makest(start, 4, 1), 4, name[j]});
                } else if (type[j] == "long") {
                    tbar = max(tbar, 8);
                    G[0].push_back(cur);
                    G[cur++].push_back(0);
                    v.push_back({4, 8, makest(start, 8, 1), 8, name[j]});
//                } else {
//                    tbar = max(tbar, v[G[0][m[name[j]]].bar);
//                    G[0].push_back(cur);
//                    G[cur++].push_back(0);
//                    dupestruct(0, m[name[j]], start);
                }
            }
            cout << tsz << " " << tbar << endl;
            v.push_back({0, tbar, tstart, tsz, s});
        } else if (op == 2) {
            int tbar = 0, tsz = 0;
            string type, name;
            cin >> type >> name;
            m[name] = rcur++;
            ll start = v[G[0][rcur-2]].start + v[G[0][rcur-2]].sz;
            bool flag = true;
            if (start == 0) cout << 0 << endl, flag = false;
            if (type == "byte") {
                G[0].push_back(cur);
                G[cur++].push_back(0);
                v.push_back({1, 1, makest(start, 1, 1), 1, name});
            } else if (type == "short") {
                tbar = max(tbar, 2);
                G[0].push_back(cur);
                G[cur++].push_back(0);
                v.push_back({2, 2, makest(start, 2, 1), 2, name});
            } else if (type == "int") {
                tbar = max(tbar, 4);
                G[0].push_back(cur);
                G[cur++].push_back(0);
                v.push_back({3, 4, makest(start, 4, 1), 4, name});
            } else if (type == "long") {
                tbar = max(tbar, 8);
                G[0].push_back(cur);
                G[cur++].push_back(0);
                v.push_back({4, 8, makest(start, 8, 1), 8, name});
//                } else {
//                    tbar = max(tbar, v[G[0][m[name]].bar);
//                    G[0].push_back(cur);
//                    G[cur++].push_back(0);
//                    dupestruct(0, m[name], start);
            }
        } else if (op == 3) {
        } else if (op == 4) {
        }
    }
    return 0;
}
