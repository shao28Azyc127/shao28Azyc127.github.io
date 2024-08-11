#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=2e4+4;

struct edge{
    int u,v,t,nxt;
}e[N],g[N];
int head[N],ecnt,u,v,t,gcnt;
void add(int u,int v,int t){
    e[++ecnt].v=v;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
    e[ecnt].t=t;
}
bool cmp(edge a,edge b){
    return a.t<b.t;
}

int dis[N];
struct node{
    int u,dis;
    friend bool operator<(node a,node b){
        return a.dis>b.dis;
    }
};
int vis[N];
void dij(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    priority_queue<node> q;
    q.push({1,0});
    while(!q.empty()){
        node now=q.top();
        q.pop();
        int u=now.u;
        cout<<u<<endl;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({v,dis[v]});
            }
        }
    }
}
int ans=1e9;
void dfs(int u,int dis,int st){
    if(u==n){
        int sum=dis+st;
        if(sum%k==0)
        ans=min(ans,sum);
        return ;
    }
    if(dis+st>=ans) return ;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        int sum=dis+st+1;
        if(sum<e[i].t){
            int x=e[i].t-sum;
            if(x%k==0) x/=k;
            else x=x/k+1;
            dfs(v,dis+1,st+k*x);
        }
        else dfs(v,dis+1,st);
    }

}
int f[N][105];
struct NODE{
    int u,k;
};
int check(int mid){
    memset(f,-1,sizeof(f));
    f[1][0]=0;
    queue<NODE> q;
    q.push({1,0});
    while(!q.empty()){
        NODE now=q.front();
        q.pop();
        int u=now.u,d=now.k;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(e[i].t>mid+f[u][d]) continue;
            int nxt=(d+1)%k;
            if(f[v][nxt]==-1){
                f[v][nxt]=f[u][d]+1;
                q.push({v,nxt});
            } 
        }
    }
    return f[n][0]+mid;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    bool flag=true;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>t;
        add(u,v,t);
        if(t!=0) flag=false;
        g[++gcnt]=edge{u,v,t,0};
    }
    
    if(n<=10){
        dfs(1,0,0);
        if(ans!=(int)1e9) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    else if(flag==true&&k==1){
        dij();
        cout<<dis[u]<<endl;
    }
    else{
        int l=0,r=1e9,mid,ans;
        int sum;
        while(l<=r){
            mid=l+r>>1;
            sum=check(mid);
            cout<<sum<<' ';
            if(sum!=mid-1) r=mid-1,ans=sum;
            else l=mid+1;
        }
        cout<<ans;
    }
}