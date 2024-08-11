#include<iostream>
#include<cstdio>
using namespace std;

int v[100005], a[100005];
int n, d;

int cal(int x)
{
    if (x <= 0)return 0;
    return (x - 1) / d + 1;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    v[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0, low = a[1];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < low)low = a[i];
        int tem;
        v[i] -= l;
        if (v[i] > 0)
        {
            tem = cal(v[i]);
            l = tem * d - v[i];
        }
        else if (v[i] <= 0)
        {
            tem = 0;
            l = -v[i];
        }
        ans += tem * low;
    }
    cout << ans << endl;
    return 0;
}
