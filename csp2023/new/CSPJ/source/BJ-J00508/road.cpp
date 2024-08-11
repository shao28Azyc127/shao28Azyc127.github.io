#include<bits/stdc++.h>
using namespace std;

long long n, d;
long long v[100005];
long long a[100005];
long long sh = 1;
long long jl;
long long ans;
double sy;

long long sqz(double x)
{
    if(x == int(x)) return x;
    return x + 1;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(long long i = 1;i < n;i++)
    {
        cin >> v[i];
    }
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(long long i = 2;i <= n;i++)
    {
        jl += v[i - 1];
        if(a[i] < a[sh])
        {
            ans += sqz(1.0 * jl / d - sy) * a[sh];
            sh = i;
            sy = sqz(1.0 * jl / d - sy) + sy - 1.0 * jl / d;
            jl = 0;
        }
    }
    ans += sqz(1.0 * jl / d - sy) * a[sh];
    cout << ans << endl;
}
