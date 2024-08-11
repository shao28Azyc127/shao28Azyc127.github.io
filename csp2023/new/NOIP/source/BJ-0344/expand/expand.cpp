#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500002],y[500002],x1[500002],yy[500002];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&y[i]);
    }
    bool flag;
    flag=true;
    int px=1,py=1,f,maxn=x[1],maxp=1,kx,ky,u,v;
    if(x[1]-y[1]<0) f=-1;
    else if(x[1]-y[1]>0) f=1;
    if(1ll*(x[1]-y[1])*(x[n]-y[m])<=0) flag=false;
    while(px<=n&&py<=m){
        if(!flag) break;
        if((x[px]-y[py])*f>0){
            if(px<n) ++px;
            else ++py;
        }
        else{
            if((x[maxp]-y[py])*f<=0){
                flag=false;
                break;
            }
            else{
                while(px--){
                    if((x[px]-y[py])*f>0) break;
                }
                ++py;
                if(py>m&&px!=n){
                    flag=false;
                    break;
                }
            }
        }
        if(f==1&&x[px]>maxn){
            maxn=x[px];
            maxp=px;
        }
        else if(f==-1&&x[px]<maxn){
            maxn=x[px];
            maxp=px;
        }
    }
    if(flag) printf("1");
    else printf("0");
    for(int i=1;i<=n;++i){
        x1[i]=x[i];
    }
    for(int i=1;i<=m;++i){
        yy[i]=y[i];
    }
    while(q--){
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;++i){
            scanf("%d%d",&u,&v);
            x1[u]=v;
        }
        for(int i=1;i<=ky;++i){
            scanf("%d%d",&u,&v);
            yy[u]=v;
        }
        flag=true;
        px=1;py=1;maxn=x1[1];maxp=1;
        if(x1[1]-yy[1]<0) f=-1;
        else if(x1[1]-yy[1]>0) f=1;
        if(1ll*(x1[1]-yy[1])*(x1[n]-yy[m])<=0) flag=false;
        while(px<=n&&py<=m){
            if(!flag) break;
            if((x1[px]-yy[py])*f>0){
                if(px<n) ++px;
                else ++py;
            }
            else{
                if((x1[maxp]-yy[py])*f<=0){
                    flag=false;
                    break;
                }
                else{
                    while(px--){
                        if((x1[px]-yy[py])*f>0) break;
                    }
                    ++py;
                    if(py>m&&px!=n){
                        flag=false;
                        break;
                    }
                }
            }
            if(f==1&&x1[px]>maxn){
                maxn=x1[px];
                maxp=px;
            }
            else if(f==-1&&x1[px]<maxn){
                maxn=x1[px];
                maxp=px;
            }
        }
        if(flag) printf("1");
        else printf("0");
        for(int i=1;i<=n;++i){
            x1[i]=x[i];
        }
        for(int i=1;i<=m;++i){
            yy[i]=y[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
