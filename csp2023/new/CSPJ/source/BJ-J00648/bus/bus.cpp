#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=1e4+10;
struct T{
    int x,d;
};
int n,m,k,mx,ans,cnt;
int vis[maxn],tot,w;
bool isc[maxn];
vector<T> e[maxn];
queue<int> qc;
void bfs(int x){
    int cnt=0;
    queue<T> q;
    q.push({1,x});
    while(q.size()){
        T u=q.front();q.pop();
        if(u.d>=ans) continue;
        if(u.x==n&&u.d%k==0){
            ans=min(ans,u.d);
            return;
        }
        for(T v:e[u.x]) if(u.d>=v.d){
            q.push({v.x,u.d+1});
        }
    }
}
void s1(){
    ans=n+m+mx+1000;
    if(ans>=1e6+3e4){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<ans;i+=k){
        bfs(i);
        //cout<<ans<<endl;
    }
    if(ans==n+m+mx+1000) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;cin>>u>>v>>a;
        e[u].push_back({v,a});
        mx=max(mx,a);
    }
    s1();
    return 0;
}
