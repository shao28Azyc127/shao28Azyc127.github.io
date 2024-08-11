#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e3 + 5;
int n, m, d[26];
struct Node {
    string t, p, e;
    int k;
} c[N], q[N];
bool operator<(Node x, Node y) {
    return x.e < y.e;
}
inline string _sort(string s) {
    memset(d, 0, sizeof(d));
    for(auto i : s) d[i - 'a' + 1]++;
    string r = "";
    for(int i = 1; i <= 26; i++) 
        for(int j = 1; j <= d[i]; j++)
            r += char(i + 'a' - 1);
    return r;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin>>n>>m;
    if(n == 1) {
        cout<<1<<endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        c[i].k = i;
        cin>>c[i].t;
        c[i].p = c[i].e = c[i].t;
        // sort(c[i].p.begin(), c[i].p.end());
        c[i].p = _sort(c[i].p);
        for(int x = 0, y = m - 1; x < m && y >= 0; x++, y--)
            c[i].e[x] = c[i].p[y];  
        q[i] = c[i];
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        if(q[i].k != c[1].k) {
            if(q[i].p < c[1].e) cout<<1;
            else cout<<0;
        } else {
            if(q[i].p < c[2].e) cout<<1;
            else cout<<0;
        }
    }
    return 0;
}