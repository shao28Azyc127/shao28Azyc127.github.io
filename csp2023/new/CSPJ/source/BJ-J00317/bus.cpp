#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,a;
};
int n,m,k;
vector<node> a[20005];
bool vis[20005][2];
queue<node> q;
int bb=0;
int tim=0;
int maxa=0;
void bfs(int t){
    q.push((node){1,t});
    vis[1][t%2]=1;
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        if(tmp.v==n&&tmp.a%k==0){
            bb=1;
            tim=tmp.a;
            return;
        }
        if(tmp.a>=maxa+n){
            bb=2;
            return;
        }
        vis[tmp.v][tmp.a%2]=0;
        for(int i=0;i<a[tmp.v].size();i++){
            if(!vis[a[tmp.v][i].v][(tmp.a+1)%2]&&(tmp.a+1>=a[tmp.v][i].a)){
                vis[a[tmp.v][i].v][(tmp.a+1)%2]=1;
                q.push((node){a[tmp.v][i].v,tmp.a+1});
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,aa;
        cin>>u>>v>>aa;
        a[u].push_back((node){v,aa});
        maxa=max(maxa,aa);
    }
    for(int i=0;i<=maxa;i+=k){
        for(int i=0;i<=n;i++){
            vis[i][0]=0;vis[i][1]=0;
        }
        tim=i;
        bfs(i);
        if(bb==1){
            break;
        }
    }
    if(bb==1){
        cout<<tim;
    }else{
        cout<<"-1";
    }
    return 0;
}
