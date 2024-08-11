#include <bits/stdc++.h>
using namespace std;
int t,m,a[5005],b[5005],c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("upe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++)
    {
        int d=b[i]*b[i];
        d-=4*a[i]*c[i];
        if(d<0)
        {
            cout<<"NO";
        }
        else
        {
            d=sqrt(d);
            cout<<(d-b[i])/(2*a[i]);
        }
        cout<<endl;
    }
    return 0;
}
