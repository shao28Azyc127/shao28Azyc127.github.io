#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
using namespace std;
const int N=2e6+7;
int ans[N],n,pos[N],pit[N];
long long AA;
char s[N];
vector<int>G[N];
int dfs(int u){
    if(ans[u]!=-1)return ans[u];
    ans[u]=1;
    for(auto v:G[u])
        ans[u]+=dfs(v);
    return ans[u];
}
main(){
    memset(ans,-1,sizeof ans);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
//    freopen("tc.out","w",stdout);
    cin>>n;
    scanf("%s",s+1);
    rep(i,n){
        if(s[i]==s[i-1]){
            G[i-1].pb(i+1);pit[i]=i-1;continue;
        }
        int j=pit[i-1];
        while(j){
            if(s[j-1]==s[i])break;
            j=pit[j-1];
        }
        if(j&&s[j-1]==s[i])pit[i]=j-1,G[j-1].pb(i+1);
    }
    rep(i,n)dfs(i);
    rep(i,n)
    AA+=ans[i]-1;
    cout<<AA;
    return 0;
}
