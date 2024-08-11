#include<iostream>
#include<map>
#define rep(i,n) for(int i=1;i<=n;++i)
#define reb(i,n) for(int i=0;i<n;++i)
#define int long long
using namespace std;
const int N=8;
map<int,int>mp;
int a[N],b[N],n,ans;
int turn(){
    int s=0;
    reb(i,n)s=s*10+b[i];
    return s;
}
main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T;cin>>T;
    rep(yyy,T){
    n=5;
    reb(i,n)cin>>a[i];
    reb(i,n){
        reb(i,n)b[i]=a[i];
        reb(j,10)
        if(j!=a[i]){
            b[i]=j;
            int k=turn();
            mp[k]++;
        }
    }
    reb(i,n-1){
        reb(i,n)b[i]=a[i];
        rep(j,9){
            b[i]++;b[i+1]++;
            b[i]%=10;b[i+1]%=10;
            int k=turn();
            mp[k]++;
        }
    }
    }
    for(auto v:mp)
    if(v.second==T)++ans;
    cout<<ans;
    return 0;
}
