#include<bits/stdc++.h>
#define mid (l+r>>1)
#define rs (k<<1|1)
#define ls (k<<1)
using namespace std;
typedef long long ll;
const int N=1e5+5;
int c,T;
int n,m,k;
struct node{
    int x,y;
    ll v;
}a[N];
bool cmp(node x,node y){
    return x.x<y.x;
}
vector<int> zy;
ll t[N<<2],lz[N<<2];
ll f[N],d;
int getid(int x){
    return upper_bound(zy.begin(),zy.end(),x)-zy.begin();
}
void pushup(int k){
    t[k]=max(t[ls],t[rs]);
}
void pushdown(int k){
    t[ls]+=lz[k];
    t[rs]+=lz[k];
    lz[ls]+=lz[k];
    lz[rs]+=lz[k];
    lz[k]=0;
}
void update(int l,int r,int k,int x,int y,ll d){
    if(x>y)return;
    if(x<=l&&r<=y){
        t[k]+=d;
        lz[k]+=d;
        return;
    }
    pushdown(k);
    if(x<=mid)update(l,mid,ls,x,y,d);
    if(y>mid)update(mid+1,r,rs,x,y,d);
    pushup(k);
}
ll query(int l,int r,int k,int x,int y){
    if(x>y)return -5e18;
    if(x<=l&&r<=y)return t[k];
    pushdown(k);
    if(y<=mid)return query(l,mid,ls,x,y);
    if(x>mid)return query(mid+1,r,rs,x,y);
    return max(query(l,mid,ls,x,y),query(mid+1,r,rs,x,y));
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        zy.clear();
        memset(t,0,sizeof(t));
        memset(lz,0,sizeof(lz));
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;++i){
            cin>>a[i].x>>a[i].y>>a[i].v;
            if(a[i].x-a[i].y+1<1){
                --m;--i;
            }
            else if(a[i].y>k){
                --m;--i;
            }
            else{
                zy.push_back(a[i].x-a[i].y+1);
            }
        }
        sort(zy.begin(),zy.end());
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;++i){
            update(1,m,1,i,i,(zy[i-1]-1)*d);
        }
        for(int i=1;i<=m;++i){
            f[i]=f[i-1];
            update(1,m,1,1,getid(a[i].x-a[i].y+1),a[i].v);
            update(1,m,1,1,m,-d*(a[i].x-a[i-1].x));
            f[i]=max(f[i],query(1,m,1,getid(a[i].x-k)+1,getid(a[i].x)));
            update(1,m,1,getid(a[i].x+1)+1,getid(a[i+1].x+1),f[i]);
        }
        cout<<f[m]<<'\n';
    }
    return 0;
}
