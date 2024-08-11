#include <bits/stdc++.h>
using namespace std;
int n,d,v[10005],a[10005],sums,summ;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        sums+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(sums%d==0)
    {
        summ=sums/d;
        summ*=a[1];
    }
    else
    {
        summ=sums/d+1;
        summ*=a[1];
    }
    cout<<summ;
    return 0;
}