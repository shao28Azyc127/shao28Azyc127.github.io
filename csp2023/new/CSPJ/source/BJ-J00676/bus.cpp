#include<bits/stdc++.h>
using namespace std;
int n,k,m,dp[10007],lmt,sz[10007];
int vis[10007];
struct edg{
    int nxt,a;
};
vector<edg> v[10007];
queue<int> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back({y,z});
        lmt=max(lmt,z);
    }
    lmt+=2*m;
    for(int i=1;i<=n;++i) dp[i]=-1,sz[i]=v[i].size();
    dp[1]=0;
    q.push(1);
    for(int i=1;i<=lmt;++i){
        if(dp[n]%k==0){
            printf("%d",dp[n]);
            return 0;
        }
        int t=q.size();
        for(int j=0;j<t;++j){
            int id=q.front();
            q.pop();
            for(int l=0;l<sz[id];++l){
                if(v[id][l].a<=i&&dp[v[id][l].nxt]<i){
                    dp[v[id][l].nxt]=i;
                    q.push(v[id][l].nxt);
                }
            }
        }
        if(i%k==0&&dp[1]<i){
            dp[1]=i;
            q.push(1);
        }
    }
    printf("-1");
    return 0;
}

