#include<bits/stdc++.h>
using namespace std;
int n,d,s,sum=0,a[10000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>s;
        sum+=s;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<sum/d*a[1];
    return 0;
}
