#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int c, n, m, q, x[N], y[N], xx[N], yy[N];
bool judge() {
    if(n == 1 && m == 1) return xx[1] != yy[1];
    else if(n == 2 && m == 2) {
        if(xx[1] < yy[1] && xx[2] < yy[2]) return 1;
        if(xx[1] > yy[1] && xx[2] > yy[2]) return 1;
        return 0;
    } else if(n == 1 && m == 2) {
        if(xx[1] < yy[1] && xx[1] < yy[2]) return 1;
        if(xx[1] > yy[1] && xx[1] > yy[2]) return 1;
        return 0;
    } else if(n == 2 && m == 1) {
        if(xx[1] < yy[1] && xx[2] < yy[1]) return 1;
        if(xx[1] > yy[1] && xx[2] > yy[1]) return 1;
        return 0;
    }
    return rand() % 2;
}
signed main() {
    srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout); 
    cin>>c>>n>>m>>q;
    for(int i = 1; i <= n; i++) cin>>x[i];
    for(int i = 1; i <= m; i++) cin>>y[i];
    for(int i = 1; i <= n; i++) xx[i] = x[i];
    for(int i = 1; i <= m; i++) yy[i] = y[i];
    cout<<judge();
    while(q--) {
        for(int i = 1; i <= n; i++) xx[i] = x[i];
        for(int i = 1; i <= m; i++) yy[i] = y[i];
        int k1, k2;
        cin>>k1>>k2;
        while(k1--) {
            int p, v;
            cin>>p>>v;
            xx[p] = v;
        }
        while(k2--) {
            int p, v;
            cin>>p>>v;
            yy[p] = v;
        }
        cout<<judge();
    }
    return 0;
}