#include<bits/stdc++.h>
using namespace std;
const long long maxn=20005;

long long n, m, k;

vector<pair<long long, long long> >vec[maxn];

struct node{
    long long x, step, mx;
};

queue<node> Q;
bool vis[maxn][105];
long long dis[maxn][105];

long long ans=1e9;

void bfs() {

    Q.push((node){1, 0, 0});

    while(!Q.empty()) {
        long long u=Q.front().x;
        long long step=Q.front().step;
        long long mx=Q.front().mx;
        Q.pop();

        long long s=(step%k)+1;

        if(vis[u][s]==0) vis[u][s]=1, dis[u][s]=step;
        else {
            continue;
        }



       // cout<<u<<" "<<step<<" "<<mx<<endl;

        if(u==n && s==1) {
            long long p=mx/k;
            ans=min(ans, step+p*k);
            return;
        }

        for(long long i=0; i<vec[u].size(); i++) {
            long long v=vec[u][i].first;
            long long ux=vec[u][i].second;
            long long x;
            x=max(mx, ux-step+1);
            Q.push((node){v, step+1, x});
        }
    }

    return;
}

int main() {

    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    scanf("%lld %lld %lld", &n, &m, &k);

    for(long long i=1, u, v, w; i<=m; i++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        vec[u].push_back(make_pair(v, w));
    }

    bfs();

    if(ans==1e9) printf("NO");
    else printf("%lld", ans);

    return 0;
}
