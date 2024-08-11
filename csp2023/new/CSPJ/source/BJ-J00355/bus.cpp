
#include<bits/stdc++.h>
using namespace std;
struct nd{int t,w;};
vector<nd> e[10050];
int dp[10050][120];
int a[10050],dep[10050];
bool vis[10050];
queue<int> q;
void topo(int s){
     q.push(s);
     int len=0;
     a[++len]=s;
     vis[s]=1;
     while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto ed:e[t]){
            dep[ed.t]--;
        if(vis[ed.t]==0) q.push(ed.t),a[++len]=ed.t,vis[ed.t]=1;
        }
     }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v,b;
        scanf("%d%d%d",&u,&v,&b);
        e[u].push_back((nd){v,b});
        dep[v]++;
    }topo(1);
    memset(dp,63,sizeof(dp));
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            for(auto ed:e[a[i]]){
                if(dp[a[i]][j]>1e8) continue;
                int o=0;
                if(j+1==k) o++;
                dp[ed.t][(j+1)%k]=min(dp[ed.t][(j+1)%k],max((ed.w-j+k-1)/k,dp[a[i]][j])+o);
            }
        }
    }if(dp[n][0]>1e8) printf("%d",-1);
    else printf("%d",dp[n][0]*k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
