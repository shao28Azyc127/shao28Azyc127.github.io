#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100010;
int n,m,k,d;
struct node{
    int l,r,v;
}a[MAXN];
bool cmp(node i,node j){
    return i.r<j.r;
}
int b[MAXN*2],h;
ll f[MAXN*2];
ll mx[MAXN*8],tg[MAXN*8];
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
void pushdown(int p){
    mx[ls]+=tg[p],tg[ls]+=tg[p];
    mx[rs]+=tg[p],tg[rs]+=tg[p];
    tg[p]=0;
}
void change(int p,int l,int r,int x){
    if(l==r){
        mx[p]=f[x]+1ll*b[x]*d;
        return;
    }
    pushdown(p);
    if(x<=mid)change(ls,l,mid,x);
    else change(rs,mid+1,r,x);
    mx[p]=max(mx[ls],mx[rs]);
}
void modify(int p,int l,int r,int x,int y,int v){
    if(x<=l&&r<=y){
        mx[p]+=v,tg[p]+=v;
        return;
    }
    pushdown(p);
    if(x<=mid)modify(ls,l,mid,x,y,v);
    if(mid<y)modify(rs,mid+1,r,x,y,v);
    mx[p]=max(mx[ls],mx[rs]);
}
ll query(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)return mx[p];
    pushdown(p);
    ll v=-1e18;
    if(x<=mid)v=max(v,query(ls,l,mid,x,y));
    if(mid<y)v=max(v,query(rs,mid+1,r,x,y));
    return v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        b[h=0]=0;
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y>>a[i].v;
            a[i].l=x-y+1;
            a[i].r=x;
            b[++h]=a[i].l-1;
            b[++h]=a[i].r+1;
        }
        sort(a+1,a+m+1,cmp);
        sort(b,b+h+1);
        h=unique(b,b+h+1)-b-1;
        change(1,0,h,0);
        for(int i=1,j=1;i<=h;i++){
            while(j<=m&&a[j].r<b[i]){
                int p=lower_bound(b,b+h+1,a[j].l-1)-b;
                modify(1,0,h,0,p,a[j].v);
                j++;
            }
            int p=lower_bound(b,b+h+1,b[i]-k-1)-b;
            f[i]=max(f[i-1],query(1,0,h,p,i-1)-1ll*(b[i]-1)*d);
            change(1,0,h,i);
        }
        cout<<f[h]<<'\n';
    }
    return 0;
}
