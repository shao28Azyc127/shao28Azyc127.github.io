#include<bits/stdc++.h>

using namespace std;

const int NR=2005;

int n,m,q,N,M;
int a[NR],b[NR],ta[NR],tb[NR],t1[NR],t2[NR];
bool f[NR][NR];

void work(){
    if(ta[1]==tb[1]){
        printf("0");
        return;
    }
    if(ta[1]>tb[1]){
        n=N; m=M;
        for(int i=1;i<=n;i++) a[i]=ta[i];
        for(int i=1;i<=m;i++) b[i]=tb[i];
    }
    else{
        n=M; m=N;
        for(int i=1;i<=n;i++) a[i]=tb[i];
        for(int i=1;i<=m;i++) b[i]=ta[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) f[i][j]=0;
    }
    f[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]>b[j]) f[i][j]|=(f[i][j-1]||f[i-1][j]||f[i-1][j-1]);
        }
    }
    if(f[n][m]) printf("1");
    else printf("0");
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int C;
    scanf("%d%d%d%d",&C,&N,&M,&q);
    for(int i=1;i<=N;i++){
        scanf("%d",ta+i);
        t1[i]=ta[i];
    }
    for(int i=1;i<=M;i++){
        scanf("%d",tb+i);
        t2[i]=tb[i];
    }
    work();
    while(q--){
        for(int i=1;i<=N;i++) ta[i]=t1[i];
        for(int i=1;i<=M;i++) tb[i]=t2[i];
        int kx,ky; scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            ta[p]=v;
        }
        for(int i=1;i<=ky;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            tb[p]=v;
        }
        work();
    }
    printf("\n");
    return 0;
}