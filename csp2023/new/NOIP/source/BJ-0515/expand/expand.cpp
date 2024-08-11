#include <iostream>
using namespace std;
const int len=5e5+10;
int c,n,m,q;
int x[len],y[len],x0[len],y0[len],ans[61];
void ini(){
    for(int i=1;i<=n;i++) x0[i]=x[i];
    for(int i=1;i<=m;i++) y0[i]=y[i];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout):
    int cnt=1;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    if(c==1){
        if(x[1]!=y[1]) ans[0]=1;
        else ans[0]=0;
    }
    if(c==2){
        //printf("x1=%d,x2=%d,y1=%d,y2=%d",x[1],x[2],y[1],y[2]);
        ans[0]=0;
        if((x[1]>y[1])&&(x[1]>y[2])&&(x[2]>y[2])) ans[0]=1;
        if((x[1]<y[1])&&(x[1]<y[2])&&(x[2]<y[2])) ans[0]=1;
    }
    for(int i=0;i<q;i++){
        ini();
        int kx,ky,p,v;
        cin>>kx>>ky;
        for(int j=0;j<kx;j++){
            cin>>p>>v;
            x0[p]=v;
        }
        for(int j=0;j<ky;j++){
            cin>>p>>v;
            y0[p]=v;
        }
        if(c==1){
            if(x0[1]!=y0[1]) ans[cnt]=1;
            else ans[cnt]=0;
            cnt++;
        }
        if(c==2){
            if((x0[1]>y0[1])&&(x0[1]>y0[2])&&(x0[2]>y0[2])) ans[cnt]=1;
            if((x0[1]<y0[1])&&(x0[1]<y0[2])&&(x0[2]<y0[2])) ans[cnt]=1;
            else ans[cnt]=0;
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++) cout<<ans[i];
    return 0;
}
