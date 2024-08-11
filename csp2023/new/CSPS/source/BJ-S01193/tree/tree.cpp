#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,ans=LONG_LONG_MAX;
int a[N],b[N],c[N];
vector<int> g[N];
int vis[N];
int cal(int i,int x){
    int l=x,r=1e18,mid,pos,add;
    while(l<r){
        mid=l+r>>1;
        if(b[i]+mid*c[i]<=1)r=mid;
        else l=mid+1;
    }
    pos=l;
    l=x,r=1e18,mid;
    while(l<r){
        mid=l+r>>1;
        int aa=b[i]+x*c[i],bb=b[i]+mid*c[i];
        if(aa<1)add=mid-x+1,aa=0,bb=0;
        else if(bb<1)add=bb-pos,bb=pos;
        else add=0;
        int num=mid-x+1,res=(aa+bb)*num/2+add;
        //printf("%lld %lld\n",mid,res);
        if(res<0 || res>=a[i])r=mid;
        else l=mid+1;
    }
    //printf("%lld %lld %lld\n",i,x,l);
    return mid;
}
void dfs(int stp,int mx){
    if(stp>=n){ans=min(ans,mx);return;}
    for(int u=0;u<=n;u++){
        if(!vis[u])continue;
        for(int v:g[u]){
            if(vis[v])continue;
            vis[v]=1;
            dfs(stp+1,max(mx,cal(v,stp+1)));
            vis[v]=0;
        }
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1),g[1].push_back(0);
    vis[0]=1;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
