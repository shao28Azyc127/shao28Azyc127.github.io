#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n,m,k;
int u[20005],v[20005],a[20005];
struct p{
        int point;
        int dis;
    bool operator< (p o) const{
        return this->dis>o.dis;
    }
};
int dis[20005];
bool vis[20005];
priority_queue<p> dmq;
vector<int> path[20005];
int pathl[20005];
int main() {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for (int iii=1;iii<=m;iii++) {
        cin>>u[iii]>>v[iii]>>a[iii];
        path[u[iii]].push_back(v[iii]);
        pathl[u[iii]]++;
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    dmq.push((p){1,0});
    while (!dmq.empty()) {
        p nown=dmq.top();
        vis[nown.point]=true;
        for (int i=0;i<pathl[nown.point];i++) {
            if ((!vis[nown.point])&&dis[path[nown.point][i]]>dis[nown.point]+1) {
                dis[path[nown.point][i]]=dis[nown.point]+1;
                dmq.push((p){path[nown.point][i],dis[path[nown.point][i]]});
            }
        }
    }
    if (dis[n]>0x3f3f3f00) cout<<-1;
    else cout<<(dis[n]+k-1)/k*k;
    return 0;
}
