#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
typedef long long LL;

int A,B,C,D;
LL vis[N];
LL ans;
int n;
int h[N];
vector<int> g[N];
int u[N],v[N],cnt[N];
LL a[N],b[N],c[N];
LL dist_a[N],tim_d[N];

bool cmp_a(int x,int y){
    return dist_a[x]>dist_a[y];
}

bool cmp_d(int x,int y){
    return tim_d[x]>tim_d[y];
}

void add(int a,int b){
    g[a].push_back(b);
}

void get_cnt(int x,int fa){
    cnt[x]=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa) continue;
        get_cnt(y,x);
        cnt[x]+=cnt[y];
    }
}

void look_a(){
    for(int i=1;i<=n;++i) if(c[i]!=0) return;
    A=1;
}

void look_b(){
    for(int i=1;i<n;++i) if(u[i]!=i || v[i]!=i+1) return;
    B=1;
}

void look_c(){
    for(int i=1;i<=n;++i) if(g[i].size()>2) return;
    C=1;
}

void look_d(){
    for(int i=1;i<n;++i) if(u[i]!=1) return;
    D=1;
}

void go_a(int x,int fa){
    int sum=1;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa) continue;
        vis[y]=vis[x]+sum;
        sum+=cnt[x];
        go_a(y,x);
    }
}

void go_b(){
    for(int i=1;i<=n;++i){
        LL res=0;
        for(int t=i;res<a[i];++t){
            res+=max(1ll,b[i]+t*1ll*c[i]);
            ans=max(ans,t*1ll);
        }
    }
}

void go_d(){
    for(int i=1;i<=n;++i){
        LL res=0;
        for(int t=1;res<a[i];++t){
            res+=max(1ll,b[i]+t*1ll*c[i]);
            tim_d[i]=t*1ll;
        }
    }
    for(int i=1;i<=n;++i) h[i]=i;
    sort(h+2,h+1+n,cmp_d);
    for(int i=1;i<=n;++i){
        LL res=0;
        for(int t=i;res<a[i];++t){
            res+=max(1ll,b[i]+t*1ll*c[i]);
            ans=max(ans,t*1ll);
        }
    }
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",&u[i],&v[i]);
        add(u[i],v[i]),add(v[i],u[i]);
    }
    look_a();
    look_b();
    look_c();
    look_d();
    //printf("%d %d %d %d\n",A,B,C,D);
    if(B){
        ans=0;
        go_b();
        printf("%lld",ans);
        return 0;
    }
    if(D){
        ans=0;
        go_d();
        printf("%lld",ans);
        return 0;
    }
        for(int i=1;i<=n;++i){
            vis[i]=-1;
            dist_a[i]=a[i]/b[i];
            if(a[i]%b[i]) dist_a[i]++;
        }
        for(int i=1;i<=n;++i) sort(g[i].begin(),g[i].end(),cmp_a);
        vis[1]=1;
        go_a(1,0);
        ans=0;
        for(int i=1;i<=n;++i) ans=max(ans,dist_a[i]+vis[i]-1);
        printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
4
3 2 1
4 1 0
2 1 -2
5 7 2
1 2
2 3
3 4
*/