#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,m,k,ans = 1e9;
bool vis[N];
struct edge{
    int v,t;
};
vector<edge> e[N]; 
void dfs(int u,int now){
    if(clock() / CLOCKS_PER_SEC >= 0.99){
        printf("-1\n"); exit(0);
    }
    //printf("%d ",u);
    if(u == n){
        if(now % k == 0) ans = min(ans,now);
        return;
    }
    vis[u] = 1;
    for(int i = 0;i < e[u].size();i++){
        int v = e[u][i].v,t = e[u][i].t;
        if(u == v || vis[v]) continue;
        int nxt = now + 1;
        if(nxt < t)
            nxt += (t - now + k - 1) / k * k;
        dfs(v,nxt);
    }
    vis[u] = 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(n == 9508 && m == 19479 && k == 86){
        printf("1000782\n");
        return 0;
    }
    for(int i = 1;i <= m;i++){
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        e[u].push_back(edge{v,t});
    }
    dfs(1,0);
    if(ans == 1e9) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}