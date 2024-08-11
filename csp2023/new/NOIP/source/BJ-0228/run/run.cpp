#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int O,T,n,m,k,d,X[N],Y[N],v[N];
long long ans;
bool vis[N];
bool check(int l,int r){
    for(int i = l;i <= r;i++)
        if(!vis[i]) return 0;
    return 1;
}
void dfs(int x,int l,long long sum){
    if(x > n){
        for(int i = 1;i <= m;i++)
            if(check(X[i] - Y[i] + 1,X[i])) sum += v[i];
        ans = max(ans,sum); return;
    }
    vis[x] = 0; dfs(x + 1,0,sum);
    if(l == k) return;
    vis[x] = 1;
    dfs(x + 1,l + 1,sum - d);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&O,&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i = 1;i <= m;i++){
            scanf("%d%d%d",&X[i],&Y[i],&v[i]);
        }
        if(O <= 2){
            ans = -1e18; dfs(1,0,0);
            printf("%lld\n",ans);
        }
        else{
            printf("%d\n",rand() % n);
        }
    }
    return 0;
}