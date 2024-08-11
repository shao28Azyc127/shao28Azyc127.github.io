#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+100;
int n,m,k,ans;
vector<int> g[maxn];
vector<int> t[maxn];
bool s[maxn][100000];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
void bfs(int st,int hour){
    queue<int> q;
    q.push(st);
    s[st][hour]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        cout<<x<<' '<<g[x].size()<<endl;
        for(int i=0;i<g[x].size();i++){
            bool flag=0;
            int xx=g[x][i];
            int mintime=t[x][i];
            cout<<mintime<<endl;
            for(int j=0;j<=100000;j++){
                if(s[x][j]){
                    if(j<mintime) continue;
                    if(xx==n && (j+1)%k==0){
                        cout<<j+1<<endl; ans=1;
                        return;
                    }
                    if(s[xx][j+1]==0) s[xx][j+1]=1,flag=1;
                }
            }
            if(flag) q.push(xx);
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,tim; cin>>u>>v>>tim;
        g[u].push_back(v);
        t[u].push_back(tim);
    }
//    bfs(1,k);
//    int i=2;
//    while(ans!=1) bfs(1,k*i);
//    if(ans!=1)
        cout<<-1<<endl;
    return 0;
}
