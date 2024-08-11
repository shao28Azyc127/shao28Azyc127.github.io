#include<bits/stdc++.h>
using namespace std;
int n,d,a[100100],b[100100],s,ans,c;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(i==2)
        {
            ans+=((a[2]-1)/d+1)*b[1];
            s=((a[2]-1)/d+1)*d-a[2];
            c=a[i];
        }
        else
        {
            int k=min(c,b[i-1]);
            ans+=(((a[i]-s)-1)/d+1)*k;
            s=(((a[i]-s)-1)/d+1)*d-(a[i]-s);
            c=k;
        }
    }
    cout<<ans;
    return 0;
}
