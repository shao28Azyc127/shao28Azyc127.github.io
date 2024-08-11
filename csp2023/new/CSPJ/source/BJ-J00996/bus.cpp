#include<bits/stdc++.h>
using namespace std;
vector<int> e[10001];
int dis[10001],q[200001],cnt[100001],l=0;
int n,m,k;
void bfs(){
    q[1]=1;
    int f=1,r=1;
    for(int i=1;i<=10000;i++){
        dis[i]=1e9;
    }
    dis[1]=0;
    while(f<=r){
        int x=q[f++];
        for(auto y:e[x]){
            if(dis[y]>dis[x]+1||y==n){
                dis[y]=dis[x]+1;
                cnt[++l]=dis[y];
                q[++r]=y;
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        e[u].push_back(v);
    }
    bfs();
    int ans=1e9;
    for(int i=1;i<=n-1;i++){
        if(cnt[i]%k==0){
            ans=min(ans,cnt[i]);
        }
    }
    if(ans==1e9){ans=-1;}

    printf("%d",ans);

}
