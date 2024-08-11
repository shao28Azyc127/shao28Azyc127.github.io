#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll v[MAXN], a[MAXN], pre[MAXN], d[MAXN];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, ds;
    cin >> n >> ds;
    for(ll i = 2; i <= n; i ++){
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    for(ll i = 1; i <= n; i ++){
        cin >> a[i];
    }
    ll ans = 0, now = 1;
    for(ll i = 2; i <= n; i ++){
        if(a[i] < a[now]){
            ll w = (pre[i] - pre[now] - d[now]) / ds;
            if(ds * w != (pre[i] - pre[now] - d[now]))w ++;
            ans += w * a[now];
            d[i] = w * ds - (pre[i] - pre[now] - d[now]);
  //          cout << i << " " << now << " " << pre[i] - pre[now] - d[now] << " " << d[now] << " " << d[i] << "\n";
            now = i;
        }
    }
    cout << ans;
    return 0;
}
