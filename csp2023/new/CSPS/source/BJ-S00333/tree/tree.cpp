#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 L;
L cal(ll b,ll c,ll t){
    if(c>=0){
        L d=b+c*t;
        d=(b+c+d)*t/2;
        return d;
    }
    c=-c;
    ll tt=(b-1)/c;
    if(tt>=t){
        L d=b-c*t;
        d=(b-c+d)*t/2;
        return d;
    }
    L d=b-c*tt;
    d=(b-c+d)*tt/2+t-tt;
    return d;
}
const int MAXN=100001;
int n;
ll a[MAXN],b[MAXN],c[MAXN];
vector<int> g[MAXN];
int fa[MAXN],siz[MAXN];
void dfs(int u,int f){
    fa[u]=f;
    for(int v:g[u]){
        if(v==f)continue;
        dfs(v,u);
        siz[u]++;
    }
}
ll tim[MAXN];
int dg[MAXN];
struct node{
    int id;
    ll val;
    bool operator < (const node &_) const{
        return val<_.val;
    }
};
priority_queue<node> q;
bool check(ll t){
    for(int i=1;i<=n;i++){
        ll l=0,r=t;
        L d=cal(b[i],c[i],t);
        while(l<r){
            ll mid=l+r+1>>1;
            if(d>=a[i]+cal(b[i],c[i],mid-1))l=mid;
            else r=mid-1;
        }
        if(!l)return 0;
        tim[i]=l;
        dg[i]=siz[i];
        if(!dg[i])q.push((node){i,tim[i]});
    }
    ll now=t;
    while(!q.empty()){
        node x=q.top();
        q.pop();
        now=min(now,x.val);
        if(x.id!=1&&!--dg[fa[x.id]])q.push((node){fa[x.id],tim[fa[x.id]]});
        now--;
    }
    return now>=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    ll l=n,r=1e9;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}
