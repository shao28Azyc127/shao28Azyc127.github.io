#include<bits/stdc++.h>
using namespace std;
struct edge {
    int v,w;
};
vector <edge> e[10005];
struct situ{
    int u,t;
};
queue<situ> q;
int main() {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    int cnt=0;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d %d %d",&u,&v,&a);
        e[u].push_back({v,a});
    }
    int t=0;
    q.push({1,0});
    while (1) {
        t++;
        if (t%k==0) {
            q.push({1,t});
        }
        while (!q.empty() && q.front().t==t-1) {
            int u=q.front().u;
            q.pop();
            for (edge E:e[u]) {
                cnt++;
                if (cnt>=99e6) {
                    printf("-1");
                    return 0;
                }
                if (E.w<=t) {
                    if (E.v==n && t%k==0) {
                        printf("%d",t);
                        return 0;
                    }
                    q.push({E.v,t});
                }
            }
        }
    }
    printf("-1");
    return 0;
}
