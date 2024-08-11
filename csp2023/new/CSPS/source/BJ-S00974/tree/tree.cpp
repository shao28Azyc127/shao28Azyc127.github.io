
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
inline int read(){
    int i=getchar(),r=0,s=1;
    while(i<'0'||i>'9'){if(i=='-')s=-1;i=getchar();}
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r*s;
}
const int N=100100,M=21;
int n,head[N],to[N<<1],nex[N<<1];
using bigint=__int128_t;
bigint a[N],b[N],c[N];
// int dep[N];
// void get_dep(int nd,int dep_=0,int fa=0)[
//     dep[nd]=dep_;
//     for(int i=head[nd];i;i=nex[i])if(to[i]!=fa)get_dep(to[i],dep_+1,nd);
// ]
void init(){
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),c[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        to[i<<1]=v;
        nex[i<<1]=head[u];
        head[u]=i<<1;
        to[i<<1|1]=u;
        nex[i<<1|1]=head[v];
        head[v]=i<<1|1;
    }
    // get_dep(1);
}
// inline bigint v(bigint day,int p){return max(1ll,b[p]+c[p]*day);}
inline bigint get_sum(int p,bigint day){
    if(c[p]>=0)return b[p]*day+day*(1+day)/2*c[p];
    else{
        bigint lim=(b[p]-1)/abs(c[p]);
        if(day<=lim)return b[p]*day+day*(1+day)/2*c[p];
        else return b[p]*lim+lim*(1+lim)/2*c[p]+day-lim;
    }
}
const int inf=0x3f3f3f3f;
inline int calc(int p,int s){
    int l=s,r=inf;
    bigint sum=get_sum(p,s-1);
    while(l<r){
        int mid=(l+r)>>1;
        if(get_sum(p,mid)-sum>=a[p])r=mid;
        else l=mid+1;
    }
    return l;
    // int t=s;
    // int res=v(s,p);
    // while(res<a[p])res+=v(++t,p);
    // return t;
}
int f[1<<M];
int nexs[1<<M];
int sta[1<<M];
int pop[1<<M];
inline int pop_count(int x){
    int cnt=0;
    while(x)cnt++,x-=x&-x;
    return cnt;
}
inline bool cmp(int x,int y){return pop[x]<pop[y];}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    init();
    // cout<<(int)get_sum(2,3)<<' '<<(int)get_sum(2,5)<<endl;
    // cout<<calc(2,4)<<endl;
    for(int i=0;i<(1<<n);i++)pop[i]=pop_count(i);
    for(int i=1;i<(1<<n);i++)sta[i]=i;
    sort(sta+1,sta+(1<<n),cmp);
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    nexs[0]=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++)if((i&(1<<(j-1)))){
            for(int k=head[j];k;k=nex[k])if(!(i&(1<<(to[k]-1))))nexs[i]|=(1<<(to[k]-1));
        }
    }
    for(int i=0;i<(1<<n);i++){
        int s=sta[i];
        for(int j=1;j<=n;j++)if(nexs[s]&(1<<(j-1))){
            int nx=s|(1<<(j-1));
            f[nx]=min(f[nx],max(f[s],calc(j,pop[s]+1)));
        }
    }
    cout<<f[(1<<n)-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}