#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,z,it;
}a[20005];
int n,m,ans[10005][3],t[10005],k[10005],u,it;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&u);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].z);
    }
    for(int i=1;i<=m;i++){
        a[i].it=k[a[i].u];
        k[a[i].u]=i;
    }
    for(int i=1;i<=n+1;i++){
        ans[i][1]=1e9;
    }
    ans[1][1]=0;
    for(int i=1;i<=n;i++){
        u=n+1;
        for(int j=1;j<=n;j++){
            if(!t[j]){
                u=ans[j]<ans[u]?j:u;
            }
        }
        t[u]=1;
        it=k[u];
        while(it!=0){
            ans[a[it].v][1]=min(ans[a[it].v][1],ans[u][1]+1);
            it=a[it].it;
        }
    }
    printf("%d",ans[n][1]);
    return 0;
}
