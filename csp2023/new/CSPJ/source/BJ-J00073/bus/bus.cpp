#include <iostream>
using namespace std;
int n, m, k, head[10005], cnt=0, minn=0x3f3f3f3f, arrive=0, book[10005];
struct{
    int to, a, next;
}edge[20005];
void add(int u,int v,int a){
    edge[++cnt].to=v, edge[cnt].a=a, edge[cnt].next=head[u], head[u]=cnt;
}
void dfs(int p,int time){
    if(p==n){
        if(time%k==0) minn=min(minn,time), arrive=1;
        return;
    }
    if(time>=minn) return;
    for(int i=head[p];i!=0;i=edge[i].next){
        if(book[i]==1) continue;
        book[i]=1;
        int x=0;
        while(time+x<edge[i].a) x+=k;
        dfs(edge[i].to,time+x+1);
        book[i]=0;
    }
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
    book[1]=1;
    dfs(1,0);
    if(arrive==0) puts("-1");
    else printf("%d",minn);
    return 0;
}
