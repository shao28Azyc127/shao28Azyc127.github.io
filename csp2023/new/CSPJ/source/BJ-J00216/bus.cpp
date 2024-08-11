#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20010,inf=2e15;
int n,m,k,dp[N][101],vis[N];
struct bian{
    int u,v,a;
}b[N];
queue<int> q;
vector<int> e[N],w[N];
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>b[i].u>>b[i].v>>b[i].a;
        int u=b[i].u,v=b[i].v,a=b[i].a;
        e[u].push_back(v);
        w[u].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            dp[i][j]=inf;
        }
    }
    dp[1][0]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i],a=w[x][i];
            for(int j=0;j<k;j++){
                if(dp[x][j]==inf) continue;
                int deng=0;
                if(a-dp[x][j]<=0) deng=0;
                else{
                    if((a-dp[x][j])%k==0){
                        deng=(a-dp[x][j])/k;
                    }else deng=(a-dp[x][j])/k+1;
                }
                int nxt=(j+1)%k;
                dp[y][nxt]=min(dp[y][nxt],deng*k+dp[x][j]+1);
            }
            if(vis[y]<=k){
                q.push(y);
                vis[y]++;
            }
        }
    }
    int ans=dp[n][0];
    if(dp[n][0]==inf) ans=-1;
    cout<<ans;
    return 0;
}
