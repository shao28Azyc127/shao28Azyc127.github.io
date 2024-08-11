#include<bits/stdc++.h>
#define gc() getchar()
typedef long long ll;
using namespace std;
const int N=100010;
inline ll read(){
    ll a=0,b=1;
    char c=gc();
    while(c<'0'||c>'9'){
        if(c=='-'){
            b=-1;c=gc();break;
        }
        c=gc();
    }
    while(c>='0'&&c<='9'){
        a=a*10+(c-'0');c=gc();
    }
    return a*b;
}
int n,f[N],depth[N],m;
ll a[N],b[N],c[N],fstday[N];
vector<int>E[N],D[N];
void dfs(int dot,int fa){
    f[dot]=fa;depth[dot]=depth[fa]+1;
    D[depth[dot]].push_back(dot);
    m=max(m,depth[dot]);
    for(int i:E[dot]){
        if(i==fa)continue;
        dfs(i,dot);
    }
}
int late[N];
int getLate(int ed,ll a,ll b,ll c,ll fir){
    if(c>=0||(c<0&&ed<=fir)){
        __int128 l=0,r=ed,mid,cnt=-1;
        while(l<=r){
            mid=(l+r)>>1;
            __int128 height=(ed-mid+1)*b+(ed-mid+1)*mid*c+(ed-mid)*(ed-mid+1)/2*c;
            if(height>=a){
                cnt=mid;l=mid+1;
            }else r=mid-1;
        }
        return cnt;
    }
    __int128 l=0,r=ed,mid,cnt=-1;
    while(l<=r){
        mid=(l+r)>>1;
        __int128 height=(fir-mid+1)*b+(fir-mid+1)*mid*c+(fir-mid)*(fir-mid+1)/2*c+(ed-fir);
        if(height>=a){
            cnt=mid;l=mid+1;
        }else r=mid-1;
    }
    return cnt;
}
int dp[40][N];
bool ck(int x,int Time){
    //printf("-----%d-----\n",x);
    for(int i=1;i<=n;i++){
        late[i]=getLate(x,a[i],b[i],c[i],fstday[i]);
        if(late[i]>n)late[i]=n;
        //cout<<i<<' '<<late[i]<<'\n';
        if(late[i]<depth[i])return 0;
    }
    //memset(dp,0,sizeof dp);
    //for(int i=1;i<=n;i++)dp[i]=0;
    for(int i=m;i>=1;i--){
        for(int j:D[m]){
            dp[Time][late[j]]++;if(dp[Time][late[j]]>late[j])return 0;
            late[f[j]]=min(late[f[j]],late[j]-1);
        }
    }
    for(int i=1;i<=n;i++){
        dp[Time][i]+=dp[Time][i-1];
        if(dp[Time][i]>i)return 0;
    }
    return 1;
}
int getFst(ll b,ll k){
    int l=0,r=1000000000,mid,cnt;
    while(l<=r){
        mid=(l+r)>>1;
        if(b+mid*k>=1){
            l=mid+1,cnt=mid;
        }else r=mid-1;
    }
    return cnt;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();b[i]=read();c[i]=read();
        if(c[i]<0)fstday[i]=getFst(b[i],c[i]);
        //cout<<i<<' '<<fstday[i]<<'\n';
    }
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        E[u].push_back(v);E[v].push_back(u);
    }
    dfs(1,0);
    int l=0,r=1000000000,mid,ans,time=0;
    while(l<=r){
        mid=(l+r)>>1;
        //cout<<mid<<'\n';
        if(ck(mid,++time)){
            ans=mid;r=mid-1;
        }else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}
