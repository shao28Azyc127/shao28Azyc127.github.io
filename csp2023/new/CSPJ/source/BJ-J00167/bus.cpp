#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
vector<int> edge[10005];
int bian_can[20005];
int vis[10005],dp[10005][105];
queue<int> q;
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1; i <= m; i++){
        int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        edge[u].push_back(v);
        bian_can[i] = w;
    }
    bool ai_0 = 1;
    for(int i = 1; i <= m; i++) if(bian_can[i]) ai_0 = 0;
    if(ai_0){
        memset(dp,0x7f,sizeof(dp));
        dp[1][0] = 0;
        q.push(1);
        while(q.size()){
            int nowx = q.front(); q.pop();
            if(vis[nowx] >= k) continue;
            vis[nowx]++;
            for(int i = 0; i < edge[nowx].size(); i++){
                for(int j = 0; j < k; j++){
                    if(dp[edge[nowx][i]][(j+1)%k] > dp[nowx][j] + 1){
                         q.push(edge[nowx][i]);
                         dp[edge[nowx][i]][(j+1)%k] = 1 + dp[nowx][j];
                    }
                }
            }
        }
        if(dp[n][0] == 0x7f7f7f7f7f7f7f7f) printf("-1\n");
        else printf("%lld\n",dp[n][0]);
    }else{
        int maxn = -1;
        for(int i = 1; i <= m; i++) maxn = max(maxn,bian_can[i]);
        maxn = (int)ceil((double)maxn / (double)k) * k;
        memset(dp,0x7f,sizeof(dp));
        dp[1][0] = 0;
        q.push(1);
        while(q.size()){
            int nowx = q.front(); q.pop();
            if(vis[nowx] >= k) continue;
            vis[nowx]++;
            for(int i = 0; i < edge[nowx].size(); i++){
                for(int j = 0; j < k; j++){
                    if(dp[edge[nowx][i]][(j+1)%k] > dp[nowx][j] + 1){
                         q.push(edge[nowx][i]);
                         dp[edge[nowx][i]][(j+1)%k] = 1 + dp[nowx][j];
                    }
                }
            }
        }
        if(dp[n][0] == 0x7f7f7f7f7f7f7f7f) printf("-1\n");
        else printf("%lld\n",dp[n][0] + maxn);
    }
    return 0;
}
