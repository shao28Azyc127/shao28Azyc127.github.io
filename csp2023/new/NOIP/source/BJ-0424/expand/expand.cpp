#include <bits/stdc++.h>
using namespace std;

int c, n, m, q, x[500010], y[500010], kx, ky, p, v;

int main(){
//    freopen("a.in", "r", stdin);
//    freopen(".out", "w", stdout);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) cin >> y[i];
    if(c == 1){
        cout << (x[1] != y[1]);
        while(q--){
            cin >> kx >> ky;
            while(kx--){
                cin >> p >> v;
                x[p] = v;
            }
            while(ky--){
                cin >> p >> v;
                y[p] = v;
            }
            cout << (x[1] != y[1]);
        }
        return 0;
    }
    if(c == 2){
        cout << ((x[1] - y[1]) * (x[2] - y[2]) > 0);
        while(q--){
            cin >> kx >> ky;
            while(kx--){
                cin >> p >> v;
                x[p] = v;
            }
            while(ky--){
                cin >> p >> v;
                y[p] = v;
            }
            cout << ((x[1] - y[1]) * (x[2] - y[2]) > 0);
        }
        return 0;
    }
    cout << (x[1] != y[1] && x[n] != y[n] && ((x[1] - y[1]) * (x[n] - y[n]) > 0));
    while(q--){
        cin >> kx >> ky;
        while(kx--){
            cin >> p >> v;
            x[p] = v;
        }
        while(ky--){
            cin >> p >> v;
            y[p] = v;
        }
        cout << (x[1] != y[1] && x[n] != y[n] && ((x[1] - y[1]) * (x[n] - y[n]) > 0));
    }
    return 0;
}

