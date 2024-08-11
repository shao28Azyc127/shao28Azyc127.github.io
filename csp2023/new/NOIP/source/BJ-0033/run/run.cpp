#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c>'9'||c<'0');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*k;
}
int n,m,k,d;
const long long inf=4e18;
struct T{
    int ls,rs;
    long long mx,lzy;
    void init_v(long long tl,long long tr){
        ls=rs=0;
        lzy=0,mx=tr*d;
    }
    void add(long long x){
        mx+=x,lzy+=x;
    }
}t[40000005];
int cnt_t=0;
void push_up(int now,long long mid,long long tr){
    t[now].mx=t[now].lzy;
    if(t[now].ls) t[now].mx=max(t[now].mx,t[t[now].ls].mx+t[now].lzy);
    else t[now].mx=max(t[now].mx,t[now].lzy+mid*d);
    if(t[now].rs) t[now].mx=max(t[now].mx,t[t[now].rs].mx+t[now].lzy);
    else t[now].mx=max(t[now].mx,t[now].lzy+tr*d);
}
void add(int now,int lst,int tl,int tr,int l,int r,long long x){
    if(l>tr||tl>r) return;
    if(l<=tl&&tr<=r){
        // cout<<"ADD "<<l<<" "<<r<<" "<<tl<<" "<<tr<<endl;
        t[now].add(x);
        // cout<<"ADD "<<t[now].mx<<" "<<t[now].lzy<<endl;
        return;
    }
    int mid=tl+tr>>1;
    if(l<=mid){
        t[now].ls=++cnt_t;
        if(t[lst].ls) t[t[now].ls]=t[t[lst].ls];
        else t[t[now].ls].init_v(tl,mid);
        add(t[now].ls,t[lst].ls,tl,mid,l,r,x);
        // push_up(t[now].ls);
    } 
    if(r>mid){
        t[now].rs=++cnt_t;
        if(t[lst].rs) t[t[now].rs]=t[t[lst].rs];
        else t[t[now].rs].init_v(mid+1,tr);
        add(t[now].rs,t[lst].rs,mid+1,tr,l,r,x);
        // push_up(t[now].rs);
    } 
    push_up(now,mid,tr);
}
int TTT=0;
long long get_mx(int now,int tl,int tr,int l,int r){
    // if(TTT) cout<<tl<<" "<<tr<<" "<<l<<"/"<<r<<" "<<t[now].mx<<" "<<t[now].lzy<<endl;
    if(l<=tl&&tr<=r){
    // if(tl==tr){
        if(!now) return 1ll*tr*d;
        return t[now].mx;
    }
    int mid=tl+tr>>1;
    long long mx=-inf;
    if(l<=mid) mx=max(mx,get_mx(t[now].ls,tl,mid,l,r));
    if(r>mid) mx=max(mx,get_mx(t[now].rs,mid+1,tr,l,r));
    return mx+t[now].lzy;
}
struct str{
    long long l,r,x;
}q[100005];
bool operator <(str x,str y){
    if(x.r!=y.r)
    return x.r<y.r;
    return x.l<y.l;
}
void solve(int ql,int qr,int l,int r){
    if(ql>qr) return;
    int mid=ql+qr>>1;
    
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C=read(),T=read();
    while(T--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            int x=read(),y=read(),z=read();
            q[i]={x-y+1,x,z};
        }
        sort(q+1,q+m+1);
        int rt=1; cnt_t=1,t[1].init_v(0,n);
        long long ans=0;
        long long pre=0;
            // for(int j=0;j<=n;j++) cout<<get_mx(rt,0,n,j,j)<<" "; puts("");
        for(int i=1;i<=m;i++){
            if(q[i].r-q[i].l+1>k) continue;
            int rt0=rt; rt=++cnt_t,t[rt]=t[rt0];
            // cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].x<<endl;
            add(rt,rt0,0,n,0,q[i].l,q[i].x);
            // for(int j=0;j<=n;j++) cout<<get_mx(rt,0,n,j,j)<<" "; puts("");
            if(i==m) TTT=1;
            long long f=get_mx(rt,0,n,q[i].r-k+1,q[i].r)-1ll*(q[i].r+1)*d;
            TTT=0;
            // cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].x<<endl;
            // cout<<q[i].r-k+1<<" "<<q[i].l<<endl;
            // cout<<f<<"/"<<f+1ll*(q[i].r+1)*d<<" "<<ans<<endl;
            ans=max(ans,f);
            // cout<<f<<" "<<ans<<endl;
            rt0=rt; 
            if(f>pre) rt=++cnt_t,t[rt]=t[rt0],add(rt,rt0,0,n,q[i].r+2,n,f-pre),pre=f;
            // for(int j=0;j<=n;j++) cout<<get_mx(rt,0,n,j,j)<<" "; puts("");
        }
        cout<<ans<<endl;
    }
    return 0;
}