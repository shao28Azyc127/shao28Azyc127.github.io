#include<bits/stdc++.h>
#define N 500005
using namespace std;
using ll=long long;
int x[N],y[N],nx[N],ny[N];
int c,n,m,q,len;
ll subOfSum=0,negSum=0;
bool solve(){
    int ptx=1,pty=1;
    while(1){
        if(x[ptx]*x[pty]+y[ptx]*y[pty]>x[ptx]*y[pty]+y[ptx]*x[pty]){
            //cout<<x[ptx]*x[pty]+y[ptx]*y[pty]<<' '<<x[ptx]*y[pty]+y[ptx]*x[pty]<<endl;
            pty++;
        }else{
            ptx++;
            if(ptx<=pty){
                if(pty==min(n,m)){
                    if(pty-ptx<=1) return true;
                    else return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]),nx[i]=x[i];
    for(int i=1;i<=m;i++)
        scanf("%d",&y[i]),ny[i]=y[i];
    len=max(n,m);
    if(n>m){
        for(int i=m+1;i<=n;i++){
            ny[i]=y[i]=y[m];
        }
    }
    if(m>n){
        for(int i=n+1;i<=m;i++){
            nx[i]=x[i]=x[n];
        }
    }
    if(solve()){
        putchar('1');
    }else putchar('0');
    int kx,ky;
    int px,vx;
    while(q--){
        memcpy(x,nx,len+2);
        memcpy(y,ny,len+2);
        scanf("%d%d",&kx,&ky);
        while(kx--){
            scanf("%d%d",&px,&vx);
            x[px]=vx;
        }
        while(ky--){
            scanf("%d%d",&px,&vx);
            y[px]=vx;
        }
        if(solve()){
        putchar('1');
        }else putchar('0');
    }
    /*
    ll tmpNegSum;
    int kx,ky;
    int px,vx;
    while(q--){
        tmpNegSum=negSum;
        scanf("%d%d",&kx,&ky);
        while(kx--){
            scanf("%d%d",&px,&vx);
            tmpSum-=(vx-x[px])&1;
        }
        while(ky--){
            scanf("%d%d",&px,&vx);
            tmpSum-=(vx-y[px])&1;
        }
    }
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
