#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100005;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int T,n,m,k,d,lu[maxn],kt;
long long dp[maxn];
pair<pair<int,int>,int> p[maxn];
struct node{
    int l,r;
    long long lazy,data;
};
struct xds{
    node pool[maxn<<2];
    void pushdown(int id){
        pool[id].data+=pool[id].lazy;
        if(pool[id].l<pool[id].r){
            pool[id<<1].lazy+=pool[id].lazy;
            pool[id<<1|1].lazy+=pool[id].lazy;
        }
        pool[id].lazy=0;
    }
    void pushup(int id){
        pushdown(id<<1);
        pushdown(id<<1|1);
        pool[id].data=max(pool[id<<1].data,pool[id<<1|1].data);
    }
    void build(int id,int l,int r){
        pool[id].l=l;pool[id].r=r;
        pool[id].data=-inf;pool[id].lazy=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
    }
    void change(int id,int l,int r,int x){
        if(pool[id].l==l&&pool[id].r==r){
            pool[id].lazy+=(long long)x;
            return;
        }
        int mid=pool[id].l+pool[id].r>>1;
        if(r<=mid)change(id<<1,l,r,x);
        else if(l>mid)change(id<<1|1,l,r,x);
        else change(id<<1,l,mid,x),change(id<<1|1,mid+1,r,x);
        pushup(id);
    }
    void ins(int id,int x,long long y){
        pushdown(id);
        if(pool[id].l==pool[id].r){
            pool[id].data=max(pool[id].data,y);
            return;
        }
        int mid=pool[id].l+pool[id].r>>1;
        if(x<=mid)ins(id<<1,x,y);
        else ins(id<<1|1,x,y);
        pushup(id);
    }
    long long ask(int id,int l,int r){
        pushdown(id);
        if(pool[id].l==l&&pool[id].r==r)return pool[id].data;
        int mid=pool[id].l+pool[id].r>>1;
        if(r<=mid)return ask(id<<1,l,r);
        else if(l>mid)return ask(id<<1|1,l,r);
        else return max(ask(id<<1,l,mid),ask(id<<1|1,mid+1,r));
    }
}t1;
int lowbit(int x){return x&-x;}
struct tl_s{
    long long data[maxn];
    void insert(int x,int y){
        for(;x<=kt;x+=lowbit(x))data[x]+=(long long)y;
    }
    long long ask(int x){
        long long res=0;
        for(;x;x-=lowbit(x))res+=data[x];
        return res;
    }
}t2;
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;cin>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        kt=0;
        for(int i=1;i<=m;++i){
            cin>>p[i].first.first>>p[i].first.second>>p[i].second;
            p[i].first.second=p[i].first.first-p[i].first.second+1;
            lu[++kt]=p[i].first.second;
        }
        sort(lu+1,lu+kt+1);
        kt=unique(lu+1,lu+kt+1)-lu-1;
        for(int i=1;i<=m;++i)p[i].first.second=lower_bound(lu+1,lu+kt+1,p[i].first.second)-lu;
        t1.build(1,1,kt);
        for(int i=1;i<=kt;++i)t2.data[i]=0;
        sort(p+1,p+m+1);
        long long now=0;
        for(int i=1;i<=m;++i){
            dp[i]=dp[i-1];
            int L=p[i].first.second,R=p[i].first.first;
            if(R-lu[L]+1>k)continue;
            now+=(long long)p[i].second;
            int prev=lower_bound(p+1,p+m+1,make_pair(make_pair(lu[L]-1,0),0))-p-1;
            t1.ins(1,L,dp[prev]+(long long)lu[L]*d-d-t2.ask(L-1));
            t2.insert(L,p[i].second);
            if(L<kt)t1.change(1,L+1,kt,-p[i].second);
            dp[i]=max(dp[i],t1.ask(1,lower_bound(lu+1,lu+kt+1,R-k+1)-lu,kt)-(long long)R*d+now);
        }
        cout<<dp[m]<<'\n';
    }
    return 0;
}
//AK 了，于是来整点小活
//我永远爱御坂美琴！