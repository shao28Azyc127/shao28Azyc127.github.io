#include <bits/stdc++.h>

using namespace std;
long long small=100000000,maxn=0,sum=0,ans=0,n,d;
long long a[1000050],v[1000050];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<small) small=a[i];
         if(a[i]>maxn) maxn=a[i];
    }
    if(a[1]==small)
    {
        if(sum%small==0) ans=sum/small*d;
        cout<<ans;
    }
    
    return 0;
}
