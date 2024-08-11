#include <bits/stdc++.h>
#define N 100005

using namespace std;

long long int v[N], a[N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long int i, j, k;
    long long int n, d;
    cin >> n >> d;
    for(i=1; i<=n-1; i++)
    {
        cin >> v[i];
    }
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    long long int qian = a[1];
    long long int you = 0;
    long long int ans = 0;
    long long int gs;
    for(i=1; i<=n-1; i++)
    {
        if(a[i] < qian) qian = a[i];

        long long x = v[i] - you;
        if(x < 0) x = 0;

        gs = (x + d - 1) / d;
        ans += qian * gs;
        you = you + gs * d - v[i];

    }
    cout << ans << endl;
    return 0;
}
