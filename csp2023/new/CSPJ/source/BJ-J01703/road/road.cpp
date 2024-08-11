#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i < n;i++)
    {
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    return 0;
}
