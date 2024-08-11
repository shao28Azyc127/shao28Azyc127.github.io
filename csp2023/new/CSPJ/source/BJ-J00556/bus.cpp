#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 10005
using namespace std;
struct Edge{
    int u,v,a,next;
}edge[maxn<<1];
int cnt,head[maxn],t[maxn];
void add(int u,int v,int a){
    cnt++;
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].a=a;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int n,m,k;
void bfs(){
    for(int i=1;i<=n;i++){
        t[i]=2147483647;
    }
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].v;
            if(t[u]<edge[i].a&&edge[i].a+1<t[v]){
                t[v]=edge[i].a+1;
                q.push(v);
            }
            else if(t[u]+1<t[v]){
                t[v]=t[u]+1;
                q.push(v);
            }
        }
        q.pop();
    }
    if(t[n]==2147483647)printf("-1");
    else printf("%d",t[n]);
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        add(u,v,a);
    }
    bfs();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
