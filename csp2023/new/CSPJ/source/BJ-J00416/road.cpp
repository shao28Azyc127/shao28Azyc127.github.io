#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        ans+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long sum=0;
    int y=ans/d;
    sum=y*a[1];
    if(ans%d!=0)
    {
        sum+=a[1];
    }
    cout<<sum;
    return 0;
}
