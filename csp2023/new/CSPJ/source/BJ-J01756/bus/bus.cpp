#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct node{
    int u,a;
};
vector<node> G[N];
bool vis[N];
int ans,c=2147483647;
void dfs(int id,int chu,int cnt){
    if(id==n){
        vis[n]=0;
            //cout<<chu<<" "<<cnt<<endl;
        if((cnt-chu)%k==0){
            if(cnt-chu<c){
                c=cnt-chu;
                ans=chu;
            }
        }
    }
    for(auto i:G[id]){
        int u=i.u,w=i.a;
        if(!vis[u]){
            vis[u]=1;
            dfs(u,chu+max(0,w-cnt),cnt+max(0,w-cnt)+1);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,a;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a;
        G[u].push_back({v,a});
    }
    vis[1]=1;
    dfs(1,0,0);
    cout<<(ans+c+k-1)/k*k;
    return 0;
}