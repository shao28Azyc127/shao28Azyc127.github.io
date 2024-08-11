#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=100010;
ll n,a[N],b[N],c[N],cnt[N],fa[N],dp[N],ans;
vector <ll> g[N];
bool cmp(ll x,ll y){
    return x>y;
}
void dfs(ll x,ll f){
    dp[x]=cnt[x];
    vector<ll> _cnt;
    fa[x]=f;
    for(auto i : g[x]){
        if(i==f)continue;
        dfs(i,x);
        _cnt.push_back(dp[i]);
    }
    sort(_cnt.begin(),_cnt.end(),cmp);
    for(int i=0;i<_cnt.size();i++){
        dp[x]=max(dp[x],_cnt[i]+i+1);
    }
    return ;
}
void tell(){
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
    cout<<endl;
    return ;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        if(b[i]<=0)cnt[i]=a[i];
        else if(a[i]%b[i])cnt[i]=a[i]/b[i]+1;
        else cnt[i]=a[i]/b[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    //tell();
    cout<<dp[1]<<endl;
    return 0;
}

