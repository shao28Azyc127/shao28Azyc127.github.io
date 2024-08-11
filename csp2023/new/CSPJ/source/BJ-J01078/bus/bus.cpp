#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> dis[N][105];
int vis[N][105];
int n,m,k;
int u,v,we;
vector<int> t[N],w[N];
void bfs(int x){
    //cout<<x<<endl;
    for(int i=0;i<t[x].size();++i){
        for(int j=0;j<k;++j){
            if(vis[x][j]==INT_MAX) continue;
            for(int l=0;l<dis[x][j].size();++l){
                if(dis[x][j][l]>=w[x][i]){
                    vis[t[x][i]][(j+1)%k]=min(vis[t[x][i]][(j+1)%k],dis[x][j][l]+1);
                    if(dis[t[x][i]][(j+1)%k].size()<=100){
                        dis[t[x][i]][(j+1)%k].push_back(dis[x][j][l]+1);
                        bfs(t[x][i]);
                    }
                }
            }


        }

    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&we);
        t[u].push_back(v);
        w[u].push_back(we);
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            vis[i][j]=1e9;
        }
    }
    vis[1][0]=0;
    dis[1][0].push_back(0);
    for(int i=1;i<=100;++i){
        dis[1][0].push_back(i*k);
    }

    bfs(1);
    //cout<<dis[2][1].size()<<endl;
    if(vis[n][0]==1e9){
        cout<<-1;
    }else{
        cout<<vis[n][0];
    }
    return 0;
}
