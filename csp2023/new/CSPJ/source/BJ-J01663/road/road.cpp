#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0,s=0,mn=1e9;
    for(int i=1;i<n;i++){
        mn=min(mn,a[i]);
        if(s<v[i]){
            ll p=(v[i]-s)/d;
            if((v[i]-s)%d!=0)p++;
            ans+=p*mn;
            s+=p*d;
        }
        s-=v[i];
    }
    cout<<ans;
    return 0;
}
