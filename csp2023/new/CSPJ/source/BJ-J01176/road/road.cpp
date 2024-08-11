#include <bits/stdc++.h>
using namespace std;
int n,d,sum;
int v[100005],a[100005],w[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    w[0]=0;
    for (int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        w[i]=w[i-1]+v[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if ((w[n-1]*a[1])%d==0)
    {
        cout<<(w[n-1]*a[1])/d;
    }
    else
    {
        cout<<(w[n-1]/d+1)*a[1];
    }
    return 0;
}
