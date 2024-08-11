#include<bits/stdc++.h>
using namespace std;
priority_queue< pair<int, int> > q;
int n, m, k;
struct Node{
    int x, ti;
};
vector<Node> a[10005];
bool vis[10005];
long long ans[10005];
void make(){
    ans[1]=k;
    q.push(make_pair(ans[1], 1));
    while(!q.empty()){
        int t=q.top().first;
        int id=q.top().second;
        //cout<<id<<" "<<t<<endl;
        q.pop();
        if(vis[id]) continue;
        vis[id]=true;
        for(int i=0;i<a[id].size();i++){
            int nx=a[id][i].x, nt=a[id][i].ti;
            if(max(t, nt)+1<ans[nx]){
                ans[nx]=max(t, nt)+1;
                //cout<<ans[nx]<<" "<<nx<<endl;
                q.push(make_pair(ans[nx], nx));
            }
        }
    }
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u, v, p;
        cin>>u>>v>>p;
        a[u].push_back(Node{v, p});
    }
    memset(ans, 0x3f, sizeof(ans));
    long long maxs=ans[n];
    make();
    //cout<<ans[n]<<endl;
    if(ans[n]==maxs){
        cout<<"-1";
        return 0;
    }
    if(ans[n]%k!=0) ans[n]+=k-(ans[n]%k);
    cout<<ans[n];
    return 0;
}
