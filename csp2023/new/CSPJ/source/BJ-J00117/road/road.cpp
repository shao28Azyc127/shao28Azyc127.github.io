#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, d;
int ans[100005], a[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 2; i <= n; i++)
    {
        int v;
        scanf("%d", &v);
        ans[i] = ans[i - 1] + v;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int tot = 0, len = 0, lastSta = a[1];
    for(int i = 2; i <= n; i++)
    {
        tot += ceil((ans[i] - len) / 1.0 / d) * lastSta;
        len += ceil((ans[i] - len) / 1.0 / d) * d;
        lastSta = min(lastSta, a[i]);
    }
    cout << tot << endl;
    return 0;
}
