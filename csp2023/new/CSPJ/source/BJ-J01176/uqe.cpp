#include <bits/stdc++.h>
using namespace std;
int t,m,a[5005],b[5005],c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for (int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if (a[i]==-1&&b[i]==0&&c[i]==0)
        {
            cout<<"0";
        }
        else if (a[i]==1&&b[i]==0&&c[i]==0)
        {
            cout<<"0";
        }
    }
    return 0;
}
