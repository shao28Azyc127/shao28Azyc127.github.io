#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[5005],b[5005],c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,k,i,j,t,v;
    double x;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for (i=1;i<=n;i++)
    {
        x=b[i]*b[i]-4*a[i]*c[i];
        if (x<0)
            cout<<"NO"<<endl;
        else
        {
            x=(-b[i]+sqrt(x))/(2*a[i]);
            if (x==0.5)
                cout<<"1/2"<<endl;
            else if (x==-0.5)
                cout<<"-1/2"<<endl;
            else
                cout<<x<<endl;
        }
    }
    return 0;
}
