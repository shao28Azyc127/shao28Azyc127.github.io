#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    int v[n],a[n+1],q[n];
    q[0] = 0;
    for (int i = 1;i < n;i++)
    {
        cin >> v[i];
        q[i] = v[i] + q[i-1];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (q[n] % d == 0)
    {
        cout << q[n] / d * a[1];
    }
    else
    {
        cout << (q[n] / d + 1) * a[1];
    }
}