#include<bits/stdc++.h>
#define ll long long
#define db double
#define lll __int128
#define pb push_back
#define mp make_pair
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
    x=x*f;
}

const int N=1e5+5;
const ll inf=1e18+5;

int n;
ll a[N],b[N],c[N];
int x,y;
struct edge{
    int next,to,w;
}e[N<<1];
int head[N],cnt;
void add(int x,int y){
    e[++cnt].next=head[x];
    e[cnt].to=y,head[x]=cnt;
}

ll ans;
bool vis[N];
int can[N];
ll get_sum(int i,ll t){
    return b[i]*t+c[i]*((t+1)*t/2);
}
ll calc(int i,ll t){
    if(c[i]<0&&t>(b[i]-1)/(-c[i])){
        ll t2=(b[i]-1)/(-c[i]);
        return get_sum(i,t2)+(t-t2);
    }
    else return get_sum(i,t);
}
ll check(int i,ll st){
    if(!i) return 0;
    if(!c[i]) return (a[i]-1)/b[i]+st;
    ll stv=calc(i,st-1);
    ll l=1,r=1e9+5;
    while(l<=r){
        ll mid=l+r>>1;
        if(calc(i,mid)-stv>=a[i]) r=mid-1;
        else l=mid+1;
    }
    return l;
}

int id[N],mxp;
bool cmp(int i,int j){
    if(c[i]*c[j]<0) return c[i]<c[j];
    else return check(i,1)>check(j,1);
}
int tot;
void dfs(int s,ll mx){
    if(mx>=ans) return ;
    if(s==n+1) return (void)(ans=mx);
    tot++;
    if(tot%10000==0){
        if((db)clock()/CLOCKS_PER_SEC>0.97){
            printf("%lld\n",ans);
            exit(0);
        }
        //cout<<tot<<endl;
    }
    for(int x=1;x<=n;x++){
        int i=id[x];
        if(can[i]&&!vis[i]){
            for(int j=head[i];j;j=e[j].next)
                can[e[j].to]++;
            vis[i]=1;
            //cout<<i<<" "<<s<<" "<<check(i,s)<<endl;
            dfs(s+1,max(mx,check(i,s)));
            vis[i]=0;
           for(int j=head[i];j;j=e[j].next)
                can[e[j].to]--;
        }
    }
}

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    read(n);
    ans=inf;
    for(int i=1;i<=n;i++){
        read(a[i]),read(b[i]),read(c[i]);
        if(check(i,1)>check(mxp,1)) mxp=i;
    }
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<n;i++){
        read(x),read(y);
        add(x,y),add(y,x);
    }
    can[1]=1;
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}

// g++ 1.cpp -o 1 -O2 -std=c++14
