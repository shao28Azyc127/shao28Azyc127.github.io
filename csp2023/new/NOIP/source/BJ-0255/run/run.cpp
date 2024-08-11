#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
ll f[2050][2050];
ll bks[2050][2050];
ll mxf[2050];
void init(){
    for(int i=1;i<=2000;i++)for(int j=1;j<=2000;j++) f[i][j]=-1e11;
    for(int i=1;i<=2000;i++)for(int j=1;j<=2000;j++) bks[i][j]=0;
    for(int i=1;i<=2000;i++)mxf[i]=-1e11;
}int n,m,k,d;
void input(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    for(int i=1;i<=m;i++){
        int lt,rt,s;
        scanf("%lld%lld%lld",&lt,&rt,&s);
        bks[lt-rt+1][lt]+=s;
    }for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            bks[j][i]+=bks[j+1][i]-d;
        }//cout<<bks[1][2]<<' ';
    }
}void dp(){
    for(int i=1;i<=k;i++) f[0][i]=0;
    mxf[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j>0) f[i][j]=max(f[i][j],f[i-1][j-1]-d);
            if(j==0) for(int it=i-1;it>=0;it--)f[i][j]=max(f[i][j],mxf[i-1]);
            for(int it=i-1;it>=max(i-j,0ll);it--){
                f[i][j]=max(f[i][j],f[it][j-i+it]+bks[it+1][i]);
            }mxf[i]=max(mxf[i],f[i][j]);
            //cout<<f[i][j]<<' ';
        }//cout<<endl;
    }
}void output(){
    ll ans=-1e9;
    for(int i=0;i<=k;i++) ans=max(f[n][i],ans);
    cout<<ans<<'\n';
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int sub;
    int _;
    cin>>sub>>_;
    while(_--){
        init();
        input();
        dp();
        output();
    }
    return 0;
}
