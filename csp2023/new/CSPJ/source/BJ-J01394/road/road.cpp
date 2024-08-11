#include <iostream>
using namespace std;
int up(int n,int m)
{
    double ans = n / 1.0 / m;
    if (ans == n / m) return n / m;
    else return n / m + 1;
}
const int N = 1e5 + 3;
int d[N],v[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int h = 0,ans = 0;
    for (int i = 1;i < n;i++)
        cin >> d[i];
    for (int i = 1;i <= n;i++)
        cin >> v[i];
    for (int i = 1;i < n;)
    {
        int now = v[i];
        while (v[i] >= now && h < d[i])
        {
            ans += now * up(d[i] - h,m);
            h += up(d[i] - h,m) * m;
            h -= d[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}

