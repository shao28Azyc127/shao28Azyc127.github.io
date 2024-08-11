#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, c= 0, ans = 0, maxn = -1;
int u[200005], v[200005], a[200005];
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> u[i] >> v[i] >> a[i];
    }
    int ans = k;
    for (int i = 1; i <= n; i++){
        if (ans < a[i]) ans = a[i];
        ans++;
    }
    cout << ans + ans%k << endl;
return 0;}
