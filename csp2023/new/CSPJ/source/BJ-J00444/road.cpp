#include<bits/stdc++.h>
using namespace std;
int n, d, a[100005], v[100005], o, p = 100000;
long long ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        if(a[i] < p) p = a[i];
        if(int(v[i] - o * d) % d == 0) ans += ceil((v[i] - o * d) * 1.0 / d) * p;
        else ans += ceil(v[i] * 1.0 / d) * p;
        o += ceil(v[i] * 1.0 / d) - v[i] * 1.0 / d;
    }
    cout << ans;
    return 0;
}