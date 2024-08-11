#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#define int long long
#define maxn 100005 //1e5+5
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int n, a[maxn], b[maxn], c[maxn], h[maxn], d[maxn], en, u, v, deg1;

struct edge {
    int u, v, next;
} e[maxn * 2];
void add(int u, int v) {
    e[en] = (edge) {u, v, h[u]};
    h[u] = en++;
}

int sum(int i, int l, int r) {
    if(c[i] == 0) return b[i] * (r - l + 1);
    else if(c[i] > 0) {
        int p = floor((-b[i]) / c[i]) + 1;
        if(l >= p) return (r - l + 1) * b[i] + (l + r) * (r - l + 1) / 2 * c[i];
        else if(p > r) return r - l + 1;
        else return (r - p + 1) * b[i] + (p + r) * (r - p + 1) / 2 * c[i] + p - l;
    }
    else {
        int p = (-b[i]) / c[i] - 1;
        if(r <= p) return (r - l + 1) * b[i] + (l + r) * (r - l + 1) / 2 * c[i];
        else if(p < l) return r - l + 1;
        else return (p - l + 1) * b[i] + (p + l) * (p - l + 1) / 2 * c[i] + r - p;
    }
}
multiset<int> s2;

void dfs(int r, int fa = 1) {
    int asn = 0x3f3f3f3f3f3f3f3fll;
    for(int j = h[r]; ~j; j = e[j].next) {
        int v = e[j].v;
        if(v == fa) continue;
        dfs(v, r);
        asn = min(asn, d[v]);
    }
    d[r] = min(asn - 1, d[r]);
}

bool check(int x) {
    //cout << x << endl;
    for(int i = 1; i <= n; i++) {
        int l = 0, r = x;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(sum(i, mid, x) >= a[i]) l = mid;
            else r = mid - 1;
        }
        d[i] = l;
        //cout << d[i] << ' ';
    }//cout << '\n';
    dfs(1);
    s2.clear();
    for(int i = 1; i <= n; i++) {
        s2.insert(d[i]);
    }
    int cnt = 0;
    for(int x : s2) {
        cnt++;
        if(cnt > x) return false;
    }
    return true;
}

signed main() {
    memset(h, 0xff, sizeof(h));
    fopen("tree");
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> u >> v; add(u, v); add(v, u);
        deg1 += (u == 1 || v == 1);
    }
    int l = 1, r = 1000000000;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}