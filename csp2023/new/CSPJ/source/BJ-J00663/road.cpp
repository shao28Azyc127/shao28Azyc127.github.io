#include <iostream>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, d, oil = 0, sum = 0, index = 1, cnt = 0, c = 0, g;
    cin >> n >> d;
    int v[n + 5], a[n + 5];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (sum > 0)
    {
        if (oil * d < v[index])
        {
            while (oil * d > v[index])
            {
                oil++;
                cnt += a[index];
            }
            index++;
            g += v[index];
        }
        else if (oil - 1 < 0)
        {
            while (oil * d > v[index])
            {
                oil++;
                cnt += a[index];
            }
            g += v[index];
            index++;
        }
        sum -= d;
        oil--;
        c += d;
    }
    cout << cnt;
    return 0;
}
