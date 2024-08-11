#include<bits/stdc++.h>
using namespace std;

//#define LOCAL

#define MAXN 100005

int n,l1[MAXN],fa[MAXN];
long long a[MAXN],b[MAXN],c[MAXN];

int ru,rv;
int al,ar;
vector<int> g[MAXN];

struct Node{
    int p,t; // point time

    bool operator<(const Node& x)const{
        if(t!=x.t){
            return t>x.t;
        }else{
            return p>x.p;
        }
    }
}pl[MAXN];

long long gsum(int p,int r){
    if(r<0){
        return -1e18;
    }else if(r==0){
        return 0;
    }
    long long ret=0;
    if(r>=l1[p]){
        ret+=r-l1[p]+1;
        r=l1[p]-1;
    }
    return ret+r*b[p]+((long long)(r+1)*r*c[p])/2;
}

long long gsum(int p,int l,int r){
    return gsum(p,r)-gsum(p,l-1);
}

int bs(int p,int ans){
    int tl=0,tr=ans;
    while(tl<tr){
        int tmid=(tl+tr+1)>>1;
        if(gsum(p,tmid,ans)<a[p]){
            tr=tmid-1;
        }else{
            tl=tmid;
        }
    }

    return tl;
}

void calc(int u,int ans){
    pl[u].t=bs(u,ans);
    for(auto v:g[u]){
        if(v==fa[u]){
            continue;
        }
        fa[v]=u;
        calc(v,ans);
        pl[u].t=min(pl[u].t,pl[v].t+1);
    }

    return;
}

priority_queue<Node> priq;

void clear(){
    while(!priq.empty()){
        priq.pop();
    }

    return;
}

bool ok(int ans){
    clear();
    calc(1,ans);
    priq.push(pl[1]);
    for(int i=1;i<=n;i++){
        Node now=priq.top();
        priq.pop();
        if(now.t<i){
            return false;
        }
        int nu=now.p;
        for(auto so:g[nu]){
            if(so==fa[nu]){
                continue;
            }
            priq.push(pl[so]);
        }
    }

    return true;
}

int main(){
    #ifndef LOCAL
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    #endif

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);

        pl[i].p=i;
        if(c[i]>=0){
            l1[i]=0x3f3f3f3f;
        }else{
            l1[i]=(a[i]-c[i]+1)/(-c[i]);
        }
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&ru,&rv);
        g[ru].push_back(rv);
        g[rv].push_back(ru);
    }
    al=n,ar=1000000000;
    while(al<ar){
        int amid=(al+ar)>>1;
        if(ok(amid)){
            ar=amid;
        }else{
            al=amid+1;
        }
    }
    printf("%d\n",al);

    return 0;
}

// For Irena ...
// For Stars ...