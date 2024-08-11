#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[2000],v[2000],a[2000],t=0,mt=10005,way=1;
bool vis[10005]={false};
void dfs(){
    if(way==n){
        mt=min(t,mt);
        return;
    }
    for(int i=0;i<m;i++){
        if(u[i]==way&&vis[v[i]]!=true){
            vis[way]=true;
            way=v[i];
            t++;
            dfs();
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    bool f=false,b=false;
    scanf("%d%d%d",&n,&m,&k);
    if(k>1||k<0||n<0||n>1000||m<0||m>2000)
        printf("-1");
    else{
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u[i],&v[i],&a[i]);
        }
        for(int i=0;i<m;i++){
            if(v[i]==n){
                b=true;
            }
            if(u[i]==1){
                f=true;
            }
        }
        if(!b||!f)
            printf("-1");
        dfs();
    }
    printf("%d\n",mt);
    return 0;
}
