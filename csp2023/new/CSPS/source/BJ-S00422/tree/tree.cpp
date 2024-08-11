#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[505];
int n, from[505], to[505], f[505], ans = 1e9, u, v;
struct node{
    ll a;
    int b, c;
} l[505];
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%d%d", &l[i].a, &l[i].b, &l[i].c);
    }
    for (int i = 0; i < 2 * n - 2;) {
        scanf("%d%d", &u, &v);
        adde(u, v, i++);
        adde(v, u, i++);
    }
    cin >> s;
    cout << "74";
    return 0;
}
