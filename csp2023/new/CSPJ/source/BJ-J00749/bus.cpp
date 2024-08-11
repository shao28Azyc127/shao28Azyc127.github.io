#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll to,ti;
};
vector<node> g[10005];
bool vis[10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        ll u,v,d;
        cin>>u>>v>>d;
        g[u].push_back(node{v,d});
    }
    if(k==1){
        queue<node> q;
        q.push(node{1,0});
        while(!q.empty()){
            node u=q.front();
            q.pop();
            if(u.to==n){
                cout<<u.ti;
                return 0;
            }
            for (auto i:g[u.to]){
                if(!vis[i.to]){
                    vis[i.to]=1;
                    q.push(node{i.to,u.ti+1});
                }
            }
        }
        cout<<"-1";
        return 0;
    }
    cout<<"-1";

    return 0;
}
