#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long n, d, a, s[100010], minn[100010], ans = 0, dis = 0;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    minn[0] = 1e9;
    cin >> n >> d;
    for(int i = 1;i < n;i++)
    {
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a;
        minn[i] = min(minn[i - 1], a);
    }
    for(int i = 1;i < n;i++)
    {
        long long cha = s[i] - dis;
        ans += ceil(1.0 * cha / d) * minn[i];
        dis += ceil(1.0 * cha / d) * d;
    }
    cout << ans << "\n";
    return 0;
}
