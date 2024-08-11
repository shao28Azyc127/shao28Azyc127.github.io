#include<bits/stdc++.h>
using namespace std;
int n, d, v[100005], a[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        a[i] = min(a[i-1], a[i]);
    }
    int fuel = 0, ans = 0;
    for(int i = 1; i < n; i++){
        int newfuel = ceil(1.0*(v[i]-fuel)/d);
        fuel += newfuel*d;
        ans += newfuel*a[i];
        fuel -= v[i];
    }
    cout << ans;
    return 0;
}
