#include<bits/stdc++.h>
using namespace std;
long long v[100005], a[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1;i < n;i++) cin >> v[i];
    for(int i = 1;i <= n;i++) cin >> a[i];
    long long ans = 0, cnt = 0;
    int fir = 1;
    for(int i = 2;i <= n;i++)
    {
        cnt += v[i - 1];
        if(a[i] < a[fir])
        {
            ans += (cnt + d - 1) / d * a[fir];
            long long t = (cnt + d - 1) / d * d - cnt;
            fir = i;
            v[i] -= t;
            cnt = 0;
        }
    }
    if(fir != n)
    {
        ans += (cnt + d - 1) / d * a[fir];
    }
    cout << ans;
    return 0;
}
