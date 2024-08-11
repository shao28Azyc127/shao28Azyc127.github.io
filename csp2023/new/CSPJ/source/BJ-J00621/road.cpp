#include <bits/stdc++.h>
using namespace std;

int v[100005], m[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> m[i];
    
    int s = 0, minn = 1000000; // s->v, minn->m
    long long ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(m[i] < minn) minn = m[i];
        int ss = v[i]-s;
        if(ss % d == 0)
        {
            ans += ss / d * minn;
            s = 0;
        }
        else
        {
            ans += (ss / d + 1) * minn;
            s = (ss / d + 1) * d - v[i+1];
        }
    }
    cout << ans << endl;
    return 0;
}