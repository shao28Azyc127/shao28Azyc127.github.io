#include<bits/stdc++.h>
using namespace std;
struct st{
    long long to,t;
};
vector<st> mp[10005];
long long n,m,k,ans=1e9+7;
void dfs(long long x,long long t,long long maxn){
    if(x==n && t%k==0){
        if(maxn%k==0)ans=min(ans,maxn+t);
        else ans=min(ans,(maxn/k+1)*k+t);
        return;
    }
    for(int b=0;b<mp[x].size();b++){
        dfs(mp[x][b].to,t+1,max(maxn,mp[x][b].t-t));
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int b=1;b<=m;b++){
        long long x,y,z;
        cin>>x>>y>>z;
        st nb;
        nb.to=y;
        nb.t=z;
        mp[x].push_back(nb);
    }
    dfs(1,0,0);
    if(ans==1e9+7)cout<<"-1";
    else cout<<ans;
    return 0;
}
