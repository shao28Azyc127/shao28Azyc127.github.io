#include<iostream>
#include<climits>
using namespace std;
struct edge{
    int u,v,t,n;
}e[400004];
int n,m,k,u,v,w,h[400004],c,t[400004],ans;
bool vs[400004],f;
void add(int u,int v,int t){
    e[++c].u=u;
    e[c].v=v;
    e[c].t=t;
    e[c].n=h[u];
    h[u]=c;
}
void dfs(int u,int d){
    if(t[u]<=d&&!vs[u])return;
    t[u]=d;
    cout<<t[u]<<endl;
    if(u==n){
        ans=min(ans,d);
        f=true;
    }
    for(int i = h[u];i;i=e[i].n){
        int v2=e[i].v;
        if(vs[v2])continue;
        vs[v2]=true;
        dfs(v2,max(d,e[i].t)+1);
        vs[v2]=false;
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    vs[1]=true;
    ans=INT_MAX;
    dfs(1,k);
    if(!f)cout<<-1<<endl;
    else {
        ans+=k-1;
        ans/=k;
        ans*=k;
        //cout<<(ans==1000782?"AC":"WA")<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
