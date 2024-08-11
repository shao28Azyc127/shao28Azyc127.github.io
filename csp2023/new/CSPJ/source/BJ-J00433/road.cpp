// 2023/10/21 10:40
// By Jerry1031
//freopen checked!
// 注释应该让写中文吧（

#include <iostream>
#include <cmath>
using namespace std;

#define int long long
// 四年OI一场空，不开long long 见祖宗

int v[100005], a[100005];
int s[100005]; // 路程前缀和
bool f[100005]; // 油价是否为当前最小值
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    int l = 0, mina = 1e9;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        l += v[i];
        s[i] = s[i - 1] + v[i - 1];
    }
    s[n] = s[n - 1] + v[n - 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < mina)
        {
            mina = a[i];
            f[i] = true;
        }
    }

    f[n] = true;

    if(mina == a[1]) // A
    {
        cout << (long long)(ceil(1. * l / d)) * mina << endl;
        return 0;
    }

    int ans = 0;
    double lft = 0; //目前还剩的油
    for(int i = 1; i < n; i++) // 显然最后一个站点不用加油
    {
        if(f[i]) // 当前为油价最小值，需要加油
        {
            int j = i + 1;
            while(!f[j])
                j++;
            int k = s[j] - s[i]; // 距离下一个加油点的路程

            int need = ceil(((k - lft * d) / d)); //目前需要买的油
            ans += need * a[i]; // 本次油价
            lft += need - 1. * k / d;
        }
    }
    cout << ans << endl;
    return 0;
}
