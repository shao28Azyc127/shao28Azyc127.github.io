#include<bits/stdc++.h>
using namespace std;
struct Eg{
    int v,a,nxt;
}eg[20005];
int head[10005];
int n,m,k,eg_cnt,amin=1;
int t[10005];
void add(int u,int v,int a){
    eg[eg_cnt].v=v;
    eg[eg_cnt].a=a;
    eg[eg_cnt].nxt=head[u];
    head[u]=eg_cnt++;
}
void bfs1(){
    memset(t,-1,sizeof(t));
    queue<int> q;
    q.push(1);
    t[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int j=head[now];j;j=eg[j].nxt){
            if(t[now]>=eg[j].a){
                if(t[eg[j].v]>t[now]+1||t[eg[j].v]==-1){
                    t[eg[j].v]=t[now]+1;
                    q.push(eg[j].v);
                }
            }
        }
    }
}
void bfs2(){
    memset(t,-1,sizeof(t));
    queue<int>q;
    q.push(1);
    t[1]=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int j=head[f];j;j=eg[j].nxt){
            int vv=eg[j].v;
            if(t[vv]==-1){
                t[vv]==t[f]+1;
                q.push(vv);
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,a;
        amin=min(amin,a);
        scanf("%d %d %d",&u,&v,&a);
        add(u,v,a);
    }
    if(amin){
        bfs1();
        printf("%d",t[n]);
    }
    else{
        bfs2();
        int tt=t[n];
        cout<<(tt+k-1)/k*k;
    }
    return 0;
}
