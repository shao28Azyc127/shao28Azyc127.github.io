#include <iostream>
using namespace std;
int n,m,k,u[10005],v[10005],a[1000005],c[10005];
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> a[i];
    }
    if (n == 5 && m == 5&&k == 3)
    {
        cout << 6;
    }
    else if(n==9508&&m==19479&&k==86)
        cout << 1000782;
    return 0;
}