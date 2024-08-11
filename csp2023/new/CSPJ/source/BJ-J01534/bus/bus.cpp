#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> a[100000];
int n,m,k,w[1000000];
int visited[100000];
void bfs(long long x){
    visited[x]=1;
    for(int i=1;i<=a[x].size();i++){
        int s=a[x][i];
        if(!visited[s]){
            w[s]=max(w[x]+1,w[s]);
            bfs(s);
        }
    }
    visited[x]=0;
}
int main()
{
  //  freopen("bus.in","r",stdin);
  // freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,s;
        cin>>u>>v>>s;
        a[u].push_back(v);
    }
    w[1]=1;
    bfs(1);
    k=0;
    for(int i=1;i<=n;i++){
        k=max(k,w[i]);
    }
    cout<<k;
    return 0;
}
