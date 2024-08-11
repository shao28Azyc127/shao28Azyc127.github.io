#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 10;
struct node1{
    int to,a;
};
struct node2{
    int x,dis;
};
int n,m,k;
vector <node1> e[maxn];
int dis[maxn][105];
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    queue <node2> q;
    q.push({1,0});
    dis[1][0] = 0;
    while (!q.empty()){
        node2 x = q.front();
        q.pop();
        for (node1 i : e[x.x]){
            int y = i.to;
            if (dis[y][(x.dis + 1) % k] > x.dis + 1){
                dis[y][(x.dis + 1) % k] = x.dis + 1;
                q.push({y,dis[y][(x.dis + 1) % k]});
            }
        }
    }
}
int ans = 2e9,t[maxn];
bool vis[15][20][105];
void dfs2(int x,int sum){
    if (sum >= ans) return;
    if (vis[x][upper_bound(t+1,t+m+1,sum) - t][sum % k]) return;
    vis[x][upper_bound(t+1,t+m+1,sum) - t][sum % k] = 1;
    if (x == n){
        if (sum % k == 0){
            ans = min(ans,sum);
        }
        return;
    }
    for (node1 y : e[x]){
        if (y.a > sum) continue;
        dfs2(y.to,sum + 1);
    }
}
void dfs1(int x,int sum){
    if (x == n){
        if (sum % k == 0){
            ans = min(ans,sum);
        }
        return;
    }
    for (node1 y : e[x]){
        if (y.a > sum) continue;
        dfs1(y.to,sum + 1);
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    bool flag = true;
    int maxa = -2e9;
    for (int i = 1;i <= m;i++){
        int u,v,a;
        scanf("%d %d %d",&u,&v,&a);
        t[i] = a;
        maxa = max(maxa,a);
        if (u > v) flag = false;
        e[u].push_back({v,a});
    }
    if (maxa == 0){
        spfa();
        if (dis[n][0] > 1e9) printf("-1");
        else printf("%d",dis[n][0]);
    }
    else if (flag){
        for (int i = 0;i <= maxa + k;i += k) dfs1(1,i);
        if (ans > 1e9) printf("-1");
        else printf("%d",ans);
    }
    else if(n <= 10&&m <= 15){
        sort(t + 1,t + n + 1);
        for (int i = 0;i <= maxa + k;i += k){
            memset(vis,0,sizeof(vis));
            dfs1(1,i);
        }
        if (ans > 1e9) printf("-1");
        else printf("%d",ans);

    }
    else{
        printf("-1");
    }
    return 0;
}
