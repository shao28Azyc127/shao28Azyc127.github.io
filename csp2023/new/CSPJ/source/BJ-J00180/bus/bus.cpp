#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn=0x7fffffff;
int f;
struct E{
int id,val;
};
int vis[10010];
vector<E>v[10010];
void dfs(int x,int deep,int j){
    if(deep>minn)return;
    if(x==n){
        if(deep%k==0)minn=min(minn,deep),f=1;
        return;
    }
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]==0){
            vis[v[x][i].id]=1;
            dfs(v[x][i].id,deep+max(0,v[x][i].val-deep-j)+1,j);
            vis[v[x][i].id]=0;
        }
    }
}
int main(){
freopen("bus.in","r",stdin);
freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back({y,z});
    }
    vis[1]=1;
    for(int i=0;i<minn;i+=k)dfs(1,i,i);
    if(f==1)printf("%d",minn);
    else printf("-1");
    return 0;
}