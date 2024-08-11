#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll x=0,cnt=0,mx=0;
};
struct edge{
    ll v=0,w=0;
};
vector<edge> arr[10005];
ll n,m,k;
ll mn=-1;
ll bfs(){
    queue<node> q;
    q.push({1,0,0});
    ll ans=-1;
    while(!q.empty()){
        node top=q.front();
        if(top.cnt>mn&&mn>0)break;
        if(top.x==n&&top.cnt%k==0){
            mn=top.cnt;
            if(ans==-1){
                if(top.mx%k==0){
                    ans=top.mx+top.cnt;
                }
                else{
                    ans=(top.mx/k+1)*k+top.cnt;
                }
            }
            else{
                if(top.mx%k==0){
                    ans=min(ans,top.mx+top.cnt);
                }
                else{
                    ans=min(ans,(top.mx/k+1)*k+top.cnt);
                }
            }
        }
        for(auto v:arr[top.x]){
            ll mx=max(v.w-top.cnt,top.mx);
            q.push({v.v,top.cnt+1,mx});
        }
        q.pop();
    }
    return ans;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edge temp;
        temp.v=v,temp.w=w;
        arr[u].push_back(temp);
    }
    cout<<bfs();
    return 0;
}
