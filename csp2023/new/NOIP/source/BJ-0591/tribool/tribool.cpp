#include<bits/stdc++.h>
using namespace std;
//I love my teacher CCH Cui Changhua
const int N=1e5+7;
struct nd{
int v;int s;}a[N];
struct edge{
int to,nxt,k;}E[4*N];
int head[N];
int c,t;
int ans;
int f[N],g[N];
bool vis[N],vis2[4*N];
vector<int> tpv;
void add(int x,int y,int k,int cnt){
    E[cnt].to=y;
    E[cnt].k=k;
    E[cnt].nxt=head[x];
    head[x]=cnt;
}
bool pd(int x){
    if(g[x]==-100) return 0;
    if(g[x]==-99) return 1;
    for(int x=0;x<tpv.size();++x){
        for(int j=head[x];j!=-1;j=E[j].to){
            if(!vis[j]){
                int y=x=E[j].to;
                if(g[y]*g[x]!=E[j].k){
                    return 0;
                }
            }
        }
    }

    return 1;

}
void dfs(int dd,int x){
tpv.push_back(x);
vis[x]=1;
f[x]=1;
if(a[x].s==0){
    if(a[x].v==0) g[dd]=-100;
    else g[dd]=-99;
}
for(int i=head[x];i!=0;i=E[i].nxt){

    int y=E[i].to;
    //cout<<i<<endl;
    if(vis[y]==0) {

    g[y]=g[x]*E[i].k;dfs(dd,y);
    f[x]+=f[y];vis2[i]=1;

    }
}

}
int main(){
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
cin>>c>>t;
for(int i=0;i<t;++i){
    memset(vis,0,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
    memset(a,0,sizeof(a));
    memset(head,-1,sizeof(head));
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++){
        a[j].s=1;a[j].v=j;
    }
    for(int j=0;j<m;j++){
        char tmp;
        scanf("%s",&tmp);
        if(tmp>='A' and tmp<='Z'){
            int x;
            scanf("%d",&x);
            a[x].s=0;
            if(tmp=='T') a[x].v=1;
            if(tmp=='F') a[x].v=-1;
            if(tmp=='U') a[x].v=0;
        }
        else{
            int x,y;scanf("%d%d",&x,&y);
            a[x].v=a[y].v;
            a[x].s=a[y].s;
            if(tmp=='-')a[x].s=0-a[x].s;
        }
    }
    int cnt=1;
    for(int j=1;j<=n;++j){
        if(a[j].v!=0){
            add(j,a[j].v,a[j].s,cnt);
            cnt++;
            add(a[j].v,j,a[j].s,cnt);
            cnt++;
        }
    }
    for(int j=1;j<=n;++j){
        if(vis[j]==0){
        //cout<<j<<endl;
        dfs(j,j);
        bool ifa=pd(j);
        if(!ifa) ans+=f[j];
        tpv.clear();
    }}
    cout<<ans<<endl;
    ans=0;
}

}