#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,v[100010],dist=0,ans=0,minn=1e6,a[100010],p,j;
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(minn>a[i])
            j=i,minn=a[i];
        if(dist>v[i])
            dist-=v[i];
        else{
            for(p=d;p<v[i]-dist;p+=d);
            ans+=minn*p/d;
            dist+=p-v[i];
            //cout<<i<<" "<<ans<<" "<<p<<" "<<minn<<" "<<dist<<" "<<j<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
