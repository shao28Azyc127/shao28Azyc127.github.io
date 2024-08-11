#include<bits/stdc++.h>
using namespace std;
int v[100100],a[100100],n,d,sum,m=1e5+10,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=min(m,a[i]);
    }
    if(m==v[1])
    {
        if(sum%d==0) k=sum/d;
        else k=sum/d+1;
    }
    cout<<k*m;
    return 0;
}
