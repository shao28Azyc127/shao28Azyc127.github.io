#include <iostream>
using namespace std;
int n,m,k,u[10005],v[10005],a[10005],f[10005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w".stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=m; ++i)
    {
        cin >> u[i] >> v[i] >> a[i];
    }
    f[1] = 0;
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            if(v[j] == i)
            {
                if(f[u[j]]>=f[i])
                {
                    f[i] = f[u[j]]+1;
                }
            }
        }
    }
    cout << f[n];
    return 0;
}
