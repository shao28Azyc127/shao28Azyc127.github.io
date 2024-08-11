#include <iostream>
using namespace std;
int a[100005],b[100005],c[100005];
int f[100005];
int h[100005];
int n;
bool chk()
{
    for (int i = 1;i <= n;i++)
    {
        if (h[i] < a[i]) return false;
    }
    return true;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1;i <= n - 1;i++)
    {
        int u,v;
        cin >> u >> v;
        f[v] = u;
    }
    int ans;
    for (int i = 1;i <= 1e9;i++)
    {
        if (chk()) break;
        ans = i;
        for (int j = 1;j <= min(n,i);j++)
        {
            h[j] += max(b[j] + i * c[j],1);
        }
    }
    cout << ans;
    return 0;
}