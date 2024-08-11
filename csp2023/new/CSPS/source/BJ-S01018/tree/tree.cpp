#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define p_b push_back
#define m_p make_pair
#define p1 first
#define p2 second
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int n;
ll a[maxn],b[maxn],c[maxn];
vector<int>g[maxn];
bool vis[maxn];
ll res=1e18;
vector<int>qwq;
ll cl(ll x,ll y){
    return (x+y-1)/y;
}ll calc(ll b,ll n,ll c){
    ll x=b+(n-1)*c;
    return (b+x)*n/2;
}
ll bs(ll b,ll c,ll a){
    int ret=0,sum=0;
    if(b<1&&c<0)return a;
    ll x=1-b;
    if(c<0){
        ll g=cl(1-b,c);
        ll f=calc(b,g-1,c);
        if(f<a)return g-1+a-f;
        ll l=-1,r=g-1;
        while(l+1<r){
            ll mid=l+r>>1;
            if(calc(b,mid,c)>=a)r=mid;
            else l=mid;
        }return r;
    }ll l=-1,r=1e9;
    while(l+1<r){
        ll mid=l+r>>1;
        if(calc(b,mid,c)>=a)r=mid;
        else l=mid;
    }return r;
}
void dfs(int x,ll ans){
    if(x>n){
        res=min(res,ans);
        return;
    }map<int,int>mp;
    for(int i=0;i<qwq.size();++i){
        int y=qwq[i];
        for(int u:g[y]){
            if(mp.count(u))continue;
            if(!vis[u]){
                mp[u]=1;
                qwq.p_b(u);
                vis[u]=1;
                dfs(x+1,max(ans,x-1+bs(b[u]+c[u]*x,c[u],a[u])));
                vis[u]=0;
                qwq.pop_back();
            }
        }
    }
}void slv(){
    n=read();
    up(i,1,n)a[i]=read(),b[i]=read(),c[i]=read();
    up(i,1,n-1){
        int x=read(),y=read();
        g[x].p_b(y),g[y].p_b(x);
    }g[0].p_b(1);qwq.p_b(0);
    dfs(1,0);
    cout<<res<<'\n';
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}