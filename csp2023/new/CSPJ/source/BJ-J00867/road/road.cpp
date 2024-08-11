#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[100010],b[100010],c[100010],ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        c[i]=b[i];
    }
    sort(c+1,c+n);
    if(c[1]==b[1])
    {
        if(ans%b[1]==0)
        {
            cout<<ans/b[i]*d;
        }
        else
        {
            cout<<ans/b[i]*d+d;
        }
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(b[i]==c[1])
            {
                int mi=b[i];
            }
            if(b[i]==c[n])
            {
                int ma=b[i];
            }
        }
    }
    cout<<ma*d;
}