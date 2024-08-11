#include<bits/stdc++.h>
// #pragma GCC optimize(2)
#define INF 1000000000
#define INFIN 1000000000000000000ll
#define ll long long
using namespace std;
const int N=100005;
int n;
struct Node{
    ll lim;
    ll b,c;
    ll best;
}a[N];
struct Edge{
    int v;
    int nxt;
}edge[N<<1];
int fa[N];
int head[N],tot=0;
ll lim[N];
struct Pai{
    ll lim;
    int id;
}pai[N];
bool ok[N];
int nowtot=0;
inline void add_edge(int u,int v){
    tot++;
    edge[tot]=(Edge){v,head[u]};
    head[u]=tot;
}
inline bool cmp(Pai k1,Pai k2){
    if(k1.lim==k2.lim) return k1.id<k2.id;
    return k1.lim<k2.lim;
}
void dfs(int pos,int faq){
    fa[pos]=faq;
    for(int i=head[pos];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==faq) continue;
        dfs(v,pos);
    }
}
inline ll total(int pos,int L,int R){
    if(a[pos].best<=L) return R-L+1;
    ll ans=0;
    if(a[pos].best<=R){
        ans=R-a[pos].best+1;
        R=a[pos].best-1;
    }
    ans+=a[pos].b*(ll)(R-L+1);
    ll pv=(ll)(R+L)*(ll)(R-L+1)/2ll;
    ll ex=INFIN/pv;
    if(a[pos].c>ex) return INFIN;
    ans+=a[pos].c*pv;
    return ans;
}
int get_time(int pos,int x){
    /*
    get the min time p, such that
    sum(p to x) min(b+c*i,1) >= a.
    */
    int nowl=1,nowr=x,ret=0;
    while(nowl<=nowr){
        int mid=(nowl+nowr)>>1;
        if(total(pos,mid,x)>=a[pos].lim) ret=mid,nowl=mid+1;
        else nowr=mid-1;
    }
    if(!ret) return -1;
    else return ret;
}
bool check(int x){
    for(int i=1;i<=n;i++){
        lim[i]=get_time(i,x);
        // assert(lim[i]>=1);
        if(lim[i]==-1) return false;
    }
    // if(x<=500000000){
    //     cout<<"in check "<<x<<endl;
    //     for(int i=1;i<=n;i++){
    //         cout<<lim[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        ok[i]=false;
        pai[i].id=i,pai[i].lim=lim[i];
    }
    nowtot=0;
    sort(pai+1,pai+n+1,cmp);
    for(int i=1;i<=n;i++){
        int cu=pai[i].id;
        while(cu && !ok[cu]){
            ok[cu]=true;
            nowtot++;
            cu=fa[cu];
        }
        if(nowtot>pai[i].lim){
            // if(x==500000000){
            //     cout<<"wrong at "<<pai[i].id<<" "<<pai[i].lim<<endl;
            // }
            return false;
        }
    }
    return true;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i].lim,&a[i].b,&a[i].c);
        if(a[i].c>=0) a[i].best=INF+1;
        else a[i].best=(a[i].b-1)/(-a[i].c)+1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,0);
    int L=1,R=INF,ret=0;
    while(L<=R){
        int mid=(L+R)>>1;
        if(check(mid)) ret=mid,R=mid-1;
        else L=mid+1;
    }
    cout<<ret<<endl;
    return 0;
}