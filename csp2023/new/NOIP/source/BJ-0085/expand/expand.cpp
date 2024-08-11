#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int ox[500005],oy[500005];
bool dfs1(int i,int j){
    if(i>n&&j>m) return true;
    if(i>n||j>m) return false;
    if(y[j]>=x[i]) return false;
    int k=j;
    while(k<=m&&y[k]<x[i]) k++;
    for(int a=j;a<=k;a++){
        bool f=dfs1(i+1,a);
        if(f) return true;
    }
    return false;
}
bool dfs2(int i,int j){
    if(i>=n&&j>=m) return true;
    if(i>n||j>m) return false;
    if(y[j]<=x[i]) return false;
    int k=j;
    while(k<=m&&y[k]>x[i]) k++;
    for(int a=j;a<=k;a++){
        bool f=dfs2(i+1,a);
        if(f) return true;
    }
    return false;
}
int main(){
    #ifndef JZQ
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    #endif
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    memcpy(ox,x,sizeof(ox));
    memcpy(oy,y,sizeof(oy));
    // for(int i=1;i<=n;i++) printf("%d ",x[i]);
    // printf("\n");
    // for(int i=1;i<=m;i++) printf("%d ",y[i]);
    // printf("\n");
    // dfs1(1,1)||dfs2(1,1);
    // printf("hello\n");
    printf("%d",dfs1(1,1)||dfs2(1,1));
    while(q--){
        memcpy(x,ox,sizeof(ox));
        memcpy(y,oy,sizeof(oy));
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            x[p]=v;
        }
        for(int i=1;i<=ky;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            y[p]=v;
        }
        // for(int i=1;i<=n;i++) printf("%09d ",x[i]);
        // printf("\n");
        // for(int i=1;i<=m;i++) printf("%09d ",y[i]);
        // printf("\n");
        // dfs1(1,1);
        // printf("hello\n");
        printf("%d",dfs1(1,1)||dfs2(1,1));
    }
    return 0;
}