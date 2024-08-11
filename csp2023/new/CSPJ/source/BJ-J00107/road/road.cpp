#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100005;
int a[N];
int v[N];
int mina[N];
long long ans = 0;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    mina[0] = N;
    for ( int i = 1; i <= n - 1; i++) {
        cin >> v[i];
    }
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
        mina[i] = min(mina[i - 1], a[i]);
    }
    int r = 0;
    for ( int i = 1; i <= n; i++) { 
        r += v[i];
        if ( r > 0) {
            ans += ((r + d - 1) / d) * mina[i];
            r -= ((r + d - 1) / d) * d;
        }
    }
    cout << ans << endl;
    return 0;
}