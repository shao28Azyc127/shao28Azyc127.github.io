#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN], b[MAXN], c[MAXN];
bool vis[MAXN];
int cnt[MAXN], ans=1e9;
vector<int> mp[MAXN];
int n;
bool check(){
    for(int i=1;i<=n;i++){
        if(cnt[i]<a[i]) return false;
    }
    return true;
}
void up(int x){
    for(int i=1;i<=n;i++){
        if(vis[i]) cnt[i]+=max(b[i]+x*c[i], 1);
    }
}
void down(int x){
    for(int i=1;i<=n;i++){
        if(vis[i]) cnt[i]-=max(b[i]+x*c[i], 1);
    }
}
void print(){
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
}
void dfs(int x){
    //cout<<x<<endl;
    //print();
    if(check()){
        ans=min(ans, x);
        //cout<<"ans="<<ans<<endl;
        return;
    }
    if(x>=n){
        up(x+1);
        dfs(x+1);
        down(x+1);
    }
    else{
        for(int i=2;i<=n;i++){
            if(vis[i]) continue;
            bool flag=false;
            int len=mp[i].size();
            for(int j=0;j<len;j++){
                if(vis[mp[i][j]]) flag=true;
            }
            if(!flag) continue;
            vis[i]=true;
            //cout<<x+1<<endl;
            //cout<<"i="<<i<<endl;
            up(x+1);
            dfs(x+1);
            down(x+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for(int i=1;i<n;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vis[1]=true;
    up(1);
    dfs(1);
    cout<<ans;
    return 0;
}

