#include <bits/stdc++.h>
using namespace std;
int a[100005], v[1000005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,d;
    cin >> n >> d;
    int sum = 0;
    for (int i = 1;i <= n - 1;i++) {
        cin >>  v[i];
        sum += v[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int price = 0;double oil = 0;
    for (int i = 1;i <= n;i++) {
        int buy = ceil(1.0 * v[i] / d);
        price += buy * a[i];
    }
    cout << price << endl;
    return 0;
}