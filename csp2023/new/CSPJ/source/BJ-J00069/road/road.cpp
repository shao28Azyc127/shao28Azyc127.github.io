#include <bits/stdc++.h>
using namespace std;
int v[100010],a[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,r = 0;
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        cin >> v[i];
        r += v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    cout << (r + d - 1) / d * a[1];
    return 0;
}
