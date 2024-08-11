#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e5 + 5;
ll c, t = 1, n, m, d, k, book1[MaxN], book2[MaxN], book3[MaxN], book4[MaxN];

struct Node{
    ll x, y, v, z1, z2;
    bool isc = true;
}a[MaxN];

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    for (ll q = 1;q <= t;q ++){
        ll x[MaxN], y[MaxN], v[MaxN], ans = 0, dk = 0, day;
        cin >> n >> m >> k >> d;
        for (ll i = 1;i <= m;i ++){
            cin >> a[i].x >> a[i].y >> a[i].v;
            a[i].z1 = a[i].v - (a[i].y * d);
            a[i].z2 = a[i].v - (k * d);
            if (a[i].x < a[i].y || a[i].z1 < 0 || a[i].y > k) a[i].isc = false;

            if (a[i].isc && (a[i].x - k + 1) >= 1){
                for (ll h = a[i].x - k + 1; h <= a[i].x - a[i].y + 1; h ++) {
                    book1[h] += a[i].z1 - ((a[i].x - a[i].y + 1) - h) * d ;
                    if (book2[h] > 0){
                        if (book3[h] > a[i].y) book1[h] += a[i].y;
                        else if(book3[h] <= a[i].y) book1[h] += book3[h];
                    }
                    book2[h] ++;
                    book3[h] = a[i].y;
                }
            }
        }
        for (ll j = 1;j <= n; j ++) {
            if (book1[j] != 0) {
                book4[j] = book1[j];
                for (ll h = j + 1; h <= j + d; h ++){
                    book4[j] -= book1[h];
                }
            }
            if (book4[j] > 0) ans += book1[j] ,j += d;
        }
        cout << ans << endl;
    }

    return 0;
}
