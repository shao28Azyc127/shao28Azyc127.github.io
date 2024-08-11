#include <iostream>
#include <cstring>
using namespace std;
const int N=2010;
int a[N],b[N];
int x[N],y[N];
bool vis[N][N];
int f[N][N];
int c,n,m,q;
bool solve(){
    if(x[1]<y[1]) swap(x,y);
    if(x[1]==y[1]) return false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]>y[j]) vis[i][j]=true;
        }
    }
    memset(f,0,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) continue;
            if(vis[j][i]){
                f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i][j-1]));
            }
        }
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<f[j][i];
        }
        cout<<endl;
    }*/
    if(f[m][n]) return true;
    else return false;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        y[i]=b[i];
    }
    cout<<solve();
    while(q--){
        for(int i=1;i<=n;i++) x[i]=a[i];
        for(int i=1;i<=m;i++) y[i]=b[i];
        int kx,ky,p,v;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            cin>>p>>v;
            x[p]=v;
        }
        for(int i=1;i<=ky;i++){
            cin>>p>>v;
            y[p]=v;
        }
        memset(vis,false,sizeof(vis));
        cout<<solve();
    }
    cout<<endl;
    return 0;
}
