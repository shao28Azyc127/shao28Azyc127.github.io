#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int v[100005],a[100005],mi[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    memset(mi,0x3f,sizeof(mi));
    cin >> n >> d;
    for (int i = 1;i <= n - 1;i++)
    {
        cin >> v[i];
    }
    for (int i = 1;i <= n - 1;i++)
    {
        cin >> a[i];
        mi[i] = min(a[i],mi[i - 1]);
    }
    cin >> a[n];
    long long sum = 0;
    int c = 0;
    for (int i = 1;i <= n - 1;i++)
    {
        int l = ceil(1.0 * (v[i] - c) / d);
        c += d * l - v[i];
        sum += 1ll * l * mi[i];
    }
    cout << sum;
    return 0;
}