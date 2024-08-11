#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,d,cc,t,a[110000],sum[110000];
struct node{
    int l,r,v;
}c[110000];
bool check(int l){
    int num=0;
    for(int i=1;i<=n;i++){
        a[i]=l%2;
        l/2;
        if(a[i]==1) num++;
        if(num>k) return 0;
        if(a[i]==0) num=0;
    }
    return 1;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> cc >> t;

    if(cc==17||cc==18){
        while(t--){
            cin >> n >> m >> k >> d;
            ll cnt=0;
            for(ll i=1;i<=m;i++){
                ll x,y,v;
                cin >> x >> y >> v;
                if(x>k||x*k>d) continue;
                cnt+=d-x*k;
            }
            cout << cnt << "\n";
        }
    }else{
        while(t--){
            cin >> n >> m >> k >> d;
            ll cnt=0;
            for(ll i=1;i<=m;i++){
                ll x,y,v;
                cin >> x >> y >> v;
                if(x>k||x>y) continue;
                c[i].r=y;
                c[i].v=v;
                c[i].l=y-x+1;
            }
            for(int i=0;i<(1<<n);i++){
                if(check(i)){
                    ll ans=0;
                    for(int j=1;j<=n;j++){
                        sum[j]=sum[j-1]+a[j];
                    }
                    for(int j=1;j<=m;j++){
                        if(sum[c[i].r]-sum[c[i].l-1]==c[i].r-c[i].l+1) ans+=c[i].v-(c[i].r-c[i].l+1)*d;
                    }
                cnt=max(cnt,ans);
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}
