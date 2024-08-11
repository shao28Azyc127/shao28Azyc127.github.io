#include<bits/stdc++.h>
using namespace std;
int a[10010], v[10010], sum[10010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long mo = 0, fu = 0;
    int n, d;
    cin >> n >> d;
    sum[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mn = a[1], mnx = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] < mn)
        {
            int dis = sum[i] - sum[mnx];
            int m = (dis + d - 1 - fu) / d;
            mo += m * a[mnx];
            fu = fu + m * d - dis;
            mn = a[i];
            mnx = i;
        }
    }

    cout << mo << endl;
    return 0;
}
