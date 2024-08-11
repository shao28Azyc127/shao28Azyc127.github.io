#include <bits/stdc++.h>
#define int long long
using namespace std;

int v[100010];
int sv[100010];
int gas[100010];

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    for(int i=1; i<n; i++)
    {
        cin >> v[i];
        sv[i] = sv[i - 1] + v[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin >> gas[i];
    }
    int fnow = 0;
    int fmin = gas[1];
    int mpos = 1;
    int total = 0;
    for(int i=2; i<n; i++)
    {
        if(gas[i] < fmin)
        {
            int dist = sv[i - 1] - sv[mpos - 1] - fnow;
            total += (dist + d - 1) / d * fmin;
            fnow = d - dist % d;
            if(fnow == d) fnow = 0;
            fmin = gas[i];
            mpos = i;
        }
    }
    int dist = sv[n - 1] - sv[mpos - 1] - fnow;
    total += (dist + d - 1) / d * fmin;
    cout << total << endl;
}
