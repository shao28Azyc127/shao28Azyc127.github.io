#include<cstdio>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct Node{
    ll a[6];
}t;
set<ll> s,s2;
ll f(Node tp){
    ll ans=0;
    for(ll i=1;i<=5;i++){
        ans*=10;ans+=tp.a[i];
    }
    return ans;
}
void check(ll tp,bool flag){
    if(!flag){
        s.insert(tp);
    }else if(s.count(tp)){
        s2.insert(tp);
    }
}
void work(Node tt,bool flag){
    Node tp=tt;
    for(ll j=1;j<=5;j++){
        for(ll k=0;k<=9;k++){
            if(k==t.a[j]){
                continue;
            }
            tp.a[j]=k;
            check(f(tp),flag);
            if(j<5){
                ll tp2=(tt.a[j+1]-tt.a[j]+k+10)%10;
                tp.a[j+1]=tp2;
                check(f(tp),flag);
                tp.a[j+1]=tt.a[j+1];
            }
            tp.a[j]=tt.a[j];
        }
    }
}
void read(){
    for(ll i=1;i<=5;i++){
        scanf("%lld",&t.a[i]);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    read(),work(t,0);
    Node tp3;
    for(ll i=2;i<=n;i++){
        s2.clear();
        read(),work(t,1);
        s=s2;
    }
    printf("%lld",ll(s.size()));
    return 0;
}
