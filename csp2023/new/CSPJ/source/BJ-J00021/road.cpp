#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int v[100010], a[100010], minn[100010];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(minn, 0x3f3f3f3f, sizeof(minn));
    for (int i = 1; i <= n - 1; i++)
    {
        minn[i] = min(minn[i - 1], a[i]);
    }
    long long last = 0, sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int op = (v[i] - last + (d - 1)) / d;
        sum += 1ll * op * minn[i];
        last = last + 1ll * op * d - v[i];
    }
    cout << sum << endl;
    return 0;
}