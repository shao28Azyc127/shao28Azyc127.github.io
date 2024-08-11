#include<bits/stdc++.h>
using namespace std;
int n,m,ans,zt[200010],check[20],h[200010],cnt;
bool d[200010];
struct node {
    int x,y;//x<-y 10T 20F 30U      v,next
    int opt;//-1 -> -     1->+       2->value
}edge[200010];
void dfs (int u) {
    if (u==11) {
        int sum=0;
        for (int a=1;a<=n;a++) check[a]=zt[a];
        for (int a=1;a<=m;a++) {
            int x=edge[a].x;
            int y=edge[a].y;
            if (edge[a].opt==-1) {
                if (zt[y]==10) zt[x]=20;
                if (zt[y]==20) zt[x]=10;
                if (zt[y]==30) zt[x]=30;
            }
            if (edge[a].opt==1) zt[x]=zt[y];
            if (edge[a].opt==2) zt[x]=y;
        }
        for (int a=1;a<=n;a++) if (check[a]!=zt[a]) return;
        for (int a=1;a<=n;a++) if (check[a]==30) sum++;
        ans=min(ans,sum);
        return;
    }
    for (int a=10;a<=30;a+=10) {
        zt[u]=a;
        dfs(u+1);
    }
    return;
}
void ae(int a,int v,int u) {
    edge[a].x=v;
    edge[a].y=h[u];
    h[u]=a;
    return;
}
bool bfs(int u) {
    cnt++;
    zt[u]=cnt;
    bool opt=true;
    for (int a=h[u];a;a=edge[a].y) {
        int v=edge[a].x;
        if (zt[v]) {
            if (v&1) {
                if (zt[v+1]) return false;
                return true;
            }
            else {
                if (zt[v-1]) return false;
                return true;
            }
        }
        if (bfs(v)) continue;
        opt=false;
    }
    return opt;
}
int main () {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    int c,T;
    cin >>c>>T;
    while (T--) {
        cin >>n>>m;
        for (int a=1;a<=2*n;a++) {
            zt[a]=0;
            d[a]=false;
        }
        if (c==1 ||c==2) {
            ans=100;
            for (int a=1;a<=m;a++) {
                char f;
                cin >>f;
                if (f=='+') {
                    cin >>edge[a].x>>edge[a].y;
                    edge[a].opt=1;
                }
                else if (f=='-') {
                    cin >>edge[a].x>>edge[a].y;
                    edge[a].opt=-1;
                }
                else {
                    cin >>edge[a].x;
                    edge[a].opt=2;
                    if (f=='T') edge[a].y=10;
                    else if (f=='F') edge[a].y=20;
                    else edge[a].y=30;
                }
            }
            dfs(1);
            cout <<ans<<endl;
        }
        if (c==3 || c==4) {
            ans=0;
            for (int a=1;a<=m;a++) {
                char f;
                int x;
                cin >>f>>x;
                if (f=='U') zt[x]=1;
                else zt[x]=2;
            }
            for (int a=1;a<=n;a++) if (zt[a]==1) ans++;
            cout <<ans<<endl;
        }
        if (c==7 || c==8) {
                ans=0;
            for (int a=1;a<=m;a++) {
                char f;
                cin >>f;
                int x,y;
                cin >>x>>y;
                if (f=='+') {
                    ae(a*2-1,2*x-1,2*y-1);
                    ae(a*2-1,2*x,2*y);
                }
                if (f=='-') {
                    ae(a*2,2*x,2*y-1);
                    ae(a*2,2*x-1,2*y);
                }
            }
            for (int a=1;a<=2*n;a+=2) {
                if (zt[a]) continue;
                if (!bfs(a)) {
                    for (int b=1;b<=2*n;b+=2) {
                        if (zt[a]==cnt) d[b]=true;
                    }
                }
            }
            for (int a=1;a<=2*n;a+=2) if (d[a]) ans++;
            cout <<ans<<endl;
        }
    }
    return 0;
}
