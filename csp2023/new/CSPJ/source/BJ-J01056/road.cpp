#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[100005];
long long h[100005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, r;
    cin >> n >> r;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    long long minn = 1e17;
    for (int i = 1; i < n; i++)
    {
        minn = min(minn, a[i]);
    }
    if (minn == h[1])
    {
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += a[i];
        }
        cout << sum * h[1] << endl;
        return 0;
    }
    int x = h[1], ans = 0;
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        int u = ceil(a[i] / (r + 0.0)) - flag;
        ans += u * h[i];
        flag = u - a[i];
    }
    cout << ans << endl;
    return 0;
}
