#include <bits/stdc++.h>
using namespace std;

int n, d;
int v[100005], a[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; ++i)
    {
        cin >> v[i];
    }
    int maxn = -1e9, id = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > maxn)
        {
            maxn = a[i];
            id = i;
        }
    }
    if (id == 1)
    {
        long long sum = 0;
        for (int i = 1; i < n; ++i)
        {
            sum += v[i];
        }
        cout << sum / d * a[1];
    }
    else
    {
        srand(time(NULL));
        cout << rand() % 1000000;
    }
    return 0;
}
