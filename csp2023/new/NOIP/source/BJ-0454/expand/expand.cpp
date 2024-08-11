#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
int a[1000010],b[1000010],c[1000010],d[1000010];
int cc,n,m,q;
void pd()
{
    if(c[1] == d[1] || a[n] == d[m]) cout << 0;
    else if(c[1] < d[1] && c[n] > d[m]) cout << 0;
    else if(c[1] > d[1] && c[n] < d[m]) cout << 0;
    else cout << 1;
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> cc >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i],c[i] = a[i];
    for(int i = 1; i <= m; i++) cin >> b[i],d[i] = b[i];
    if(cc == 1)
    {
        if(a[1] == b[1]) for(int i = 0; i <= q; i++) cout << 0;
        else for(int i = 0; i <= q; i++) cout << 1;
    }
    else
    {
        pd();
        for(int i = 1; i <= q; i++)
        {
            int x1,x2;
            cin >> x1 >> x2;
            for(int j = 1; j <= x1; j++)
            {
                int aa,bb;
                cin >> aa >> bb;
                c[aa] = bb;
            }
            for(int j = 1; j <= x2; j++)
            {
                int aa,bb;
                cin >> aa >> bb;
                d[aa] = bb;
            }
            pd();
            for(int j = 1; j <= n; j++) c[j] = a[j];
            for(int j = 1; j <= m; j++) d[j] = a[j];
        }
    }
    return 0;
}
