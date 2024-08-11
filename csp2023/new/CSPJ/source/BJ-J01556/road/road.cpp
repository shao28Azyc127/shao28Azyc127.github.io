#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,a[100005]={},b[100005],last,ans=0,box=0,far=0;
    cin>>n>>d;
    for(int i=1; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    last=b[1];
    b[n]=b[n-1]-1;
    for(int i=1; i<n; i++)
    {
        far+=a[i];
        if(last>b[i+1])
        {
            if(i==n-1)
            {
                b[i+1]=b[i];
            }
            ans=ans+last*((far-box-1)/d+1);
            box=d*((far-box-1)/d+1)+box-far;
            last=b[i+1];
            far=0;
        }
    }
    if(ans==0)
    {
        ans=((far-1)/d+1)*b[1];
    }
    cout<<ans;
    return 0;
}
