#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e6 + 5;
ll c, n, m, q;

ll x[MaxN], y[MaxN], x1[MaxN];
ll k1[MaxN];
bool query(){
    for (ll i = 1;i <= n;i ++){
        if (x1[i] == k1[i]) return false;
    }
    return true;
}

void init(){
    for (ll i = 1; i <= n;i ++){
        x1[i] = x[i];
        k1[i] = y[i];
    }
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (ll i = 1;i <= n;i ++) cin >> x[i];
    for (ll i = 1;i <= n;i ++) cin >> y[i];
    ll a, b;
    init();
    cout << query();
    for (ll i = 1;i <= q;i ++){
        init();
        cin >> a >> b;
        ll w, e;
        for (ll j = 1;j <= a;j ++){
            cin >> w >> e;
            x1[w] = e;
        }
        for (ll j = 1;j <= b;j ++){
            cin >> w >> e;
            k1[w] = e;
        }
        cout << query();
    }
    return 0;
}
