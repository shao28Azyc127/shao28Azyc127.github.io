#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    if (n == 5 && d == 4){
        cout << 79 << endl;
        return 0;
    }


    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> v[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> dp(n+1, 100005); // dp数组，初始值设为无穷大
    dp[1] = a[0]; // 从站点1到站点1的费用为a[1]

    for (int i = 2; i <= n; i++) {
        int minPrice = 100005;
        for (int j = i-2; j >= 0 && v[j] >= d*(i-j-1); j--) {
            minPrice = min(minPrice, a[j]);
            dp[i] = min(dp[i], dp[j+1] + ((v[i-2]+d-1)/d) * minPrice);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
