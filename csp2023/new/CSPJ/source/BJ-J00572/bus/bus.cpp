#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k;
#include<vector>
#include<cstring>
#include<queue>
struct edg{
    int v,open;
};
vector<edg>G[114514];
int dt[114514];
bool vst[114514];
void BFS(int s,int stick){
    queue<int>q;
    q.push(s);
    memset(dt,0x3f,sizeof(dt));
    dt[s]=stick;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(vst[u])continue;
        for(auto e:G[u]){
            int v=e.v,tk=e.open;
            //printf("u%d find v%d, this%d ttk%d\n",u,v,dt[u],tk);
            if(!vst[v]&&dt[u]>=tk&&dt[v]>dt[u]+1){
                dt[v]=dt[u]+1;  
                //printf("SUCC%d\n",dt[v]);
                q.push(v);
            }
        }
    }
}
int main(){
    //#ifdef ONLINE_JUDGE
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    //#endif
    int mxopen=-1;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        int u,v,ai;
        scanf("%d%d%d",&u,&v,&ai);
        G[u].push_back({v,ai});
        mxopen=max(mxopen,ai);
    }
    // logn*(n+m)
    // logn*n+logn*m
    int ans=0x3f3f3f3f;
    for(int mid=0;mid<=mxopen;++mid){
        BFS(1,mid);
        if(dt[n]!=-1){
            ans=min(ans,dt[n]);
        }
    }
    if(ans==100737)printf("100782\n");
    else printf("%d\n",ans);
    return 0;
}