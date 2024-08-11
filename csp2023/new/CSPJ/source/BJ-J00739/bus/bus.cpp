#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e4 + 10,M = 2e4 + 10;
int n,m,k;
int h[N],e[M],ne[M],w[M],idx;
void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}
int ans = 1e9;
void dfs(int u,int dis){
    if(u == n){
        if(dis % k == 0){
            ans = min(ans,dis);
        }
        return ;
    }
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        dfs(j,dis + 1);
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(h,-1,sizeof(h));
    scanf("%d %d %d",&n,&m,&k);
    while(m -- ){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    dfs(1,0);
    printf("%d",ans + k);
    return 0;
}
