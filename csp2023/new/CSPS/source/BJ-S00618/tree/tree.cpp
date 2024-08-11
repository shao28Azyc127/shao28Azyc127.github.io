#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,ans=1e9,vis[N];
struct T{
    int a;
    int b;
    int c;
}t[N];
vector<int> G[N];
int check(){
    int tot=0;
    for(int i=1;i<=n;i++){
        int p=ceil(t[i].a/max(t[i].b,1));
        tot=max(tot,vis[i]+p-1);
    }
    return tot;
}
void dfs(int x){
    if(x==n){
       ans=min(ans,check());
       return;
    }
    for(int i=2;i<=n;i++){
        if(vis[i]==0){
            vis[i]=x+1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b>>t[i].c;
    }
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vis[1]=1;
    dfs(1);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}