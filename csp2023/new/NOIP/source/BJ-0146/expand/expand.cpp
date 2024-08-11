# include <bits/stdc++.h>
# define int long long
# define maxn 10
using namespace std;
int c, n, m, q;
int a[maxn], b[maxn];
void sol1()
{
    cin >> a[1] >> b[1];
    if(a[1] == b[1]) cout << 0;
    else cout << 1;
    while(q--){
        int kx, ky;
        cin >> kx >> ky;
        for(int i = 1; i <= kx; i++){
            int px, vx;
            cin >> px >> vx;
            a[px] = vx;
        }
        for(int i = 1; i <= ky; i++){
            int py, vy;
            cin >> py >> vy;
            b[py] = vy;
        }
        if(a[1] == b[1]) cout << 0;
        else cout << 1;
    }
}
void sol2()
{
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    int bga, eda, bgb, edb;
    bga = a[1], eda = a[n], bgb = b[1], edb = b[m];
    cout << ((bga < bgb && eda < edb) || (bga > bgb && eda > edb));
    while(q--){
        int kx, ky;
        cin >> kx >> ky;
        for(int i = 1; i <= kx; i++){
            int px, vx;
            cin >> px >> vx;
            a[px] = vx;
        }
        for(int i = 1; i <= ky; i++){
            int py, vy;
            cin >> py >> vy;
            b[py] = vy;
        }
        bga = a[1], eda = a[n], bgb = b[1], edb = b[m];
        cout << ((bga < bgb && eda < edb) || (bga > bgb && eda > edb));
    }
}
signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> q;
    if(c == 1){
        sol1();
    }
    if(c == 2){
        sol2();
    }
    return 0;
}
/*
this problem is so difficult so that i can only get 10 pts.
*/
