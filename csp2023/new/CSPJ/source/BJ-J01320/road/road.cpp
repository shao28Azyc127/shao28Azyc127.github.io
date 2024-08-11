#include<bits/stdc++.h>
using namespace std;
int n,d;
int sum;
int u[100005];
int a[100005];
int oil_min = 1e+9;
int oil_more;
int main()
{
    freopen("road2.in","r",stdin);
    freopen("road2.out","w",stdout);
    cin>> n >> d;
    int i;
    for (i = 1; i < n; ++i) cin >> u[i];
    for (i = 1; i <= n; ++i) cin >> a[i];
    for (i = 1; i < n; ++i)
    {
        oil_min = min(oil_min,a[i]);
        int need = (u[i] - oil_more + d - 1) / d;
        sum += need * oil_min;
        oil_more = oil_more + need * d - u[i];
    }
    cout << sum;
    return 0;
}