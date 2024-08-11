#include <iostream>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out","w", stdout);
    int N = 100005;
    int u[N], a[N];
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) cin >> u[i];//距离
    for (int i = 1; i <= n; i++) cin >> a[i];//价格
    int m = 1, ans = 0, lo = 0, more = 0;
    for (int i = 2; i <= n; i++)//计算下降子序列（非最长）
    {
        lo += u[i - 1];
        ///cout << lo << " ";
        if (a[i] < a[m] || i == n)//发现较便宜的车站
        {
            ans += ((lo - 1 - more) / d + 1) * a[m];
            //cout << m << " " << (lo - 1 - more) / d + 1 << " " << ((lo - 1 - more) / d + 1) * a[m] << " " << lo << " " << more << endl;
            more = ((lo - 1 - more) / d + 1) * d + more - lo;//计算多余的油能跑的距离
            m = i;
            lo = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
