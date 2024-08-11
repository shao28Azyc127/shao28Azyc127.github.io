#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N],a[N],sum[N],mi[N]={1000000};
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    double d;
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mi[i]=min(mi[i-1],a[i]);
    }
    int ans=0;
    double t=0.0;
    for(int i=2;i<=n;i++)
    {
        double cnt1=double(v[i]/d)-t;
        int cnt2=cnt1;
        if(cnt1-cnt2>0.0)cnt2++;
        t=cnt2+t-double(v[i]/d);
        ans=ans+cnt2*mi[i-1];
//        cout<<cnt2<<" "<<ans<<" ";
    }
    cout<<ans;
    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
