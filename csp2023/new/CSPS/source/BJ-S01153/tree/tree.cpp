#include<bits/stdc++.h>
using namespace std;
int const N = 1e5+5;
int n,ans;
struct Edge{
    int v,nex;
}e[N];
int head[N],ecnt;
void addedge(int u,int v){
    e[ecnt++] = Edge{v,head[u]};
    head[u] = ecnt;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int a[N],b[N],c[N];
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    for(int i=head[1];i!=0;i =e[i].nex){
        int dot = e[i].v;
        ans+=1;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
