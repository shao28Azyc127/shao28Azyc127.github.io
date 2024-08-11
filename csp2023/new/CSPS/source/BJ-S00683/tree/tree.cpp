#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=100005;
const __int128 inf=1100000000000000000ll;
int n,b[maxn],c[maxn],fa[maxn],tag[maxn];
long long a[maxn];
vector<int> tree[maxn];
void dfs(int s){
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j];
        if(s_==fa[s])continue;
        fa[s_]=s;
        dfs(s_);
    }
}
pair<int,int> g[maxn];
long long cdcp(long long a,int b,int x){
    if(b>0){
        a=a+(long long)b*(x-1);
        b=-b;
    }
    if(a<=1)return x;
    else if(a+(long long)b*(x-1)>=1){
        return min((__int128)(2*a+(long long)b*(x-1))*x/2,inf);
    }
    else{
        int tmp=(a-1)/(-b)+1;
        //printf("d %d %d %d %d\n",tmp,a,b,x);
        return min((__int128)(2*a+(long long)b*(tmp-1))*tmp/2+x-tmp,inf);
    }
}
int calc(long long x,long long a,int b){
    int L=1,R=1000000001;
    while(L<R){
        int mid=L+R>>1;
        if(cdcp(a,b,mid)<x)L=mid+1;
        else R=mid;
    }
    return L;
}
bool check(int x){
    for(int i=1;i<=n;++i)tag[i]=0;
    tag[0]=1;
    int cnt=0;
    for(int i=1;i<=n;++i){
        long long tmp=min(x-calc(a[i],b[i]+(long long)c[i]*x,-c[i])+1,n);
        if(tmp<=0)return false;
        //printf("%d %d\n",i,tmp);
        g[++cnt]=make_pair(tmp,i);
    }
    sort(g+1,g+n+1);
    for(int i=1,now=0;i<=n;++i){
        now+=g[i].first-g[i-1].first;
        int x=g[i].second;
        while(!tag[x]){
            tag[x]=1;
            x=fa[x];
            --now;
        }
        if(now<0)return false;
    }
    return true;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        b[i]=read();
        c[i]=read();
    }
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    tree[0].push_back(1);tree[1].push_back(0);
    dfs(0);
    //cdcp(0,2,3);
    //check(5);
    int L=n,R=1000000000;
    while(L<R){
        int mid=L+R>>1;
        if(check(mid))R=mid;
        else L=mid+1;
    }
    printf("%d",L);
    return 0;
}