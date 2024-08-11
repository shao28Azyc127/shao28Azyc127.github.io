#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int a[n-1],b[n],ans=0,t=0,min_z=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    min_z=b[0];
    for(int i=0;i<n-1;i++)
    {
        ans+=min_z*((a[i]-t)/d);
        if((a[i]-t)%d!=0)
        {
            ans+=min_z;
            t=((a[i]-t)/d+1)*d-a[i];
        }
        else
            t=0;
        //cout<<ans<<" "<<t<<endl;
        if(b[i+1]<min_z)
            min_z=b[i+1];
    }
    cout<<ans;
    return 0;
}
