// 100
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

long long v[100010], a[100010];

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,d;
    cin >> n >> d;
    for(int i = 2;i <= n;i++)
    {
        scanf("%lld", &v[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i]);
    }
    long long minn = a[1], totd = 0, money = 0;
    for(int i = 2;i <= n;i++)
    {
        totd += v[i];
        if(minn > a[i] || i == n)
        {
            long long mn = max((totd + d-1)/d, (long long)0);
            money += mn * minn;
            minn = a[i];
           // cout << i << " " << mn << " " << totd << "\n";
            totd -= mn * d;
        }
    }
    cout << money;
    return 0;
}
