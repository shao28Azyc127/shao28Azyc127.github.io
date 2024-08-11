#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int c,n,m,q,a[N],b[N],aa[N],bb[N];

void work1(){
    if(a[1]!=b[1]) printf("1");
    else printf("0");
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        memcpy(aa,a,sizeof(a));
        memcpy(bb,b,sizeof(b));
        while(x--){
            int x1,c1;
            scanf("%d%d",&x1,&c1);
            aa[x1]=c1;
        }
        while(y--){
            int y1,c1;
            scanf("%d%d",&y1,&c1);
            bb[y1]=c1;
        }
        if(aa[1]!=bb[1]) printf("1");
        else printf("0");
    }
}

void check(){
    if(aa[1]<bb[1] && aa[2]<bb[2]){
        printf("1");
        return;
    }
    if(aa[1]>bb[1] && aa[2]>bb[2]){
        printf("1");
        return;
    }
    printf("0");
}

void work2(){
    memcpy(aa,a,sizeof(a));
    memcpy(bb,b,sizeof(b));
    check();
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        memcpy(aa,a,sizeof(a));
        memcpy(bb,b,sizeof(b));
        while(x--){
            int x1,c1;
            scanf("%d%d",&x1,&c1);
            aa[x1]=c1;
        }
        while(y--){
            int y1,c1;
            scanf("%d%d",&y1,&c1);
            bb[y1]=c1;
        }
        check();
    }
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=m;++i) scanf("%d",&b[i]);
    if(c==1){
        work1();
    }
    else if(c==2){
        work2();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}