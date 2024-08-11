#include <bits/stdc++.h>
using namespace std;

long long n, a[100010], b[100010], mi, dis, ans, s, d;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    mi = b[1];
    for(int i = 2; i <= n; i++){
        dis += a[i - 1];
        if(s < dis){
            long long derta = ceil((dis - s) / (double)d);
            ans += derta * mi;
            s += derta * d;
        }
        mi = min(mi, b[i]);
    }
    cout << ans << endl;
    return 0;
}