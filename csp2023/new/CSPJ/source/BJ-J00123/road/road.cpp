#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
int n,d;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int y=0,ans=0,p=b[0];
    for(int i=0;i<n-1;i++)
    {
        p=min(p,b[i]);
        int l=(a[i]-y)*1.0/d+0.5;
        ans+=l*p;
        y=l*d-a[i];
    }
    cout<<ans;
    return 0;
}
