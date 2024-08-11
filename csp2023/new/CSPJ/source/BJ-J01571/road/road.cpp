#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],a1[100005];
long long ans;
int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=ans+a1[i];
    }
    if(ans%m==0){
        ans=ans/m;
    }else
    {
        ans=ans/m+1;
    }
    ans=ans*a[1];
    cout<<ans;

    return 0;
}
