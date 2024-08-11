#include <bits/stdc++.h>
using namespace std;
#define int ll
#define MP make_pair
typedef long long ll;
const int N = 1e5+5;
const int M = N<<2;
const ll inf=0x3f3f3f3f3f3f3f3f;
int C,T,n,m,lim;
ll d,f[N];
vector<pair<int,int>>vec[N];
struct SegTree {
    ll mx[N],add[N];
    inline int ls(int p){return p<<1;}
    inline int rs(int p){return p<<1|1;}
    inline void push_up(int p){mx[p]=max(mx[ls(p)], mx[rs(p)]);}
    inline void push_down(int p){
        if(add[p]){
            add[ls(p)] += add[p], add[rs(p)] += add[p];
            mx[ls(p)] += add[p], mx[rs(p)] += add[p];
            add[p]=0;
        }
    }
    inline void update(int p,int l,int r,int dl,int dr,int k){
        if(dl<=l&&r<=dr){
            add[p]+=k,mx[p]+=k;
            return;
        }
        push_down(p);
        int mid=l+r>>1;
        if(dl<=mid)
            update(ls(p),l,mid,dl,dr,k);
        if(mid<dr)
            update(rs(p),mid+1,r,dl,dr,k);
        push_up(p);
    }
    inline void cover(int p,int l,int r,int x,ll k){
        if(l==r){
            mx[p]=k,add[p]=0;
            return;
        }
        push_down(p);
        int mid=l+r>>1;
        if(x<=mid)
            cover(ls(p),l,mid,x,k);
        else
            cover(rs(p),mid+1,r,x,k);
        push_up(p);
    }
    inline ll query(int p,int l,int r,int qx,int qy){
        if(qx<=l&&r<=qy)
            return mx[p];
        push_down(p);
        int mid=l+r>>1;
        ll res=0;
        if(qx<=mid)
            res=max(res, query(ls(p),l,mid,qx,qy));
        if(mid<qy)
            res=max(res, query(rs(p),mid+1,r,qx,qy));
        return res;
    }
}seg;
inline void solve2(){
    while(T--){
        cin>>n>>m>>lim>>d;
        ll ans=0;
        for(int i=1,l,r,k;i<=m;i++){
            cin>>r>>l>>k;
            if(l<=lim && l*d<k)
                ans+=k-l*d;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    freopen("run.in","r", stdin);
    freopen("run.out","w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>C>>T;
    if(C>=15){
        solve2();
        return 0;
    }
    while(T--){
        memset(seg.mx,-0x3f,sizeof(seg.mx));
        memset(seg.add,0,sizeof(seg.add));
        cin>>n>>m>>lim>>d;
        for(int i=1;i<=n;i++)
            vec[i].clear();
        for(int i=1,l,r,k;i<=m;i++)
            cin>>r>>l>>k,vec[r].push_back(MP(r-l+1,k));
        seg.cover(1,0,n,0,0);
        for(int i=1;i<=n+1;i++){
            for(auto x:vec[i-1])
                seg.update(1,0,n,0,x.first-1,x.second);
            f[i] = seg.query(1,0,n,max(0ll,i-lim-1),i-1)-(i-1)*d;
            if(i<=n)
                seg.cover(1,0,n,i,f[i]+i*d);
        }
        cout<<f[n+1]<<'\n';
    }
    return 0;
}
