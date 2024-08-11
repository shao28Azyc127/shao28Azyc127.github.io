#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,q;
int a[500010],b[500010],na[500010],nb[500010];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    if(c==1||(n==1&&m==1)){
        if(a[1]!=b[1]){
            printf("1");
        }else{
            printf("0");
        }
    }else if(c==2){
        if(n==2&&m==1){
            if(a[1]>b[1]&&a[2]>b[1]){
                printf("1");
            }else if(a[1]<b[1]&&a[2]<b[1]){
                printf("1");
            }else{
                printf("0");
            }
        }else if(n==1&&m==2){
            if(b[1]>a[1]&&b[2]>a[1]){
                printf("1");
            }else if(b[1]<a[1]&&b[2]<a[1]){
                printf("1");
            }else{
                printf("0");
            }
        }else{
            if(a[1]>b[1]&&a[2]>b[2]){
                printf("1");
            }else if(a[1]<b[1]&&a[2]<b[2]){
                printf("1");
            }else{
                printf("0");
            }
        }
    }else{
        printf("0");
    }

    while(q--){
        for(int i=1;i<=n;i++){
            na[i]=a[i];
        }
        for(int i=1;i<=m;i++){
            nb[i]=b[i];
        }
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,u;
            scanf("%d%d",&p,&u);
            na[p]=u;
        }
        for(int i=1;i<=ky;i++){
            int p,u;
            scanf("%d%d",&p,&u);
            nb[p]=u;
        }
        if(c==1||(n==1&&m==1)){
            if(na[1]!=nb[1]){
                printf("1");
            }else{
                printf("0");
            }
        }else if(c==2){
            if(n==2&&m==1){
                if(na[1]>nb[1]&&na[2]>nb[1]){
                    printf("1");
                }else if(na[1]<nb[1]&&na[2]<nb[1]){
                    printf("1");
                }else{
                    printf("0");
                }
            }else if(n==1&&m==2){
                if(nb[1]>na[1]&&nb[2]>na[1]){
                    printf("1");
                }else if(nb[1]<na[1]&&nb[2]<na[1]){
                    printf("1");
                }else{
                    printf("0");
                }
            }else{
                if(na[1]>nb[1]&&na[2]>nb[2]){
                    printf("1");
                }else if(na[1]<nb[1]&&na[2]<nb[2]){
                    printf("1");
                }else{
                    printf("0");
                }
            }
        }else{
            printf("0");
        }
    }
    return 0;
}
