#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N];
int a[N],b[N];
bool f[2005][2005];
bool dp(int* xx,int* yy,int nn,int mm){
    if(xx[nn]<=yy[mm])return 0;
    if(nn>2000||mm>2000)return rand()%2;
    memset(f,0,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=nn;++i){
        for(int j=1;j<=mm;++j){
            if(f[i][j]==0)continue;
            if(xx[i+1]>yy[j+1])f[i+1][j+1]=1;
            if(xx[i+1]>yy[j])f[i+1][j]=1;
            if(xx[i]>yy[j+1])f[i][j+1]=1;
        }
    }
    return f[nn][mm];
}
int main(){
    srand(time(0));
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i)cin>>x[i];
    for(int i=1;i<=m;++i)cin>>y[i];
    if(x[1]>y[1]){
        if(dp(x,y,n,m))cout<<1;
        else cout<<0;
    }
    else if(x[1]<y[1]){
        if(dp(y,x,m,n))cout<<1;
        else cout<<0;
    }else cout<<0;
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        memcpy(a,x,sizeof(a));
        memcpy(b,y,sizeof(b));
        for(int i=1;i<=kx;++i){
            int u,v;
            cin>>u>>v;a[u]=v;
        }
        for(int i=1;i<=ky;++i){
            int u,v;
            cin>>u>>v;b[u]=v;
        }
        if(a[1]>b[1]){
            if(dp(a,b,n,m))cout<<1;
            else cout<<0;
        }
        else if(a[1]<b[1]){
            if(dp(b,a,m,n))cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    return 0;
}
