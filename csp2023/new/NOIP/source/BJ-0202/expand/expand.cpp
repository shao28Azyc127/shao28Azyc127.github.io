#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
#define per(i,x,y) for(LL i=(x);i>=(y);i--)
#define all(x) x.begin(),x.end()
#define vi vector<LL>
#define pb push_back
#define pii pair<LL,LL>
#define fi first
#define se second
#define mp make_pair
LL c,N,M,Q,x[514514],y[514514],xt[2005],yt[2005];
vector<pii >qx,qy;
LL chk0(){
    if(x[1]<=y[1]&&x[N]>=y[M])return 0;
    if(x[1]>=y[1]&&x[N]<=y[M])return 0;
    LL n=N,m=M;
    if(x[1]>y[1]){rep(i,1,n)xt[i]=x[i];rep(i,1,m)yt[i]=y[i];}
    else {swap(n,m);rep(i,1,n)xt[i]=y[i];rep(i,1,m)yt[i]=x[i];}
    LL j=1;
    rep(i,1,n){
        while(j<m&&yt[j+1]<xt[i]&&yt[j]<xt[i])j++;
        while(j&&yt[j]>=xt[i])j--;
        if(!j)return 0;
    }
    if(j==m)return 1;
    return 0;
}
void solve0(){
    rep(i,1,N)cin>>x[i];rep(i,1,M)cin>>y[i];
    cout<<chk0();
    while(Q--){
        qx.clear();qy.clear();LL kx,ky;cin>>kx>>ky;
        while(kx--){LL i,v;cin>>i>>v;qx.pb(mp(i,x[i]));x[i]=v;}
        while(ky--){LL i,v;cin>>i>>v;qy.pb(mp(i,y[i]));y[i]=v;}
        cout<<chk0();
        for(pii i:qx)x[i.fi]=i.se;
        for(pii i:qy)y[i.fi]=i.se;
    }
    cout<<'\n';
}
LL chk1(){
    LL mxy=y[1],mnx=x[1];
    LL r=1;rep(i,1,N){
        mnx=min(mnx,x[i]);
        while(x[i]>mxy){
            if(r==M)return 0;
            if(y[r+1]<=mnx)return 0;
            r++;mxy=max(mxy,y[r]);
        }
    }
    return 1;
}
void solve1(){
    rep(i,1,N)cin>>x[i];rep(i,1,M)cin>>y[i];
    cout<<chk1();
    while(Q--){
        qx.clear();qy.clear();LL kx,ky;cin>>kx>>ky;
        while(kx--){LL i,v;cin>>i>>v;qx.pb(mp(i,x[i]));x[i]=v;}
        while(ky--){LL i,v;cin>>i>>v;qy.pb(mp(i,y[i]));y[i]=v;}
        cout<<chk1();
        for(pii i:qx)x[i.fi]=i.se;
        for(pii i:qy)y[i.fi]=i.se;
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
    cin>>c>>N>>M>>Q;
    if(c<=7){solve0();return 0;}
    if(c<=14){solve1();return 0;}
    return 0;
}
//What do you want,merc?Blood and gold,or a broken throne?
