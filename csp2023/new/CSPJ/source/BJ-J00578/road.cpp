#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NR = 100010;
const ll INF = 9e18;

ll v[NR], a[NR];
int n, d;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    ll sum = 0;
    for (int i = 1; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    ll mn = INF;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    if (mn == a[1])
    {
        cout << (sum + d - 1) / d * a[1] << endl;
    }
    return 0;
}
