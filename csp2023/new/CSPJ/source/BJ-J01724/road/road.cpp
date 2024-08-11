#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,vv;
    cin>>n>>d;
    int v[n-1],a[n];
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
        vv+=v[i];
    }
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<vv/d *a[0];
    return 0;
}
