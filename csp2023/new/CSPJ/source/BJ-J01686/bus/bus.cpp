#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans = INT_MAX,anst;
int dis[10005];
map<int,map<int,bool> > vis;
struct node{
    int x,w;
    bool operator < (const node &b) const{
        return b.w<w;
    }
};
struct edge{
    int x,w,mx;
};
vector<node> v[10005];
int tran(int x){
    return x%k==0 ? x : (x/k+1)*k;
}
void bfs(){
    queue<edge> que;
    que.push((edge){1,0});
    vis[1][0] = 1;
    while(!que.empty()){
        edge t = que.front();
        que.pop();
        if(t.w+t.mx>=ans){
            continue;
        }
        if(t.x==n){
            if(t.w%k==0){
                if(t.w+t.mx<ans){
                    ans = t.w+t.mx;
                }
            }
            continue;
        }
        for(auto y:v[t.x]){
            int d = t.w+1;
            if(!vis[y.x][d]){
                que.push((edge){y.x,d,max(y.w,t.mx)});
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    bool flag = 0,flag2 = 0;
    for(int i=1;i<=m;i++){
        int u,w,d;
        cin >> u >> w >> d;
        v[u].push_back((node){w,d});
        if(d!=0){
            flag = 1;
        }
        if(u>=w){
            flag2 = 1;
        }
    }
    if(!flag){
        bool vis[10005];
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        priority_queue<node> que;
        que.push((node){1,0});
        dis[1] = 0;
        while(!que.empty()){
            node t = que.top();
            que.pop();
            if(vis[t.x]){
                continue;
            }
            vis[t.x] = 1;
            for(int i=0;i<v[t.x].size();i++){
                int y = v[t.x][i].x;
                if(dis[t.x]+1<dis[y]){
                    dis[y] = dis[t.x]+1;
                    que.push((node){y,dis[y]});
                }
            }
        }
        if(dis[n]>1e9){
            cout << -1;
        }
        else{
            cout << tran(dis[n])+dis[n];
        }
        return 0;
    }
    else if(!flag2){
        bfs();
        cout << ans;
        return 0;
    }
    cout << -1;
    return 0;
}
