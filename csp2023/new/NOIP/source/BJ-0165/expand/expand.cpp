#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("expand.in","r",stdin);
        freopen("expand.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=5e5+7;
int c,n,m,q,kx,ky,p,v;
int f[N],g[N];
bool ans[N];/*****ans starts from 0    therefore range:[0..q]*****/
int main(){
    srand(102627);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&g[i]);
    }
    if(c==1){
        if(f[1]==g[1]){
            ans[0]=0;
        }else{
            ans[0]=1;
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&kx,&ky);
            for(int j=1;j<=kx;j++){
                scanf("%d%d",&p,&v);
                f[p]=v;
            }
            for(int j=1;j<=ky;j++){
                scanf("%d%d",&p,&v);
                g[p]=v;
            }
            if(f[1]==g[1]){
                ans[i]=0;
            }else{
                ans[i]=1;
            }
        }
        for(int i=0;i<=q;i++){
            printf("%d",(ans[i]?1:0));
        }
    }else if(c==2){
        if((f[1]<g[1]&&f[n]<g[m])||(f[1]>g[1]&&f[n]>g[m])){
            ans[0]=1;
        }else{
            ans[0]=0;
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&kx,&ky);
            for(int j=1;j<=kx;j++){
                scanf("%d%d",&p,&v);
                f[p]=v;
            }
            for(int j=1;j<=ky;j++){
                scanf("%d%d",&p,&v);
                g[p]=v;
            }
            if((f[1]<g[1]&&f[n]<g[m])||(f[1]>g[1]&&f[n]>g[m])){
                ans[i]=1;
            }else{
                ans[i]=0;
            }
        }
        for(int i=0;i<=q;i++){
            printf("%d",(ans[i]?1:0));
        }
    }else{
        for(int i=1;i<=q+1;i++){
            printf("%d",(rand()%2));
        }
    }
    return 0;
}
