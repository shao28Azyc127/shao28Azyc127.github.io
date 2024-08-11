#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, d, v[100005], a[100005], b[100005], x[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(b, 0x3f3f3f3f, sizeof(b));
    cin >> n >> d;
    x[1] = 0;
    for(int i = 1; i < n; i++){
        cin >> v[i];
        x[i +1] = x[i] +v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = min(b[i - 1], a[i]);
    }
    long long ans = 0, l = 0;
    for(int i = 1; i <= n; i++){
        if(l >= x[i]) continue;
        long long f = x[i] - l, h = ceil((double)f / d);
        ans += b[i - 1] * h;
        l += h * d;
    }
    cout << ans;
    return 0;
}
