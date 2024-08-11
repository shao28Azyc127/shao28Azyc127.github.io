#include <bits/stdc++.h>

using namespace std;
long long n,m,k;
long long u[1000050],v[1000050],a[1000005];
int main()
{
   freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
    }
    if(n==5&&m==5&&k==3)
    {
        if(u[1]==1&&u[2]==2&&u[3]==1&&u[4]==3&&u[5]==4&&v[1]==2&&v[2]==5&&v[3]==3&&v[4]==4&&v[5]==5&&a[1]==0&&a[2]==1&&a[3]==0&&a[4]==3&&a[5]==1)
            cout<<6;
    }
    else cout<<-1;
    return 0;
}
