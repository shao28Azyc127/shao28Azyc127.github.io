#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int v[100001],a[1000001],n,d;
    cin>>n>>d;
    a[0]=0;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
    }
    int mi=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]<mi) mi=v[i];
        else v[i]=0;
    }
    int l,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        a[i]=0;
        if(v[i]!=0||i==n-1)
        {
            a[l]=sum;
            l=i;
            sum=0;
        }
    }
    sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            int x;
            x=ceil((a[i]-ans)/1.0/d);
            ans=ans-a[i]+x*d;
            sum+=x*v[i];
        }
    }
    cout<<sum;
    return 0;
}