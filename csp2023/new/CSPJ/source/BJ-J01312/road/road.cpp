#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int v[N], a[N], dp[N], sum[N];
int z(int a, int b)
{
    if(a % b == 0) return 0;
    return 1;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 2;i <= n;i++)
    {
        dp[i] = 1e9 + 10;
        for(int j = 1;j < i;j++)
        {
            int p = sum[i] - sum[j];
            dp[i] = min(dp[i], dp[j] + ((p / d) + z(p, d)) * a[j]);
            cout << dp[j] + ((p / d) + z(p, d)) * a[j] << " ";
        }
        cout << endl;
    }
    cout << dp[n];
}
