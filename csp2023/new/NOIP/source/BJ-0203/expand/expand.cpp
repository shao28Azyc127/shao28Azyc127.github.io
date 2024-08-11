#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+5;
int x[N],y[N],a[N],b[N],topx,topy,ox[N],oy[N];
int c,n,m,q;
stack<int> xx,yy;
int dp[2005][2005];
inline void work() {
    reverse(x+1,x+n+1);
    reverse(y+1,y+m+1);
    bool ok=0;
    if(x[1]>y[1]) ok=1;
    else if(x[1]==y[1]) {
        cout<<0;
        return ;
    }
    if(ok) {
        swap(x,y);
        swap(n,m);
    }
    rep(i,1,n) rep(j,1,m) dp[i][j]=0;
    dp[1][1]=1;
    rep(i,1,n) rep(j,1,m) {
        if(dp[i][j]) {
            if(x[i]<y[j+1]) dp[i][j+1]=1;
            if(x[i+1]<y[j]) dp[i+1][j]=1;
        }
    }
    //rep(i,1,n) {
    //    rep(j,1,m) cout<<dp[i][j]<<' ';
    //}
    //cout<<endl;
    cout<<dp[n][m];
    if(ok) {
        swap(x,y);
        swap(n,m);
    }
    reverse(x+1,x+n+1);
    reverse(y+1,y+m+1);
}
void work1() {

}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    rep(i,1,n) cin>>x[i],ox[i]=x[i];
    rep(i,1,m) cin>>y[i],oy[i]=y[i];
    if(n<=2000&&m<=2000)
    work();
    else work1();
    //return 0;
    while(q--) {
        rep(i,1,n) x[i]=ox[i];
        rep(i,1,m) y[i]=oy[i];
        int kx,ky;
        cin>>kx>>ky;
        rep(i,1,kx) {
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        rep(i,1,ky) {
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        //rep(i,1,n) cout<<x[i]<<' ';
        //cout<<endl;
        //rep(i,1,m) cout<<y[i]<<' ';
        //cout<<endl;
    if(n<=2000&&m<=2000)
    work();
    else work1();
    }
    return 0;
}
