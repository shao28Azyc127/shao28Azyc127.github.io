#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,b[N],c[N],ans = 2e9;
bool vis[N];
long long a[N],h[N];
vector<int> e[N];
void dfs(int x,int day,int sh,int cnt){
    vis[x] = 1,cnt = 0;
    int l[N]; memset(l,0,sizeof(l));
    for(int i = 1;i <= n;i++)
        if(vis[i] && h[i] < a[i]){
            h[i] += max(b[i] + 1ll * day * c[i],1ll);
            if(h[i] < a[i]) cnt++; l[i] = 1;
        }
    //printf("%d %d %lld %lld %lld %lld %d\n",day,x,h[1],h[2],h[3],h[4],cnt);
    if(sh == 0){
        int k[N]; memcpy(k,h,sizeof(k));
        while(cnt){
            day++; cnt = 0;
            for(int i = 1;i <= n;i++)
                if(h[i] < a[i]){
                    h[i] += max(b[i] + 1ll * day * c[i],1ll);
                    if(h[i] < a[i]) cnt++;
                }
        }
        ans = min(ans,day);
        for(int i = 1;i <= n;i++) h[i] = k[i];
        return;
    }
    bool y[N]; memset(y,0,sizeof(y));
    for(int u = 1;u <= n;u++){
        if(!vis[u]) continue;
        //if(day == 2) cout << u << ' ';
        for(int v : e[u]){
            //if(day == 3) cout << u << " " << v << ' ';
            if(vis[v] || y[v]) continue;
            y[v] = 1;
            //if(day == 1 && v == 3) cout << "yes" << ' ';
            dfs(v,day + 1,sh - 1,cnt);
        }
    }
    for(int i = 1;i <= n;i++)
        if(l[i]) h[i] -= max(b[i] + 1ll * day * c[i],1ll);
    vis[x] = 0;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i = 1;i < n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,1,n - 1,n);
    printf("%d\n",ans);
    return 0;
}
/*
4
12 1 1
2 4 -1
10 3 0
7 10 -2
1 2
1 3
3 4
*/