#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+5;
struct Node{
    int a, b, c, f, t, d=0x3f3f3f3f3f3f3f3f, p, fa, vis;
}no[maxn];
struct Edge{
    int v, next;
}e[maxn << 1]; int ep = 2;
void connect(int a, int b){
    e[ep] = {b, no[a].f};
    no[a].f = ep;
    ep++;
}
void dfs(int a, int f){
    no[a].fa = f;
    if(no[f].d + 1 < no[a].d){
        no[a].d = no[f].d + 1;
    no[a].d = min(no[a].d, no[f].d + 1);
    no[a].p = no[a].t + no[a].d;
    for(int d=no[a].f;d;d=e[d].next){
        if(e[d].v == f) continue;
        dfs(e[d].v, a);
    }
    }
}
pair<int, int> forest[maxn];
stack<int> st;
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>no[i].a>>no[i].b>>no[i].c;
        no[i].t = (no[i].a - 1) / no[i].b + 1;
    }
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        connect(a, b);
        connect(b, a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        forest[i] = make_pair(no[i].p, i);
    }
    int day = 0, ans = 0;
    for(int ii=n;ii>=1;ii--){
        int i = 0;
        for(int j=1;j<=n;j++){
            if(!no[j].vis && no[j].t >= no[i].t) i = j;
        }
        int now = forest[i].second;
        while(now != 0){
            st.push(now);
            now = no[now].fa;
        }
        while(!st.empty()){
            int a = st.top();
            st.pop();
            if(!no[a].vis){
                no[a].vis = 1;
                no[a].d = 1;
                ans = max(ans, day + no[a].t);
                day++;
            }
        }
        dfs(1, 0);
    }
    cout<<ans<<endl;
    return 0;
}
