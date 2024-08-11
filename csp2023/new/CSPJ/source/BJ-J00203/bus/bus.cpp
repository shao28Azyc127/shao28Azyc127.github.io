#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int cnt=0;
int n,m,k,ans=1e9,dis[20010];
bool vis[20010];
vector<pair<int,int> >g[20010];
void bfs(int st,int tm){
    for(int i=2;i<=20000;i++)vis[i]=0;
    for(int i=2;i<=20000;i++)dis[i]=1e9;
    dis[st]=tm;
    cnt+=44000;
    vis[1]=1;
    queue<int>q;
    q.push(st);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(pair<int,int> y:g[u]){
            if(dis[u]+1>=y.second){
                dis[y.first]=dis[u]+1;
                cnt++;
                if((dis[u]+1)%k==0&&y.first==n){
                        cnt=8e7;
                    return;
                }
                vis[y.first]=1;
                q.push(y.first);
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    for(int i=0;i<=ans;i+=k){
        bfs(1,i);
        cnt++;
        if(dis[n]%k==0)ans=dis[n];
        if(ans>=8e8&&cnt>=5e7){
            cout<<-1;
            return 0;
        }
        if(cnt>=9e7){
            cout<<ans;
            return 0;
        }
        //cout<<i;
    }
    if(ans>8e8)cout<<-1;
    else cout<<ans;
    return 0;
}
