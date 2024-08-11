#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[10005],c[10005];
int dp[10005][105];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++){
        int x,y,t; scanf("%d%d%d",&x,&y,&t);
        v[x].push_back(y); c[x].push_back(t);
    }
    queue<int> qx,qdis;
    qx.push(1); qdis.push(0);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0] = 0;
    while(!qx.empty()){
        int x = qx.front(); qx.pop();
        int dis = qdis.front(); qdis.pop();
        for(int i = 0;i < v[x].size();i++){
            int now = v[x][i],ans = dp[x][dis] + 1;
            if(dp[x][dis] < c[x][i]){
                if((c[x][i] - dp[x][dis]) % k == 0) ans = c[x][i] + 1;
                else ans = dp[x][dis] + ((c[x][i] - dp[x][dis]) / k + 1) * k + 1;
            }
            if(ans < dp[now][(dis + 1) % k]){
                dp[now][(dis + 1) % k] = ans;
                qx.push(now); qdis.push((dis + 1) % k);
            }
        }
    }
    if(dp[n][0] == 0x3f3f3f3f) printf("-1");
    else printf("%d",dp[n][0]);
    return 0;
}