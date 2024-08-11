// rui_er is kawaii!!!
// finished at 18:16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

#ifndef RUIER
ifstream fin("tree.in");
ofstream fout("tree.out");
#define cin fin
#define cout fout
#endif

const int N = 1e5 + 5, lim = 1e9 + 2;
const ll inf = 2e18;

int n, U[N], V[N], deg[N], mustBefore[N];

struct Land {
    ll a, b, c;
    Land(ll a = 0, ll b = 0, ll c = 0) : a(a), b(b), c(c) {}
    friend istream& operator>>(istream& in, Land& land) {
        in >> land.a >> land.b >> land.c;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Land& land) {
        out << land.a << " " << land.b << " " << land.c;
        return out;
    }
    i128 delta(int day) const {
        return max((i128)1, b + (i128)day * c);
    }
    i128 calc(int l, int r) const {
        return (delta(l) + delta(r)) * (r - l + 1) / 2;
    }
    i128 sum(int l, int r) const {
        if(c >= 0) return calc(l, r);
        else {
            ll daysGreaterThanOne = (1 - b) / c;
            if(r <= daysGreaterThanOne) return calc(l, r);
            else if(l > daysGreaterThanOne) return r - l + 1;
            else return calc(l, daysGreaterThanOne) + (r - daysGreaterThanOne);
        }
    }
}land[N];

vector<int> e[N];

bool dfs_calc(int u, int f, int day) {
    if(u == 1) mustBefore[u] = 1;
    else {
        int l = 0, r = day;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(land[u].sum(mid, day) < land[u].a) r = mid - 1;
            else l = mid;
        }
        mustBefore[u] = r;
        if(mustBefore[u] == 0) return false;
    }
    for(int v : e[u]) {
        if(v != f) {
            if(!dfs_calc(v, u, day)) return false;
            mustBefore[u] = min(mustBefore[u], mustBefore[v] - 1);
            if(mustBefore[u] <= 0) return false;
        }
    }
    return true;
}

inline bool check(int day) {
    if(land[1].sum(1, day) < land[1].a) return false;
    if(!dfs_calc(1, 0, day)) return false;
    sort(mustBefore + 1, mustBefore + 1 + n);
    for(int i = 1; i <= n; ++i) {
        if(mustBefore[i] < i) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> land[i];
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int l = n, r = lim;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    cout.flush();
    return 0;
}

/*

Special B:

6
5 1 -10
7 5 -1
4 1 0
3 1 2
9 3 2
2 1 -1
1 2
2 3
3 4
4 5
5 6

need days : 5 5 6 4 5 7
ans = 7

Special A:

(tree2.in / tree2.ans)

Special A && D:

6
100 1 0
1 1 0
1 1 0
1 1 0
1 1 0
1 1 0
1 2
1 3
1 4
1 5
1 6

ans = 100

Special D:

6
5 1 1
4 3 1
4 1 2
4 1 -1
4 7 -4
10 50 -20
1 2
1 3
1 4
1 5
1 6

order = 1 6 5 4 3 2
ans = 7

*/