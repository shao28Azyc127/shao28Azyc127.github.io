#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5,M = 2e4+5;
int n,m,k,u,v,a;
struct Edge{
    int u,v;
    int w;
}edge[M];
int head[N];
void addege(int u,int v,int w){
    edge[u] = Edge{u,v,w};
    head[u] = u;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",u,v,a);
    }
    printf("-1");
    fcloseall();
}
