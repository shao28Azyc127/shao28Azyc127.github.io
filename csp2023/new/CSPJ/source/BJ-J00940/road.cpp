#include <bits/stdc++.h>
#define MAXN 100000
#define ll long long
#define db double

using namespace std;

int n,d;
ll v[MAXN+5];
ll a[MAXN+5];
ll ans=0;

int up(db x){
   int ans=(int)x;
   if(x-ans>0) ans++;
   return ans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll mn=a[1];
    ll dis=0;
    ll lost=0;
    for(int i=2;i<=n-1;i++){
        dis+=v[i-1];
        if(a[i]<mn){
            ll V=(dis-lost)/d;
            if((dis-lost)%d!=0)V++;
            lost=V*d+lost-dis;
            ans+=mn*V;
            dis=0;
            mn=a[i];

        }

    }
    ll V=(dis+v[n-1]-lost)/d;
    if((dis-lost)%d!=0)V++;
    ans+=mn*V;
    dis=0;
    cout<<ans<<endl;
    return 0;
}
