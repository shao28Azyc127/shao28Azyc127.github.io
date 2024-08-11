#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,x[N],y[N],x0[N],yy[N],kx,ky,cnt;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)   scanf("%d",&x0[i]);
    for(int i=1;i<=m;i++)   scanf("%d",&yy[i]);
    for(int T=0;T<=q;T++){
        cnt=0;
        for(int i=1;i<=n;i++)   x[i]=x0[i];
        for(int i=1;i<=m;i++)   y[i]=yy[i];
        if(T){
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=kx;i++){
                int px,vx;
                scanf("%d%d",&px,&vx);
                x[px]=vx;
            }
            for(int i=1;i<=ky;i++){
                int py,vy;
                scanf("%d%d",&py,&vy);
                y[py]=vy;
            }
        }
        if(x[1]==y[1]){
            printf("0");
            continue;
        }
        if(x[n]==y[m]){
            printf("0");
            continue;
        }
        if((x[1]<y[1])&&(x[n]>y[n])){
            printf("0");
            continue;
        }
        if((x[1]>y[1])&&(x[n]<y[n])){
            printf("0");
            continue;
        }
        printf("1");
    }
    return 0;
}
