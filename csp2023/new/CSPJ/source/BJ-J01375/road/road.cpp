#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

long long n, d, v[100005], a[100005], ansv[100005], ansa[100005], cnt, ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int mn = 1e9, l = 0, ll = 0;
    for (int i = 1; i <= n; i++)
    {
        ansv[l] += v[i];
        if (a[i] < mn)
        {
            ansv[l] -= ll;
            int c = 0, lll = ansv[l];
            while (ansv[l] > 0)
            {
                ansv[l] -= d;
                c++;
            }
            ll = c * d - lll;
            ansv[l] = c;
            mn = a[i];
            l = ++cnt;
            ansa[cnt] = a[i];
        }
    }
    for (int i = 1; i <= cnt; i++)
        ans += ansv[i] * ansa[i];
    cout << ans << endl;
    return 0;
}
