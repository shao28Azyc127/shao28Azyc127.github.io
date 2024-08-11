#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,d,ans;
int u[100010],a[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
        cin >> u[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int minn = a[1];
    int c = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        if(i != 1)
            u[i] -= c;
        if(a[i] < minn)
            minn = a[i];
        if(u[i] % d == 0)
        {
            ans += u[i] / d * minn;
            c = 0;
        }
        else
        {
            ans += (u[i] / d + 1) * minn;
            c = (u[i] / d + 1) * d - u[i];
        }
    }
    cout << ans;
    return 0;
}
