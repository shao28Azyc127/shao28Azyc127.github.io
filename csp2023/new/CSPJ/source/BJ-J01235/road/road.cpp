#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int minn = 1e6;
long long ans = 0;
const int MAXN = 1e5 + 5;
int a[MAXN], v[MAXN];
long long sum;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    for(int i = 1; i <= n - 1; i++)
    {
        sum += v[i];
        if(sum > n * d)
        {
            ans += v[i] * minn;
        }
    }
    cout << ans;
    return 0;
}
