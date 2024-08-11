#include <bits/stdc++.h>
using namespace std;
int n, d;
int v[100005];
int a[100005];
int cnt;//钱数
int sum;//本次油量
double s;//剩余油量
int ans;//距离
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans = 0;
        for (int j = i+1; j <= n; j++)
        {
            if (a[j] < a[i])
            {
                for (int k = i; k < j; k++)
                {
                    ans += v[i];
                }
                sum = ceil((s*d + ans)/d);
                cnt += sum * a[i];
                s = sum - (s*d + ans)*1.0/d;
            }
        }
    }
    cout << cnt;
    return 0;
}
