#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e6;

ll c, t, n, m;



int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
        for (ll i = 1;i <= t; i ++){
            cin >> n >> m;
            ll ans = 0;
            char a[MaxN];
            memset(a, ' ', sizeof(a));
            for (ll j = 1;j <= m;j ++){
                ll x, y;
                char op;
                cin >> op >> x;
                if (op == '+'){
                    cin >> y;
                    if (a[x] == 'U' && a[y] != 'U') ans --;
                    else if(a[x] != 'U' && a[y] == 'U') ans ++;
                    a[x] = a[y];
                }else if(op == '-'){
                    cin >> y;
                    if (a[x] == 'U' && a[y] != 'U') ans --;
                    else if(a[x] != 'U' && a[y] == 'U') ans ++;
                    if (a[y] == 'U') a[x] = 'U';
                    else if(a[y] == 'T') a[x] == 'F';
                    else if(a[y] == 'F') a[x] == 'T';

                }else if(op == 'T'){
                    if (a[x] == 'U') cout << "ooo", ans --;
                    a[x] = 'T';
                }else if(op == 'F'){
                    if (a[x] == 'U') cout << "nnn", ans --;
                    a[x] = 'F';
                }else if(op == 'U'){
                    if (a[x] != 'U') ans ++;
                    a[x] = 'U';
                }
            }

            cout << ans << endl;
        }

    return 0;
}
