#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define int long long
using namespace std;
int c,t,f[200010],fu[200010];
bool d[200010];
int tp[200010];
char kkk[200010];
vector<int> mp[200010];
int find(int x) {return f[x]==x?f[x]:f[x]=find(f[x]);}
void merge(int x,int y) {
    int fx=find(x),fy=find(y);
    if (fx!=fy) f[fx]=fy;
}
signed main(void) {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    if (c==3||c==4) {
        for (int n,m;t--;) {
            cin >> n >> m;
            for (int i=1;i<=m;i++) {
                char vv;
                cin >> vv;
                cin >> kkk[vv];
            }
            int cnt=0;
            for (int i=1;i<=n;i++) {
                if (kkk[i]=='U') cnt++;
            }
            cout << cnt << endl;
        }
        return 0;
    }
    for (int n,m;t--;) {
        cin >> n >> m;
        for (int i=1;i<=200000;i++) {
            f[i]=i; tp[i]=4; d[i]=false;
            fu[i]=0;
            mp[i].clear();
        }
        for (int i=1;i<=m;i++) {
            char k;
            cin >> k;
            if (k=='U'||k=='T'||k=='F') {
                int u; cin >> u;
                if (k=='U') d[u]=1;
                fu[u]=0;
                fu[u+n]=0;
            } else if (k=='+') {
                int u,v; cin >> u >> v;
                d[u]=d[v];
                fu[u]=v;
                fu[u+n]=v+n;
            } else if (k=='-') {
                int u,v; cin >> u >> v;
                d[u]=!d[v];
                fu[u]=v+n;
                fu[u+n]=v;
            }
        }
        queue<int> que;
        for (int i=1,u,v;i<=2*n;i++) {
            if (fu[i]==0) continue;
            u=i,v=fu[i];
            int ddu,ddv;
            if (u<=n) ddu=u+n;
            else ddu=u-n;
            if (v<=n) ddv=v+n;
            else ddv=v-n;
            if (find(u)==find(ddv)||find(ddu)==find(v)) {
                tp[u]=tp[v]=tp[ddu]=tp[ddv]=2; continue;
            }
            merge(u,v);
            merge(ddu,ddv);
        }
        for (int i=1;i<=2*n;i++) {
            mp[find(i)].push_back(i);
        }
        for (int i=1;i<=2*n;i++) {
            if (d[i]==1) que.push(i);
        }
        while (!que.empty()) {
            int p=que.front();
            que.pop();
            if (p<=n) {
                tp[p+n]=2;
                if (!d[p+n]) que.push(p+n),d[p+n]=1;
            } else {
                tp[p-n]=2;
                if (!d[p-n]) que.push(p-n),d[p-n]=1;
            }
            int ff=find(p);
            for (int i=0;i<mp[ff].size();i++) {
                int dd=mp[ff][i];
                if (!d[dd]) que.push(dd),d[dd]=1,tp[dd]=2;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++) {
            if (d[i]==1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}