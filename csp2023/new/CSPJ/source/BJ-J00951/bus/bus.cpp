#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=20005;
struct node{
    int u,dis;
};
struct edge{
    int v,w;
    int nxt;
}edge[M];
int head[N],cnt;
int n,m,k,d;
int dis[N];
queue<node> q;
void addedge(int u,int v,int w){
    edge[++cnt].v=v,edge[cnt].w=w,edge[cnt].nxt=head[u],head[u]=cnt;
}
int check(int x){
    for(int i=1;i<=n;i++) dis[i]=0;
    q.push((node){1,0});
    while(!q.empty()){
        int u=q.front().u,dis=q.front().dis;
        q.pop();
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].v,w=edge[i].w;
            if(x+dis<w) continue;
            if((dis+1)%k==0&&v==n){
                d=dis+1;
                return 1;
            }
            q.push((node){v,dis+1});
        }
    }
    return 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    int l=0,r=1000000,ans1=-1,ans2=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans1=mid,ans2=d,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",((ans1-1)/k+1)*k+ans2);
    return 0;
}
