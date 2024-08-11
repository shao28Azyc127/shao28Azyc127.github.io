#include <bits/stdc++.h>
using namespace std;

long long n, d, ans, cur;
long long a[100010], v[100010], s[100010], q[100010];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n-1; i ++)
    {
        cin >> v[i];
        s[i] = s[i- 1] + v[i];
    }
    for(int i = 1; i <= n-1; i ++)
    {
        cin >> a[i];
    }
    int e;
    cin >> e;
    int t = n-1;
    while(t != 1)
    {
        int l = 1, r = t;
        while(l < r)
        {
            if(a[l] > a[r]) l ++;
            else r --;
        }
        q[++cur] = r;
        t = r-1;
    }
    q[++cur] = 1;
    sort(q + 1, q + cur + 1);
    int dis = 0;
    q[cur + 1] = n;
    for(int i = 1; i <= cur; i ++)
    {
        long long r = s[q[i+1]-1] - s[q[i]-1];
        r -= dis;
        if(r <= 0)
        {
            dis += 0-r;
            continue;
        }
        if(r % d == 0)
        {
            ans += r/d * a[q[i]];
        }
        else
        {
            dis += (r/d+1) * d - r;
            ans += (r/d+1) * a[q[i]];
        }
    }
    cout << ans;
    return 0;
}

