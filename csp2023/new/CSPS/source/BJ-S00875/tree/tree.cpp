#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int N=2e6+5;
const int M=1e6+5;
const int INF=2e9+5;
template<typename T>
inline void read(T &x) {
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
template<typename T>
void write(T x) {
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
int n,b[N],c[N],xx[N],edgecnt,head[N];
ll a[N],p[N],ans;
struct EDGE {
    int v,next;
}edge[M];
void add_edge(int x,int y) {
    edge[++edgecnt]=(EDGE){y,head[x]};
    head[x]=edgecnt;
}
ll suan(int x,int day,int up) {
    if(c[x]>=0) {
        return 1ll*(b[x]+day*c[x]+b[x]+up*c[x])*(up-day+1)/2;
    }
    else {
        if(day>xx[x])return up-day+1;
        else if(up<=xx[x])return 1ll*(b[x]+day*c[x]+b[x]+up*c[x])*(up-day+1)/2;
        else return 1ll*(b[x]+day*c[x]+b[x]+xx[x]*c[x])*(xx[x]-day+1)/2+up-xx[x]+1;
    }
}
int binar(int x,int mi) {
    int l=1,r=mi,res=-1;
    while(l<=r) {
        int mid=l+r>>1;
        if(suan(x,mid,mi)<a[x])r=mid-1;
        else l=mid+1,res=mid;
    }
    return res;
}
ll imp[N],deep[N],lz[N];
void dfs(int x,int fa,int dep) {
    p[x]-=dep;p[x]++;deep[x]=dep+1;
    imp[x]=p[x];
    for(int i=head[x];~i;i=edge[i].next) {
        int v=edge[i].v;
        if(v==fa)continue;
        dfs(v,x,dep+1);
        if(imp[v]==imp[x])imp[x]--;
        imp[x]=min(imp[x],imp[v]);
        //if(p[v]==imp[x])lz[x]++;
        //if(p[v]<imp[x]) {
        //    imp[x]=p[v];
        //}
    }
}

priority_queue<pair<ll,int> >q;
bool vis[N];
bool check(int mi) {
  //  printf("%d\n",mi);
    for(int i=1;i<=n;i++) {
        p[i]=binar(i,mi);
     //   printf("%lld ",p[i]);
        if(p[i]==-1)return 0;
    }
//   puts("");
    dfs(1,0,0);
 //   for(int i=1;i<=n;i++)printf("%lld ",imp[i]);
   // printf("\n");
    for(int i=1;i<=n;i++) {
        //imp[i]-=lz[i];
        if(imp[i]<deep[i])return 0;
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    while(!q.empty())q.pop();
    for(int i=head[1];~i;i=edge[i].next) {
        int v=edge[i].v;
        q.push(mkp(-imp[v],v));
    }
    int step=0;
    while(!q.empty()) {
        int u=q.top().second;q.pop();vis[u]=1;
        step++;
        if(step>p[u])return 0;
        for(int i=head[u];~i;i=edge[i].next) {
            int v=edge[i].v;
            if(vis[v])continue;
            q.push(mkp(-imp[v],v));
        }
    }
    return 1;
}
bool flaga=1,flagb=1,flagc=1,flagd=1;
void solveb() {
    for(int i=1;i<=n;i++) {
        int l=i,r=1e9+10;
        while(l<=r) {
            int mid=l+r>>1;
            if(suan(i,i,mid)>a[i])r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,l);
    }
    printf("%lld\n",ans);
    exit(0);
}
signed main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        if(c[i]<0)xx[i]=b[i]/(-c[i]);
    }
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%lld%lld",&u,&v);
        if(u!=i||v!=i+1)flagb=0;
        add_edge(u,v);
        add_edge(v,u);
    }
    if(flagb) {
        solveb();
    }
    int l=1,r=1e10+10;
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid))r=mid-1;
        else l=mid+1,ans=l;
    }
    printf("%lld",ans);
    return 0;
}
/*  if(c[x]>=0) {
        int l=day,r=up;
        while(l<=r) {
            int mid=l+r>>1;
            if((b[x]+day*c[x]+b[x]+mid*c[x])*(mid-day+1)>a[x])r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    else {
        if(b[x]+day*c[x]<=1)return day+a[x];
        ll sx=b[x]+day*c[x],xs=(b[x]+day*c[x])/(-c[x]),mx=sx+c[x]*(xs-1);
        if((sx+mx)*xs/2>=a[x]) {
            int l=day,r=up;
            while(l<=r) {
                int mid=l+r>>1;
                ll xss=(b[x]+mid*c[x])/(-c[x]),mxx=sx+c[x]*(xs-1);
                if((sx+mxx)*xss/2>a[x])r=mid-1;
                else l=mid+1;
            }
            return l;
        }
        else {
            return (a[x]-(sx+mx)*xs/2);
        }
    }*/
