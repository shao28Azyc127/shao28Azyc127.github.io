#include <bits/stdc++.h>
using namespace std;
int n, d;
long long a[100005], b[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 2; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    int road = 0;
    int flag = 1;
    for(int i = 2; i <= n; i++)
    {
        while(road < a[i])
        {
            road += d;
            ans += b[flag];
        }
        if(b[i] < b[flag]) flag = i;
    }
    cout << ans;
    return 0;
}
