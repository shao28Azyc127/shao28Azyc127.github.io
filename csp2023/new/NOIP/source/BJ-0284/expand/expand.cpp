#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
//#define int long long
using namespace std;
const int N=5e5+5,F=2e3+5;
int c,n,m,q,px[N],py[N],x[N],y[N],kx,ky,p,v;
bool f[F][F];
bool good(int xp,int yp){
    if(x[xp]<=y[yp]) return false;
    if(xp<F&&yp<F){
        if(f[xp][yp]) return false;
        f[xp][yp]=true;
    }
    if(xp>n){
        return false;
    }
    if(yp==m&&xp==n){
        return true;
    }
    if(yp>m)
        return false;
    if(x[xp+1]>y[yp]&&good(xp+1,yp))
        return true;
    if(x[xp+1]>y[yp+1]&&good(xp+1,yp+1))
        return true;
    if(x[xp]>y[yp+1]&&good(xp,yp+1))
        return true;
    return false;
}
bool god(int xp,int yp){
    if(x[xp]>=y[yp]) return false;
    if(xp<F&&yp<F){
        if(f[xp][yp]) return false;
        f[xp][yp]=true;
    }
    if(xp>n){
        return false;
    }
    if(yp>=m&&xp>=n){
        return true;
    }
    if(yp>m)
        return false;
    //cout<<xp<<"-"<<yp<<endl;
    if(x[xp+1]<y[yp]){
        //cout<<"!!!\n";
        if(god(xp+1,yp))
            return true;
    }
    if(x[xp+1]<y[yp+1])
        if(god(xp+1,yp+1))
            return true;
    if(x[xp]<y[yp+1])
       if(god(xp,yp+1))
            return true;
    return false;
}
void cpy() {
    //memset(x,0,sizeof(x));
    //memset(y,0,sizeof(y));
    for(int i=1;i<=n;i++)
        x[i]=px[i];
    for(int i=1;i<=m;i++)
        y[i]=py[i];
}
signed main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>px[i];
    }
    for(int i=1;i<=m;i++){
        cin>>py[i];
    }
    cpy();
    if((x[1]>y[1]&&good(1,1))||(x[1]<y[1]&&god(1,1)))
        cout<<1;
    else
        cout<<0;

    while(q--){
        cin>>kx>>ky;
        cpy();
        for(int i=1;i<=kx;i++){
            cin>>p>>v;
            x[p]=v;
        }
        for(int i=1;i<=ky;i++){
            cin>>p>>v;
            y[p]=v;
        }
//        cout<<endl;
//        for(int i=1;i<=n;i++) cout<<x[i]<<" ";
//        cout<<endl;
//        for(int i=1;i<=m;i++) cout<<y[i]<<" ";
//        cout<<endl;
        for(int i=1;i<=min(n,F-1);i++){
            for(int j=1;j<=min(m,F-1);j++){
                f[i][j]=false;
            }
        }
        if((x[1]>y[1]&&good(1,1))||(x[1]<y[1]&&god(1,1)))
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
