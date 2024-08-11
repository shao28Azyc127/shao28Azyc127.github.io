
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,v[100005],far[100005],a[100005];
struct point{
    ll a;
    ll id;
//    friend operator < (const point &a,const point &b){
//        a.a<b.a;
//    }
}k[100005];
ll f[100005];
ll lost;
ll ans=0;
ll cmp(point a,point b){
    return a.a<b.a;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        far[i+1]=far[i]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k[i].a=a[i];
        k[i].id=i;
    }
    sort(k+1,k+n+1,cmp);
    for(int i=1;i<=n;i++){
        f[k[i].id]=i;
    }
    for(int i=1;i<n;i++){
        ll x;
        for(int j=i+1;j<=n;j++){
            if(j==n){
                ans+=ceil(1.0*(far[n]-far[i]-lost)/d)*a[i];
                cout<<ans;
//                cout<<i<<" ";
                return 0;
            }
            if(f[j]<f[i]){
                ans+=ceil(1.0*(far[j]-far[i]-lost)/d)*a[i];
                lost=ceil(1.0*(far[j]-far[i]-lost)/d)*d-1.0*(far[j]-far[i]-lost);
                x=j;
       //         cout<<far[j]-far[i]<<" i:"<<i<<"j:"<<j<<" ";
       //         cout<<lost<<" "<<x<<" "<<ans<<" ";
                break;
            }
        }
        i=x-1;
        if(i==n-1){
            ans+=ceil(1.0*(far[n]-far[i]-lost)/d)*a[i];
        }

    }
    cout<<ans;
    return 0;
}

