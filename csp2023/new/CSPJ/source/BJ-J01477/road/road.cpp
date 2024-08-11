#include<bits/stdc++.h>
using namespace std;
struct h{
    long long int mon;//have spent money
    long long int she;
    long long int hw;

};
h x[100005];


int v[100005];
int a[100005];
int m(int u)
{
    int z=9999999;
    for(int i=1;i<=u;i++)
    {
        z=min(z,a[i]);

    }
    return z;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    x[0].hw=0;
    x[0].she=0;
    x[0].mon=0;
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        long long f=x[i-1].she*d-x[i-1].hw;
        long long o=v[i]-f;
        if(v[i]>f)
        {
            if(o%d==0)
            {
                x[i].she=x[i-1].she+o/d;
                x[i].mon=x[i-1].mon+o/d*m(i);
            }
            else
            {
                x[i].she=x[i-1].she+o/d+1;
                x[i].mon=x[i-1].mon+(o/d+1)*m(i);
            }
        }
        else{
            x[i].mon=x[i-1].mon;
            x[i].she=x[i-1].she;
        }
        x[i].hw=x[i-1].hw+v[i];
    }
    cout<<x[n].mon;
    return 0;
}
