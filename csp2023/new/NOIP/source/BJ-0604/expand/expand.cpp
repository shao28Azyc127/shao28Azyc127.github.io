#include <iostream>
using namespace std;
int c,n,m,q;
int x[500005];
int y[500005];
int x2[500005];
int y2[500005];
int kx,ky;
int xpx,vx,ypy,vy;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) {cin>>x[i];x2[i]=x[i];}
    for(int j=1;j<=m;j++) {cin>>y[j];y2[j]=y[j];}
    if(c==1){
        for(int i=1;i<=q+1;i++) cout<<'1';
    }
    else if(c==2){
        if((x[1]-y[1])*(x[2]-y[2])>0) cout<<'1';
        else cout<<'0';
        for(int i=1;i<=q;i++){
            for(int j=1;j<=n;j++) x2[j]=x[j];
            for(int j=1;j<=m;j++) y2[j]=y[j];
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++){
                cin>>xpx>>vx;
                x2[xpx]=vx;
            }
            for(int j=1;j<=ky;j++){
                cin>>ypy>>vy;
                y2[ypy]=vy;
            }
            if((x2[1]-y2[1])*(x2[2]-y2[2])>0) cout<<'1';
            else cout<<'0';
        }
    }
    return 0;
}