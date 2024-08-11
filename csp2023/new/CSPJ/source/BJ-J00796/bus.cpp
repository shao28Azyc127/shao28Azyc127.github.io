#include <bits/stdc++.h>
using namespace std;
int n,m,k,h;
int dist[10005][205];
typedef pair<int,int> PII;
int u,a,v;
vector<int>g[10005],tim[10005];
void add(int u,int v,int a){
    g[u].push_back(v);
    tim[u].push_back(a);
}
void bfs(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[1][0]=start;
    queue<PII>q;
    q.push({1,start});
    while(q.size()){
        PII t=q.front();q.pop();
        int x=t.first;
        for(int i=0;i<g[x].size();i++){
            if(dist[x][t.second%k]<tim[x][i])continue;
            if(dist[x][t.second%k]+1<dist[g[x][i]][t.second%k]){
            dist[g[x][i]][t.second%k]=dist[g[x][i]][t.second%k]+1;
            q.push({g[x][i],(t.second+1)%k});
            }
        }
    }
    //if(dist[n][0]==0x3f3f3f3f)dist[n][0]=1;
}
bool go(int y){
    if(y==n)return 1;
    for(int i=0;i<g[y].size();i++)
        if(go(g[y][i]))return 1;
    return 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&a);
    }
    if(!go(1)){
        cout<<-1;
        return 0;
    }
    memset(dist,0x3f,sizeof(dist));
    h=0;
    while(dist[n][0]!=0x3f3f3f3f){
        bfs(h);
        h+=k;
    }
    printf("%d",dist[n][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}