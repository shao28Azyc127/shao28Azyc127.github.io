#include<iostream>
#include<cstdio>
using namespace std;

long long n, d, v[10005], a[10005], ans, oil;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for(int i = 1; i <= n - 1; i ++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n - 1; i ++)
    {
        if(oil > v[i])
        {
            oil -= v[i];
            continue;
        }

        long long dis = 0;
        for(int j = i; j <= n - 1; j ++)
        {
            if(a[j] < a[i])
            {
                break;
            }
            dis += v[j];
        }

        long long x = dis - oil;
        if(x < 0) x = 0;

        if(x % d == 0)
        {
            long long y = x / d;

            oil += y * d;
            ans += y * a[i];
        }
        else
        {
            long long y = x / d + 1;

            oil += y * d;
            ans += y * a[i];
        }

        oil -= v[i];
    }

    cout << ans << endl;

    return 0;
}
