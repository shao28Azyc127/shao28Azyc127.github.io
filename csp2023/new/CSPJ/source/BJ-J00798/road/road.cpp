#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+10;
ll n,d,a[Maxn],v[Maxn];
ll now,last,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    last=a[1],now=0;
    for(int i=2;i<n;i++)
    {
        if(a[i]<last)
        {
            ans+=((v[i]-now+d-1)/d)*last;
            now+=((v[i]-now+d-1)/d)*d;
            last=a[i];
        }
    }
    ans+=((v[n]-now+d-1)/d)*last;
    cout<<ans<<endl;
    return 0;
}