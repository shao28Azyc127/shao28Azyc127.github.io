#include<iostream>
#include<cstdio>
using namespace std;
int op(double a,double b)
{
    double ans=a/b;
    int an=a/b;
    if(ans==an) return an;
    else return an+1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ans=0,y=0,lc=0;
    cin>>n>>d;
    int v[n]={},a[n]={};
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<n;i++) cin>>a[i];
    int t=a[1];
    for(int i=2;i<=n;i++)
    {
        lc+=v[i-1];
        if(a[i]<t)
        {
            ans+=t*op(lc-y,d);
            y+=op(lc-y,d)*d-lc;
            t=a[i];
            lc=0;
        }
    }
    cout<<ans;
    return 0;
}