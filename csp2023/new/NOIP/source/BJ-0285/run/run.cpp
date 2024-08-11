#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
}

const int N=1e5+5;

int n,m,k,d,x,y,v;
int C,T;

ll f[N],g[N];

vector<pair<int,int> >w[N];

#define l(x) x<<1
#define r(x) x<<1|1
struct tree{
    ll mx[N<<2],tag[N<<2];
    void push_tag(int x,ll s){
        mx[x]+=s,tag[x]+=s;
    }
    void push_down(int x){
        push_tag(l(x),tag[x]);
        push_tag(r(x),tag[x]);
        tag[x]=0;
    }
    void push_up(int x){
        mx[x]=max(mx[l(x)],mx[r(x)]);
    }
    void rebuild(int x,int l,int r){
        mx[x]=tag[x]=0;
        if(l==r) return ;
        int mid=l+r>>1;
        rebuild(l(x),l,mid),rebuild(r(x),mid+1,r);
    }
    void update(int x,int l,int r,int l2,int r2,ll s){
        if(l>=l2&&r<=r2) return push_tag(x,s);
        int mid=l+r>>1;
        push_down(x);
        if(l2<=mid) update(l(x),l,mid,l2,r2,s);
        if(r2>mid) update(r(x),mid+1,r,l2,r2,s);
        push_up(x);
    }
    ll query(int x,int l,int r,int l2,int r2){
        if(l>=l2&&r<=r2) return mx[x];
        int mid=l+r>>1;
        ll res=0;
        push_down(x);
        if(l2<=mid) res=query(l(x),l,mid,l2,r2);
        if(r2>mid) res=max(res,query(r(x),mid+1,r,l2,r2));
        push_up(x);
        return res;
    }
}t;

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    read(C),read(T);
    while(T--){
    if(C<=14){
    read(n),read(m),read(k),read(d);
    for(int i=1;i<=n;i++)
        w[i].clear();
    t.rebuild(1,0,n);
    for(int i=1;i<=m;i++){
        read(x),read(y),read(v);
        w[x].push_back(mp(y,v));
    }
    for(int i=1;i<=n;i++)
        if(w[i].size()) sort(w[i].begin(),w[i].end());
    f[0]=0;
    /*for(int i=1;i<=n;i++)
        g[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<w[i].size();j++)
            if(i-w[i][j].first<0) break;
            else g[i-w[i][j].first+1]+=w[i][j].second;
        f[i]=f[i-1];
        ll pre=0;
        for(int j=i;j>=max(1,i-k+1);j--){
            pre+=g[j]-d;
            //cout<<pre<<" ";
            f[i]=max(f[i],f[max(0,j-2)]+pre);
        }
        //cout<<f[i]<<endl;
    }*/

    t.update(1,0,n,0,0,-d);
    for(int i=1;i<=n;i++){
        ll pre=0;
        for(int j=0;j<w[i].size();j++)
            if(i-w[i][j].first<0) break;
            else t.update(1,0,n,0,i-w[i][j].first,w[i][j].second);
        f[i]=max(f[i-1],t.query(1,0,n,max(i-k,0),i-1));
        t.update(1,0,n,i,i,f[i-1]);
        t.update(1,0,n,0,i,-d);
        //cout<<f[i]<<endl;
    }
    printf("%lld\n",f[n]);
    }
    else{
    read(n),read(m),read(k),read(d);
    ll ans=0;
    for(int i=1;i<=m;i++){
        read(x),read(y),read(v);
        if(y<=min(x,k)&&1ll*v>=y*d) ans+=v-y*d;
    }
    printf("%lld\n",ans);
    }
    }
    return 0;
}
