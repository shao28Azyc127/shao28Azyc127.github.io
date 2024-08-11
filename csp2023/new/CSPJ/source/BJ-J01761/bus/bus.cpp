#include <iostream>
#include <cstdlib>
#include <vector>
#define INF 0x7fffffff
using namespace std;

int n,m,k;
vector<int> mapp[10005];
bool vis[10005];
int ans[10005],ansss=INF,cnt=0;

void dfs(int cur,int anss){
    vis[cur]=true;
    ans[cur]=min(ans[cur],anss);
    if(cur==n){
        if(anss%k==0){
            ansss=min(ansss,anss);
        }
    }for(vector<int>::iterator iter=mapp[cur].begin();iter<mapp[cur].end();iter++){
        if(!vis[*iter]) dfs(*iter,anss+1);
    }vis[cur]=false;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++) ans[i]=INF;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mapp[a].push_back(b);
    }dfs(1,0);
    if(ansss==INF) cout<<-1;
    else cout<<ansss;
    return 0;
}
