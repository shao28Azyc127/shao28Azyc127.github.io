#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll c,t,n,m,k,d,x[maxn],y[maxn],v[maxn],vis[maxn],con[maxn],ans;
void dfs(int pos){
    if(pos==n+1){
        ll num=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) {
                con[i]=con[i-1]+1;
                num-=d;
            }
            else con[i]=0;
            if(con[i]>k) return ;
        }
        for(int i=1;i<=m;i++){
            if(con[x[i]]>=y[i]) num+=v[i];
        }
        ans=max(ans,num);
        return ;
    }
    vis[pos]=0;
    dfs(pos+1);
    vis[pos]=1;
    dfs(pos+1);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
        }
        ans=-1e18;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
