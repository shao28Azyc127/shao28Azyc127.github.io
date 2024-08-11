#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll b[114514],a[114514],price[114514];
ll minprice=0,wz=0,zhan=1,ans=0,n,d,q,cs;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    a[1]=0;
    for(ll i=2;i<=n;i++){
        cin>>b[i];
        a[i]=b[i]+a[i-1];
    }
    for(ll i=1;i<=n;i++){
        cin>>price[i];
    }
    minprice=price[1];
    while(zhan<=n){
        q=a[zhan]-wz;
        cs=q/d;
        if(cs==0)cs=1;
        ans+=minprice*cs;
        wz+=d*cs;
        while(a[zhan]<=wz){
            minprice=min(minprice,price[zhan]);
            zhan++;
            if(zhan>n)break;
        }
    }
    cout<<ans;
    return 0;
}
