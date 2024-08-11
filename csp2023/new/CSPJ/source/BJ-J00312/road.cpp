#include <bits/stdc++.h>
using namespace std;
int sum, a[100005], b[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d; cin >> n >> d;
    for (int i = 1;i < n;i++) cin >> a[i], sum += a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    cout << sum * d * b[1];
}
