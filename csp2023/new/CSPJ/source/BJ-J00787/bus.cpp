#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,nxt,v;
}e[20010];
struct sc{
    int tm,id;
};
int head[10010],cnt=0,vis[10010];
void add(int u,int v,int w){
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].v=w;
    head[u]=cnt;
}
queue<sc> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(vis,0x3f,sizeof(vis));
    memset(head,0,sizeof(head));
    memset(e,0,sizeof(e));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    vis[1]=k;
    q.push(sc{k,1});
    while(!q.empty()){
        sc t=q.front();
        q.pop();
        for(int i=head[t.id];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].v;
            if(t.tm>=w){
                t.tm++;
                //if(vis[v]>t.tm){
                    //vis[v]=t.tm;
                    if(v==n&&t.tm%k==0){
                        cout<<t.tm;
                        return 0;
                    }
                    q.push(sc{t.tm,v});
                //}
                /*else if(v==n&&t.tm%k==0){
                    cout<<t.tm;
                    return 0;
                }*/
            }
        }
    }
    cout<<-1;
}