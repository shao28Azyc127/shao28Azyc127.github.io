#include<bits/stdc++.h>
#define ll long long
const int N=100010;
using namespace std;
int a[N],c,t,n,m;
vector<pair<int,int> > g[N];
int dp[N],vis[N];
bool flag=true;
void dfs(int x){
    for(auto i:g[x]){
        if(vis[i.first]) continue;
        if(i.second==1){
            dp[i.first]=dp[x];
            vis[i.first]=1;
            dfs(i.first);
        }else{
            dp[i.first]=-dp[x];
            vis[i.first]=1;
            dfs(i.first);
        }
    }
    return;
}
void dfs2(int x){
    if(!flag) return;
    for(auto i:g[x]){
        int temp;
        if(i.second==1){
            temp=dp[x];
        }else{
            temp=-dp[x];
        }
        if(dp[i.first]==0){
            dp[i.first]=temp;
            dfs2(i.first);
        }
        else if(dp[i.first]==temp){
            continue;
        }
        else if(dp[i.first]!=temp){
            flag=false;
            //cout<<vis[2]<<endl;
            return;
        }
    }
    return;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i]=i;
            dp[i]=0;
            vis[i]=0;
            g[i].clear();
        }
        dp[0]=0;
        g[0].clear();
        dp[100001]=1;
        g[100001].clear();
        for(int i=1;i<=m;i++){
            char c;
            int x,y;
            cin>>c;
            if(c=='T'){
                cin>>x;
                a[x]=100001;
            }
            if(c=='F'){
                cin>>x;
                a[x]=-100001;
            }
            if(c=='U'){
                cin>>x;
                a[x]=0;
            }
            if(c=='+'){
                cin>>x>>y;
                a[x]=a[y];
            }
            if(c=='-'){
                cin>>x>>y;
                a[x]=-a[y];
            }
        }
        for(int i=1;i<=n;i++){
            //cout<<i<<" "<<a[i]<<endl;
            if(a[i]<0){
                g[i].push_back({-a[i],-1});
                g[-a[i]].push_back({i,-1});
            }else{
                g[i].push_back({a[i],1});
                g[a[i]].push_back({i,1});
            }
        }
        vis[0]=1;
        dfs(0);
        dfs(100001);
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            dp[i]=1;
            flag=true;
            dfs2(i);
            vis[i]=1;
            if(flag){
                dfs(i);
            }else{
                //cout<<i<<endl;
                dp[i]=0;
                dfs(i);
            }
        }
        //xunhuanzhao==0
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dp[i]==0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
