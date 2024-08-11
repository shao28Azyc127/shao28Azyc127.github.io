#include<bits/stdc++.h>
using namespace std;

const int maxn=2e4+10;
struct edge{
    int to;
    int lim;
};

vector<edge> G[maxn];
int dp[maxn][110];
int n,m,k;

struct node{
    int u;
    int d;
    bool operator <(const node &cmp) const{
        return d>cmp.d;
    }
};

void solve(int start_time){
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++) dp[i][j]=1e9+7;
    }

    dp[1][0]=start_time;
    priority_queue<node> q;
    while (!q.empty()) q.pop();
    q.push((node){1,start_time});

    while (!q.empty()){
        node f=q.top(); q.pop();
        if (f.d>dp[f.u][f.d%k]) continue;
        int u=f.u,op=f.d%k;

        for (int i=0;i<(int)G[u].size();i++){
            int v=G[u][i].to;
            if (dp[u][op]+1<G[u][i].lim) continue;
            if (dp[v][(op+1)%k]>dp[u][op]+1){
                dp[v][(op+1)%k]=dp[u][op]+1;
                q.push((node){v,dp[v][(op+1)%k]});
            }
        }
    }
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);

    int tot=0;
    for (int i=1;i<=m;i++){
        int u,v,lim;
        scanf("%d%d%d",&u,&v,&lim);
        G[u].push_back((edge){v,lim});
        tot=max(tot,lim);
    }

    int l=0,r=tot/k;
    int ans=-1;
    while (l<=r){
        int mid=(l+r)/2;
        solve(mid*k);
        if (dp[n][0]!=1e9+7){
            ans=dp[n][0];
            r=mid-1;
        }else l=mid+1;
    }

    printf("%d\n",ans);
    return 0;
}