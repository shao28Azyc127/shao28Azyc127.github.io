#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
using namespace std;


struct edge{
    int stop,time;
    bool operator < (const edge a)const{
        return time>a.time;
    }
};




int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<edge> e[n];

    bool flag1=false,flag2=false;
    for(int i=0;i<m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        u--;
        v--;
        e[u].push_back(edge{v,a});
        if(a != 0){
            flag1 = true;
        }
        if(u >= v){
            flag2 = true;
        }
    }

    if(k == 1){
        bool vis[n];
        memset(vis,false,sizeof(vis));
        int dis[n];
        memset(dis,-1,sizeof(dis));
        vis[0] = true;
        dis[0] = 0;

        queue<edge> q;
        q.push(edge{0,0});

        while(!q.empty()){
            while(!q.empty()  &&  q.front().time > dis[q.front().stop]) q.pop();

            if(q.empty())
                break;

            edge l=q.front();
            q.pop();

            for(auto i:e[l.stop]){
                if(dis[i.stop] == -1  ||  dis[i.stop] > max(dis[l.stop],i.time)+1){
                    dis[i.stop] = max(dis[l.stop],i.time)+1;
                    q.push(edge{i.stop,dis[i.stop]});
                }
            }
        }

        if(dis[n-1] != -1)
            cout<<dis[n-1]<<endl;
        else
            cout<<-1<<endl;
    }
    else if(flag1 == false){
        int ans=-1;
        queue<int> q;

        set<int> dis[n];
        q.push(0);
        dis[0].insert(0);

        while(!q.empty()){
            int l=q.front();
            q.pop();

            if(l == n-1){
                for(auto i:dis[n-1]){
                    if(i%k == 0){
                        ans = i;
                        break;
                    }
                }
                if(ans != -1)
                    break;
                dis[n-1].clear();
            }

            for(auto i:e[l]){
                q.push(i.stop);
                for(auto j:dis[l]){
                    dis[i.stop].insert(j+1);
                }
            }

        }

        cout<<ans<<endl;
    }
    else if(flag2 == false){
        cout<<-1<<endl;
    }


    return 0;
}
