#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "W", stdout);
    int n, d, a1;
    int tmp, dis = 0;
    cin >> n >> d;
    int r = n-1;
    while(r--) {
        cin >> tmp;
        dis += tmp;
    }
    for (int i=0; i<n; i++) {
        if (i == 0) cin >> a1;
        else cin >> tmp;
    }
    cout << dis / d * a1;
    return 0;
}