#include <bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int n,d,ans=0;
    cin >>n>>d;
    for (int i=1;i<n;i++)
    {
        cin >>v[i];
        ans+=v[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    if (ans%a[1]==0) cout <<ans/a[1];
    else cout <<ans/a[1];

    return 0;
}
