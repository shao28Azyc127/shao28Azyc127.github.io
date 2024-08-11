#include<bits/stdc++.h>
using namespace std;
int a[100002],b[100002];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,k;
    long long ans=0,ams;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    ams=ceil(ans/k)*b[1];
    cout<<ams;
    return 0;
}
