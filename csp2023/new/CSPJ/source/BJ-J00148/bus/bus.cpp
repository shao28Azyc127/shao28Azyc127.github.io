#include<bits/stdc++.h>
using namespace std;
struct e{
    int to,time;
};
const int maxn=50000;
int n,m,k;
vector<e> edge[maxn];
int t(int a,int b){
    int dif=b-a;
    dif/=k;
    dif++;
    dif*=k;
    return a+dif;
}
int bfs(){
    queue<e> q;
    e org;
    org.to=1,org.time=0;
    q.push(org);
    while(!q.empty()){
        e top = q.front();
        // cout << "{" << top.to <<',' << top.time << '}';
        if(top.to==n and top.time%k==0) return top.time;
        for(int i = 0;i < edge[top.to].size();i++){
            e tmp;
            tmp.to=edge[top.to][i].to;
            if(top.time+1<edge[top.to][i].time) tmp.time=t(top.time+1,edge[top.to][i].time);
            else tmp.time=top.time+1;
            q.push(tmp);
        }
        q.pop();
    }
    return -1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u,v,tm;
        cin >> u >> v >> tm;
        e psh;
        psh.to=v,psh.time=tm;
        edge[u].push_back(psh);
    }
    cout << bfs();
    return 0;
}