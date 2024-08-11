#include<bits/stdc++.h>
using namespace std;
const int MXN=5e3+10;
int c,n,m,q;
int x[MXN],y[MXN],lx[MXN],ly[MXN];
bitset<MXN> f[MXN];
bool check1(){
    memset(f,0,sizeof(f));
    f[0][0]=1;
    //cout<<'@'<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;j-k>=1&&x[i]>y[j-k];k++){
                f[i][j]=f[i-1][j-k-1]||f[i-1][j-k];
                if(f[i][j]) break;
            }
            //cout<<f[i][j]<<' ';
        }
        //cout<<'\n';
    }
    return f[n][m];
}
bool check2(){
    memset(f,0,sizeof(f));
    f[0][0]=1;
    //cout<<'#'<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;j-k>=1&&x[i]<y[j-k];k++){
                f[i][j]=f[i-1][j-k-1]||f[i-1][j-k];
                if(f[i][j]) break;
            }
            //cout<<f[i][j]<<' ';
        }
        //cout<<'\n';
    }
    return f[n][m];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>lx[i];
        x[i]=lx[i];
    }
    for(int i=1;i<=m;i++){
        cin>>ly[i];
        y[i]=ly[i];
    }
    //cout<<x[n-1]<<' '<<y[m-1]<<'\n';
    if(check1()||check2()) cout<<1;
    else cout<<0;
    for(int i=1,kx,ky;i<=q;i++){
        for(int i=1;i<=n;i++){
            x[i]=lx[i];
        }
        for(int i=1;i<=m;i++){
            y[i]=ly[i];
        }
        cin>>kx>>ky;
        for(int j=1,p,v;j<=kx;j++){
            cin>>p>>v;
            x[p]=v;
            //cout<<p<<' '<<x[p]<<'\n';
        }
        for(int j=1,p,v;j<=ky;j++){
            cin>>p>>v;
            y[p]=v;
            //cout<<p<<' '<<y[p]<<'\n';
        }
        if(check1()||check2()) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
    //cout<<n<<' '<<m<<'\n';
    return 0;
}