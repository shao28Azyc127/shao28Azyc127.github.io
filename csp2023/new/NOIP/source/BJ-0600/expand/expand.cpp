#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c, n, m, q, x[N], y[N], min2=1e9, max1=0, min1=1e9, max2 = 0;
int main (){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for (int i=1;i<=n;i++)
    {
         cin >>x[i];
         max1 = max(max1, x[i]);
         min1 = min(min1, x[i]);
    }

    for (int i=1;i<=m;i++)
    {
        cin >> y[i];
        min2 = min(min2, y[i]);
        max2 = max(max2, y[i]);
    }
    if (max1<min2||min1>max2)
        cout << 1;
    else
        cout << 0;
    while (q--)
    {
        int k1, k2, a1, b1, a2, b2;
        cin >> k1 >> k2;
        while (k1--)
        {
            int p, v;
            cin >> p >> v;
            a1 = max(v, max1);
            a2 = min(v, min1);
        }
        while (k2--)
        {
            int p, v;
            cin >> p >> v;
            b1 = min(v, min2);
            b2 = max(v, max2);
        }
        if (a1<b1||a2>b2)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
