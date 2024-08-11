#include<iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll n;
ll v[10][10];
ll test[10];
ll ans=0;
bool not_same(ll i){
    rep(j,1,5){
        if(v[i][j]!=test[j]){
            return true;
        }
    }
    return false;
}
ll len[15][15];
bool check(){
    ll num[10];
    bool type=false;
    rep(t,1,n){
        if(!not_same(t)){
            return false;
        }
        rep(i,1,5){
            num[i]=len[test[i]][v[t][i]];
        }
        bool use=false;
        rep(i,1,5){
            if(num[i]){
                if(use){
                    return false;
                }
                use=true;
                if(i<5&&num[i]==num[i+1]){
                    type=true;
                    num[i+1]=0;
                }
            }
        }
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    rep(i,0,9){
        rep(j,0,9){
            if(i<=j){
                len[i][j]=j-i;
            }else{
                len[i][j]=10-i+j;
            }
            //cout<<i<<" "<<j<<" "<<len[i][j]<<endl;
        }
    }
    scanf("%lld",&n);
    rep(i,1,n){
        rep(j,1,5){
            scanf("%lld",&v[i][j]);
        }
    }
    rep(a,0,9){
        rep(b,0,9){
            rep(c,0,9){
                rep(d,0,9){
                    rep(e,0,9){
                        test[1]=a;test[2]=b;test[3]=c;test[4]=d;test[5]=e;
                        if(check()){
                            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

