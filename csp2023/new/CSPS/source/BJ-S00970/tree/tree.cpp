#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
using namespace std;
#define ll long long
ll read(){
    ll x=0,k=1;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
int n;
struct Q{
    ll a,b,c,lim;
    bool get_lim(__int128 ans){
        __int128 l=1,r=ans,p=0;
        if(c<0){
            if(b<=-c) p=0;
            else p=(b-1)/(-c);
            p=min(p,ans);
            if(ans-p+(p+1)*p/2*c+p*b<a) return 0;
            while(l<r){
                __int128 mid=l+r+1>>1,s=0;
                if(mid>p) s=ans-mid+1;
                else s=ans-p+(p+mid)*(p-mid+1)/2*c+(p-mid+1)*b; 
                if(s>=a) l=mid;
                else r=mid-1;
            }
            lim=l;
            return 1;
        }
        if(!c){
            b=max(b,1ll);
            if(ans*b<a) return 0;
            while(l<r){
                __int128 mid=l+r+1>>1,s=(ans-mid+1)*b;
                if(s>=a) l=mid;
                else r=mid-1;
            }
            lim=l;
            return 1;
        }
        if(b>=0) p=1; else p=(-b-1)/c+1;
        p=min(p,ans+1);
        if((p+ans)*(ans-p+1)/2*c+(ans-p+1)*b+p-1<a) return 0;
        while(l<r){
            __int128 mid=l+r+1>>1,s=0;
            if(mid>=p) s=(mid+ans)*(ans-mid+1)/2*c+(ans-mid+1)*b;
            else s=(p+ans)*(ans-p+1)/2*c+(ans-p+1)*b+(p-mid);
            if(s>=a) l=mid;
            else r=mid-1;
        }
        lim=l;
        return 1;
    }
}a[100005];
struct E{
    int u,v,nxt;
}e[200005];
int head[100005],cnt_e=0;
void add_e(int u,int v){
    e[++cnt_e]={u,v,head[u]};
    head[u]=cnt_e;
}
struct T{
    int ls,rs,rnd,siz;
    int v,lzy,mx,mn;
    void add(int x){v+=x,lzy+=x,mx+=x,mn+=x;}
}t[100005];
void push_down(int now){
    if(!t[now].lzy) return;
    if(t[now].ls) t[t[now].ls].add(t[now].lzy);
    if(t[now].rs) t[t[now].rs].add(t[now].lzy);
    t[now].lzy=0;
}
void push_up(int now){
    t[now].siz=t[t[now].ls].siz+t[t[now].rs].siz+1;
    t[now].mx=t[now].mn=t[now].v;
    if(t[now].ls) t[now].mn=min(t[now].mn,t[t[now].ls].mn);
    if(t[now].rs) t[now].mx=max(t[now].mx,t[t[now].rs].mx);
}
int merge(int x,int y){
    if(!x||!y) return x|y;
    push_down(x),push_down(y);
    int rt=0;
    if(t[x].rnd<t[y].rnd){
        rt=x;
        t[x].rs=merge(t[x].rs,y);
    }
    else{
        rt=y;
        t[y].ls=merge(x,t[y].ls);
    }
    push_up(rt);
    return rt;
}
void split_v(int rt,int &x,int &y,int v){
    if(!rt){
        x=y=0;
        return;
    }
    push_down(rt);
    if(t[rt].v<=v){
        x=rt;
        split_v(t[x].rs,t[x].rs,y,v);
    }
    else{
        y=rt;
        split_v(t[y].ls,x,t[y].ls,v);
    }
    push_up(rt);
}
void split_r(int rt,int &x,int &y,int r){
    if(!rt){
        x=y=0;
        return;
    }
    push_down(rt);
    int rnk=t[t[rt].ls].siz+1;
    if(rnk<=r){
        x=rt;
        split_r(t[x].rs,t[x].rs,y,r-rnk);
    }
    else{
        y=rt;
        split_r(t[y].ls,x,t[y].ls,r);
    }
    push_up(rt);
}
void split(int rt,int &x,int &y,int v){
    if(!rt) {
        x=y=0;
        return;
    }
    push_down(rt);
    if(t[rt].siz==v-t[rt].mn+1){
        y=rt,x=0;
        return;
    }
    if(t[rt].v==v-t[t[rt].rs].siz){
        y=rt;
        split_r(t[y].ls,x,t[y].ls,t[rt].v-1);
    }
    else{
        x=rt;
        split_r(t[x].rs,t[x].rs,y,v);
    }
    push_up(rt);
}
int get_mx(int now){
    push_down(now);
    if(t[now].rs) return get_mx(t[now].rs);
    return t[now].v;
}
ll get_mn(int now){
    push_down(now);
    if(t[now].ls) return get_mn(t[now].ls);
    return t[now].v;
}
int merge2(int u,int v){
    if(!u||!v) return u|v;
    if(t[u].siz>t[v].siz) swap(u,v);
    while(t[u].siz){
        int r1,r2,r3,r4,r5;
        split_r(u,r1,r2,t[u].siz-1);
        split_v(v,r3,r4,t[r2].v);
        if(r3&&t[r3].mx==t[r2].v){
            split(r3,r3,r5,t[r2].v);
            if(r5) t[r5].add(-1); 
            r3=merge(r3,r5);
        }
        u=r1,v=merge(merge(r3,r2),r4);
    }
    return v;
}
int cnt_t=0,rt[100005];
int newnode(int v){
    cnt_t++;
    t[cnt_t].ls=t[cnt_t].rs=t[cnt_t].lzy=0,t[cnt_t].siz=1,t[cnt_t].rnd=rand(),t[cnt_t].v=t[cnt_t].mx=t[cnt_t].mn=v;
    return cnt_t;
}
void solve(int now,int fa){
    rt[now]=0;
    for(int i=head[now];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        solve(v,now);
        rt[now]=merge2(rt[now],rt[v]);
    }
    // cout<<"NOW "<<now<<" "<<t[rt[now]].mx<<" "<<t[rt[now]].mn<<endl;
    if(rt[now]) a[now].lim=min(a[now].lim,(ll)t[rt[now]].mn-1);
    rt[now]=merge(newnode(a[now].lim),rt[now]);
    // cout<<cnt_t<<endl;
}
bool check(ll ans){
    // cout<<"MID "<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(!a[i].get_lim(ans)) return 0;
        // cout<<a[i].lim<<" ";
    }
    // puts("");
    cnt_t=0;
    solve(1,0);
    return get_mn(rt[1])>0;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i].a=read(),a[i].b=read(),a[i].c=read();
    }
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        add_e(u,v),add_e(v,u);
    }
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1; 
    }
    cout<<l;
    return 0;
}