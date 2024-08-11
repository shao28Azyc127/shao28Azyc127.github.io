#include<bits/stdc++.h>
#define LL long long
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
using namespace std;
LL N,a[10][6];
LL tng[114514];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(j,1,N){
        rep(i,1,5)cin>>a[j][i];
        rep(i,1,5){
            rep(k,1,9){
                LL hsh=0,hst=1;
                a[j][i]+=k;a[j][i]%=10;
                rep(l,1,5)hsh+=a[j][l]*hst,hst*=10;
                tng[hsh]++;
                a[j][i]+=10-k;a[j][i]%=10;
            }
        }
        rep(i,1,4){
            rep(k,1,9){
                LL hsh=0,hst=1;
                a[j][i]+=k;a[j][i]%=10;
                a[j][i+1]+=k;a[j][i+1]%=10;
                rep(l,1,5)hsh+=a[j][l]*hst,hst*=10;
                tng[hsh]++;
                a[j][i]+=10-k;a[j][i]%=10;
                a[j][i+1]+=10-k;a[j][i+1]%=10;
            }
        }
    }
    LL ans=0;
    rep(i,0,99999)if(tng[i]==N)ans++;
    cout<<ans<<"\n";
    return 0;
}
