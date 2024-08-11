#include<bits/stdc++.h>
#define MaxN 100010
using namespace std;
struct Edge{
    int next,to,from;
    bool opt;
}edge[MaxN],e[MaxN<<1];
int c,t,m,n;
int low[MaxN],dfn[MaxN],tim,stac[MaxN],top,head[MaxN],tot,ans,cnt,h[MaxN],siz[MaxN],sd[MaxN],copt[MaxN];
bool num[MaxN],visit[MaxN];
bool vis[MaxN];
inline void addE(int a,int b){
    e[++cnt].next = h[a];
    e[cnt].from = a;
    e[cnt].to = b;
    h[a] = cnt;
    return;
}
inline void addEdge(int a,int b,bool opt){
    edge[++tot].next = head[a];
    edge[tot].from = a;
    edge[tot].to = b;
    edge[tot].opt = opt;
    head[a] = tot;
    return;
}
void tarjan(int x){
    low[x] = dfn[x] = ++tim;
    stac[top++] = x;
    siz[x] = 1;
    vis[x] = true;
    for(int i = head[x];i;i=edge[i].next){
        int v = edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x] = min(low[v],low[x]);
        }else if(vis[v]){
            low[x] = min(low[v],low[x]);
        }
    }
    if(dfn[x]==low[x]){
        int y;
        while(y=stac[--top]){
            sd[y] = x;
            if(num[y]){
                num[x] = true;
            }
            vis[y] = false;
            if(x==y) break;
            siz[x] += siz[y];
        }
    }
    return;
}
void dfs(int x,int fa){
    visit[x] = true;
    for(int i = h[x];i;i=e[i].next){
        int v = e[i].to;
        if(visit[v]) continue;
        if(v==fa) continue;
        dfs(v,x);
    }
}
void init(){
    memset(copt,0,sizeof(copt));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    top = 0,tim = 0,tot = 0,cnt= 0,ans = 0;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    memset(e,0,sizeof(e));
    memset(h,0,sizeof(h));
    memset(siz,0,sizeof(siz));
    memset(visit,0,sizeof(visit));
    memset(sd,0,sizeof(sd));
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    while(t--){
        init();

        cin >> n >> m;
        for(int i = 1;i<=n;i++){
            sd[i] = i;
        }
        for(int i = 0;i<m;i++){
            char opt;
            cin >> opt;
            if(opt=='-'){
                int a,b;
                cin >> a >> b;
                addEdge(b,a,0);
                num[a] = num[b];
            }else if(opt=='+'){
                int a,b;
                cin >> a >> b;
                num[a] = num[b];
                addEdge(b,a,1);
            }else{
                int a;
                cin >> a;
                if(opt=='U'){
                    num[a] = true;
                }else{
                    num[a] = false;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        for(int i = 1;i<=tot;i++){
            int x = sd[edge[i].from];
            int y = sd[edge[i].to];
            if(x!=y){
                //cout << x <<"--->" << y << endl;
                addE(x,y);
                addE(y,x);
            }else{
                if(edge[i].opt==0){
                    copt[x]++;
                }
            }
        }
        for(int i =1;i<=n;i++){
            if(i!=sd[i]) continue;
            if(copt[i]%2==1){
                num[i] = true;
            }
        }
        for(int i = 1;i<=n;i++){
            if(num[sd[i]]==true) dfs(sd[i],0);
        }
        for(int i = 1;i<=n;i++){
            if(visit[i]) ans += siz[i];
        }
        cout << ans << endl;
    }
    return 0;
}
