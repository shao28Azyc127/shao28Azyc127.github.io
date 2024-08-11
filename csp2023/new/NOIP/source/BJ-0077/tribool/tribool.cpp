#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Src{
    int type, a, v;
}vars[maxn];
struct Node{
    int f, v; bool vis;
}no[maxn];
queue<int> known;
struct Edge{
    int v, w, next;
}e[maxn << 1]; int ep = 2;
void connect(int u, int v, int w){
    e[ep] = {v, w, no[u].f};
    no[u].f = ep;
    ep++;
}
int dfs(int a, bool& ok){
    no[a].vis = 1;
    if(no[a].v == 0) ok = 0;
    int sum = 1;
    for(int d=no[a].f;d;d=e[d].next){
        int v = e[d].v;
        if(no[v].vis == 1 && no[v].v != no[a].v * e[d].w){
            ok = 0;
        }else if(no[v].vis == 0){
            no[v].v = no[a].v * e[d].w;
            sum += dfs(v, ok);
        }
    }
    return sum;
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, T;
    cin>>c>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        ep = 2;
        for(int i=1;i<=n;i++){
            vars[i] = {1, i, 0};
            no[i] = {0, 0, 0};
        }
        for(int i=0;i<m;i++){
            char v;
            cin>>v;
            if(v == 'T' || v == 'F' || v == 'U'){
                int i;
                cin>>i;
                vars[i] = {0, 0, v=='T'?1:(v=='F'?-1:0)};
            }else if(v == '+'){
                int i, j;
                cin>>i>>j;
                vars[i] = vars[j];
            }
            else if(v == '-'){
                int i, j;
                cin>>i>>j;
                vars[i] = vars[j];
                vars[i].type *= -1;
                vars[i].v *= -1;
            }
        }
        for(int i=1;i<=n;i++){
            if(vars[i].type == 0) {no[i].v = vars[i].v; known.push(i);}
            else{
                connect(i, vars[i].a, vars[i].type);
                connect(vars[i].a, i, vars[i].type);
            }
        }
        int uk = 0;
        while(!known.empty()){
            int a = known.front();
            known.pop();
            bool ok = 1;
            uk += dfs(a, ok) * (!ok);
        }
        for(int i=1;i<=n;i++){
            if(!no[i].vis){
                no[i].v = 1;
                bool ok = 1;
                uk += dfs(i, ok) * (!ok);
            }
        }
        cout<<uk<<endl;
    }
    return 0;
}
