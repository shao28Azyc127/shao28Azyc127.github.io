#include<bits/stdc++.h>
using namespace std;
bool vis[2000000];
int n,m,k,u,v,a,dis[2000000];
vector<pair<int,int> >g[2000000];
priority_queue<pair<int,int> >q;
pair<int,int>t;
int pst(int x,int y){
    if(x<y){
        return x+ceil(double(y-x)/k)*k;
    }else{
        return x;
    }
}
void dij(){
    memset(dis,0x3f,sizeof(dis));
    q.push(make_pair(0,k));
    if(0){
        Break:
            cout<<dis[n*k];
            return;
    }
    q.push(make_pair(0,k));
    for(int i=1;i<=n*k;i++){
        do{
            if(q.size()){
                t=q.top();
                q.pop();
            }else{
                goto Break;
            }
        }while(vis[t.second]);
        vis[t.second]=1;
        dis[t.second]=t.first;
        for(auto&it:g[t.second]){
            q.push(make_pair(pst(t.first,it.second)+1,it.first));
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a;
        for(int j=0;j<k;j++){
            g[u*k+j].push_back(make_pair(v*k+(j+1)%k,a));
        }
    }
    dij();
}
