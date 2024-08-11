#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int INF=1e9+9;
struct Node{
    int v,nxt;
}e[N<<1];
int h[N],tot;
int a[N],b[N],c[N];
void add(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int dep[N],siz[N];
int dfn[N],idx[N];
int dfn_cnt=0;
bool vis[N];
int fa[N][25];
int _log[N],pp[N];
void dfs(int start,int father){
    fa[start][0]=father;
    dep[start]=dep[father]+1;
    siz[start]=1;
    dfn[start]=++dfn_cnt;
    idx[dfn_cnt]=start;
    for(int i=1;i<=_log[dep[start]];i++){
        fa[start][i]=fa[fa[start][i-1]][i-1];
    }
    for(int i=h[start];i;i=e[i].nxt){
        if(e[i].v==father)continue;
        dfs(e[i].v,start);
        siz[start]+=siz[e[i].v];
    }
}
int n;
int limit[N];
struct Seg{
    int left,right;
    int lazy,min_n,min_id;
}t[N<<1];
void update(int id){
    if(t[id<<1].min_n<t[id<<1|1].min_n){
        t[id].min_id=t[id<<1].min_id;
        t[id].min_n=t[id<<1].min_n;
    }
    else{
        t[id].min_id=t[id<<1|1].min_id;
        t[id].min_n=t[id<<1|1].min_n;
    }
}
void pushdown(int id){
    if(t[id].lazy){
        t[id<<1].lazy+=t[id].lazy;
        t[id<<1].min_n+=t[id].lazy;
        t[id<<1|1].lazy+=t[id].lazy;
        t[id<<1|1].min_n+=t[id].lazy;
        t[id].lazy=0;
        return;
    }
}
void build(int id,int l,int r){
    t[id].left=l;
    t[id].right=r;
    t[id].lazy=0;
    if(l==r){
        t[id].min_n=limit[l]-dep[l];
        t[id].min_id=l;
        return;
    }
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    update(id);
}
void change(int id,int l,int r,int c){
    if(t[id].left==l&&t[id].right==r){
        t[id].min_n+=c;
        t[id].lazy+=c;
        return;
    }
    pushdown(id);
    if(t[id<<1].right>=r)change(id<<1,l,r,c);
    else if(t[id<<1|1].left<=l)change(id<<1|1,l,r,c);
    else{
        change(id<<1,l,t[id<<1].right,c);
        change(id<<1|1,t[id<<1|1].left,r,c);
    }
    update(id);
}
pair<int,int> query(){
    return make_pair(t[1].min_n,t[1].min_id);
}
int up(int k){
    int limm=_log[dep[k]];
    for(int i=limm;i>=0;i--){
        if(vis[fa[k][i]])continue;
        k=fa[k][i];
    }
    return k;
}
bool check(int endtim){
    vis[0]=1;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        if(c[i]<0&&b[i]+endtim*c[i]<=0){
            int divv=floor((double)-b[i]*1.0/(double)c[i]);
            if(endtim-(divv+1)+1>=a[i])limit[i]=endtim-a[i]+1;
            else{
                double aa=c[i],bb=-(c[i]+2*endtim*c[i]+2*b[i]),cc=2*(a[i]-(endtim-divv));
                double delt=bb*bb-4*aa*cc;
                if(delt<0)return 0;
                int lenn;
                if(c[i]>0)lenn=ceil((-bb-sqrt(delt))/2.0/aa);
                if(c[i]<0)lenn=ceil((-bb+sqrt(delt))/2.0/aa);
                if(c[i]==0)lenn=ceil((double)a[i]*1.0/(double)b[i]);
                limit[i]=endtim-lenn+1;
            }
        }
        else{
            double aa=c[i],bb=-(c[i]+2*endtim*c[i]+2*b[i]),cc=2*a[i];
            double delt=bb*bb-4*aa*cc;
            if(delt<0)return 0;
            int lenn;
            if(c[i]>0)lenn=ceil((-bb-sqrt(delt))/2.0/aa);
            if(c[i]<0)lenn=ceil((-bb+sqrt(delt))/2.0/aa);
            if(c[i]==0)lenn=ceil((double)a[i]*1.0/(double)b[i]);
            limit[i]=endtim-lenn+1;
        }
    }
    //<=limitit
    build(1,1,n);
    for(int i=1;i<=n;i++){
        pair<int,int>pa1=query();
        if(pa1.first<0)return 0;
        int id=idx[pa1.second];
        int tt=up(id);
        vis[tt]=1;
        //change(1,dfn[tt],dfn[tt]+siz[tt]-1,1);
        change(1,dfn[tt],dfn[tt],INF);
    }
    return 1;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    pp[0]=1;
    for(int i=1;i<=20;i++)pp[i]=pp[i-1]<<1;
    _log[1]=0;
    for(int i=1;i<=n;i++){
        if(i==pp[_log[i-1]+1])_log[i]=_log[i-1]+1;
        else _log[i]=_log[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    //cout<<"?\n";
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v);
        add(v,u);
    }
    //cout<<"?\n";
    dfs(1,0);
    //for(int i=1;i<=n;i++)cout<<idx[i]<<"\n";
    int l=n,r=1e9,ans=1e9;
    while(l<=r){
        //cout<<l<<" "<<r<<"\n";
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}