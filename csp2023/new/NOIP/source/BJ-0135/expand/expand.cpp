#include <cstdio>
int ysa[107],ysb[107],a[107],b[107];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&ysa[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&ysb[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]=ysa[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=ysb[i];
    }
    if(a[1]==b[1]){
        printf("0");
    }else if(n==1){
        printf("1");
    }else if(n<=2 && m<=2){
        if(a[1]<b[1] && a[n]<b[m]) printf("1");
        else if(a[1]>b[1] && a[n]>b[m]) printf("1");
        else printf("0");
    }else printf("0");
    for(int i=1;i<=q;i++){
        for(int i=1;i<=n;i++){
            a[i]=ysa[i];
        }
        for(int i=1;i<=m;i++){
            b[i]=ysb[i];
        }
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int j=1;j<=kx;j++){
            int p,v;
            scanf("%d%d",&p,&v);
            a[p]=v;
        }
        for(int j=1;j<=ky;j++){
            int p,v;
            scanf("%d%d",&p,&v);
            b[p]=v;
        }
        if(a[1]==b[1]){
            printf("0");
            continue;
        }
        if(n==1){
            printf("1");
            continue;
        }
        if(n<=2 && m<=2){
            if(a[1]<b[1] && a[n]<b[m]) printf("1");
            else if(a[1]>b[1] && a[n]>b[m]) printf("1");
            else printf("0");
            continue;
        }
        printf("0");
    }
    return 0;
}