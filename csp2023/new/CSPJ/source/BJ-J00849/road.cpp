#include <bits/stdc++.h>
using namespace std;
int n,d;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int v[n+5],a[n+5],b[n+5];
    int ju=0;
    for (int i=0;i<n-1;i++)
    {
        cin>>v[i];
        ju+=v[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>a[i];

        b[i]=a[i];
    }
    sort(b,b+n);
    if (b[0]==a[0])
    {
        if (ju%d==0)
        {
            cout<<ju/d*b[0];
            return 0;
        }
        else{
            cout<<(ju/d+1)*b[0];
            return 0;
        }
    }
    int you=0,min=1e9,mon=0;
    for (int i=0;i<n;i++)
    {
        if (you<v[i])
        {

        }
    }
    return 0;
}