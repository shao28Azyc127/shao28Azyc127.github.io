#include <bits/stdc++.h>
using namespace std;
int vis[100010],dis[100010];
vector <int> vc[100010];
void bfs(){
    queue <int> q;
    q.push(1); vis[1]=1;
    while (!q.empty()){
        int tmp=q.front(); q.pop();
        for (auto x:vc[tmp]){
            if (!vis[x]) {
                q.push(x); vis[x]=1; dis[x]=dis[tmp]+1;
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        vc[a].push_back(b);
        if (c!=0){
            cout<<-1; return 0;
        }
    }
    bfs();
    if (!vis[n]) cout<<"-1";
    else printf("%d",dis[n]);
    return 0;
}