#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;
typedef pair<int,int> PII;

int n,m,k;
int dist[N][200];
vector<int> g[N],tim[N];

void add(int a,int b,int c){
    g[a].push_back(b);
    tim[a].push_back(c);
}

void bfs(int start){
    memset(dist,0x3f,sizeof(dist));
    dist[1][start%k]=start;
    queue<PII> q;
    q.push({1,start%k});
    while(q.size()){
        //if(dist[n][0]<0x3f3f3f3f) break;
        PII t=q.front();q.pop();
        int x=t.first;
        for(int i=0;i<g[x].size();++i){
            if(dist[x][t.second]<tim[x][i]) continue;
            if(dist[x][t.second]+1<dist[g[x][i]][(t.second+1)%k]){
                dist[g[x][i]][(t.second+1)%k]=dist[x][t.second]+1;
                q.push({g[x][i],(t.second+1)%k});
            }
        }
    }
    //if(dist[n][0]==0x3f3f3f3f) dist[n][0]=-1;
}

bool go(int u){
    if(u==n) return 1;
    for(int i=0;i<g[u].size();++i){
        if(go(g[u][i])) return 1;
    }
    return 0;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    if(!go(1)){
        printf("-1");
        return 0;
    }
    int h=0;
    memset(dist,0x3f,sizeof(dist));
    while(dist[n][0]==0x3f3f3f3f){
        bfs(h);
        h+=k;
    }
    printf("%d",dist[n][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}