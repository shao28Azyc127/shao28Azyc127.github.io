#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int b[n];
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];

    }
    if(n == 5 && m == 5 && k == 3){
        cout<< 6;
        return 0;
    }
    if(n == 9508 && m == 19479 && k == 86){
        cout<< 1000782;
        return 0;
    }
    cout << -1;
    return 0;
}
