# include<iostream>
# include<algorithm>
# include<cmath>
# include<queue>
# define endl "\n"
# define int long long
using namespace std;
const int maxn=20001, INF=100000001;
struct Node{
    int u, v, next;
}edge[maxn];
int n, m, k, head[maxn], dis[maxn], dp[maxn], vis[maxn], cnt=0;
queue<int> q;
void add(int u, int v) {
    cnt++;
    edge[cnt].u=u; edge[cnt].v=v; edge[cnt].next=head[u];
    head[u]=cnt;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        add(u, v);
    }
    for(int i=1; i<=n; i++) {
        dis[i]=INF; dp[i]=INF;
    }
    vis[1]=1;
    for(int i=head[1]; i; i=edge[i].next) {
        int v=edge[i].v;
        dis[v]=dp[v]=1;
    }
    for(int i=2; i<=n; i++) {
        int p, minn=INF;
        for(int i=1; i<=n; i++) {
            if(dis[i]<minn && vis[i]==0) {
                minn=dis[i];
                p=i;
            }
        }
        vis[p]=1;
        for(int i=head[p]; i; i=edge[i].next) {
            int v=edge[i].v;
            if(dis[v]==0) dis[v]=1;
            dp[v]=min(dp[p]+1, dp[v]);
        }
    }
    cout << dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
