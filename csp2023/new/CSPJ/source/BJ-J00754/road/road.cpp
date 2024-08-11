#include <bits/stdc++.h>
using namespace std;
int a[100001], v[100000];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int cost = 0, more = 0;
    for(int i = 1; i < n;)
    {
        int j, km = v[i] - more;
        for(j = i + 1; j < n; j++)
        {
            if(a[i] <= a[j]) km += v[j];
            else break;
        }
        int x = ceil(1.0 * km / d) * a[i];
        cost += x;
        more = x / a[i] * d - km;
        i = j;
    }
    cout << cost;
    return 0;
}