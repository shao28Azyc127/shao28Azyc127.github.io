#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
#include<map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,v[100100],sum[100100],a[100100],mins[100100];
ll ans,les,k=1;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    mins[0]=2e9;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        sum[i+1]=sum[i]+v[i];
    //    cout<<sum[i]<<" ";
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mins[i]=min(mins[i-1],a[i]);
//        cout<<mins[i]<<" ";
        if(i==n) mins[i]=-1;
        if(mins[i]!=mins[i-1])
        {
//            cout<<i<<":";
            ll t=sum[i]-sum[k];
//            cout<<t<<",";
//            cout<<i<<" "<<k<<" "<<t<<endl;
            t-=les;
//            cout<<les<<" "<<t<<" ";
            ll f=ceil(t*1.0/d);
            ans+=f*mins[k];
            les=f*d-t;
//            cout<<f<<" "<<ans<<" "<<les<<endl;
            k=i;
        }
    }
    cout<<ans;
    return 0;
}
