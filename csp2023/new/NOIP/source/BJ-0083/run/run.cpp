#include<bits/stdc++.h>
using namespace std;
const int NR=2e5+10;
#define int long long
int Tid,T,n,m,k,d,l[NR],r[NR],v[NR],f[NR];
struct point{
    int opt,v,id;
    bool operator <(const point &T)const{
        if(v!=T.v)return v<T.v;
        return opt>T.opt;
    }
}t[NR];

namespace brute_force{
    const int MR=2e3+10;
    int f[MR],sum[MR][MR],g[MR][MR],val[MR],len;
    void solve(){ 
        len=0;
        for(int i=1;i<=m;i++){
            int tmp;
            scanf("%lld%lld%lld",&r[i],&tmp,&v[i]);l[i]=r[i]+1-tmp;
            val[++len]=l[i];val[++len]=r[i];
        }
        sort(val+1,val+1+len);len=unique(val+1,val+1+len)-val-1;
        for(int i=1;i<=m;i++){
            l[i]=lower_bound(val+1,val+1+len,l[i])-val;
            r[i]=lower_bound(val+1,val+1+len,r[i])-val;
            g[l[i]][r[i]]+=v[i];
        }
        for(int i=0;i<len;i++)
            for(int j=1;j+i<=len;j++)sum[j][i+j]+=g[j][i+j]+sum[j][i+j-1]+sum[j+1][i+j]-sum[j+1][i+j-1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=len;i++){
            f[i]=f[i-1];
            for(int j=1;j<=i;j++)
                if(val[j]+k>val[i])f[i]=max(f[i],sum[j][i]+f[j-1]-d*(val[i]-val[j]+1));
        }
        cout<<f[len]<<endl;
        memset(sum,0,sizeof(sum));
        memset(g,0,sizeof(g));
    }
}

int maxv[NR<<2],tag[NR<<2];
#define lson (id<<1)
#define rson (id<<1|1)
#define mid ((l+r)>>1)
void update(int id){
    maxv[id]=max(maxv[lson],maxv[rson]);
}
void pushdown(int id){
    if(!tag[id])return;
    maxv[id]+=tag[id];
    tag[lson]+=tag[id];tag[rson]+=tag[id];
    tag[id]=0;
}
void buildtree(int id,int l,int r){
    tag[id]=0;
    if(l==r){
        maxv[id]=maxv[lson]=maxv[rson]=-1e18;
        return;
    }
    buildtree(lson,l,mid);
    buildtree(rson,mid+1,r);
    update(id);
}
void modify(int id,int l,int r,int pos,int k){
    pushdown(id);
    if(l==r){
        maxv[id]=k;
        // printf("modify:l:%lld %lld\n",l,k);
        return;
    }
    if(pos<=mid)modify(lson,l,mid,pos,k);
    else modify(rson,mid+1,r,pos,k);
    update(id);
    // printf("modify:l:%lld r:%lld pos:%lld k:%lld %lld\n",l,r,pos,k,maxv[id]);
}
void add(int id,int l,int r,int L,int R,int k){
    pushdown(id);
    if(r<L||R<l)return;
    if(L<=l&&r<=R){
        tag[id]+=k;pushdown(id);
    // printf("add:l:%lld r:%lld L:%lld R:%lld k:%lld maxv:%lld\n",l,r,L,R,k,maxv[id]);
        return;
    }
    add(lson,l,mid,L,R,k);
    add(rson,mid+1,r,L,R,k);
    update(id);
}

void solve(){
    cin>>n>>m>>k>>d;
    if(m<=1000){
        brute_force::solve();
        return;
    }
    int tot=0;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&r[i],&l[i],&v[i]);l[i]=r[i]+1-l[i];
        t[++tot]=(point){0,l[i],i};t[++tot]=(point){1,r[i],i};
    }
    sort(t+1,t+1+tot);
    int now=0,maxf=0;
    buildtree(1,1,tot);
    for(int i=1;i<=tot;i++){
        // printf("opt:%d v:%d %d\n",t[i].opt,t[i].v,t[i].id);
        while(t[now+1].v+k<=t[i].v)now++,modify(1,1,tot,now,-1e18);
        add(1,1,tot,1,i-1,-d*(t[i].v-t[i-1].v));
        if(t[i].opt==1){
            int tmp=upper_bound(t+1,t+1+tot,(point){-1,l[t[i].id],0})-t;
            // if(!(t[tmp-1].v<=l[t[i].id]&&t[tmp].v>l[t[i].id])){
            //     printf("i:%lld id:%lld l:%lld r:%lld %lld\n",i,t[i].id,l[t[i].id],t[i].v,t[tmp].v);
            // }
            assert(t[i].id&&t[i].id<=m);
            if(tmp>tot)assert(tmp<=tot+1);
            else assert(t[tmp].v>l[t[i].id]);
            // printf("i:%lld idx:%lld %lld tmp:%lld\n",i,t[i].id,f[i],tmp);
            add(1,1,tot,1,tmp-1,v[t[i].id]);
            f[i]=maxv[1]-d;maxf=max(maxf,f[i]);
        }
        else{
            modify(1,1,tot,i,maxf);
        }
    }
    cout<<maxf<<endl;
    for(int i=1;i<=tot;i++)t[i]=(point){0,0,0};
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>Tid>>T;
    while(T--)solve();
    return 0;
}