#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, d;
int v[100010];
int a[100010];
int cnt[100010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out","w",stdout);
    cin >>n >>d;
    int minn = 0x3f3f3f3f;
    ll sum = 0;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll cost = 0;
    int leftfuel = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= minn)
        {
            cost += ceil(1.0*max(0, v[i]-leftfuel)/d)*minn;
        }
        if(a[i] < minn)
        {
            minn = a[i];
            cost += ceil(1.0*max(0, v[i]-leftfuel)/d)*minn;
        }
        leftfuel = leftfuel + ceil(1.0*max(0, v[i]-leftfuel)/d) * d - v[i];
    }
    cout << cost << endl;
    return 0;
}
