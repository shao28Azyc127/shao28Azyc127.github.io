#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,a[10001][10001],b[1000001],cnt,s,t,ti;
bool c[10001][10001],v[10001];
int dfs(int tim,int x){
    if(tim%k==0&&x==n)return tim;
    if(x==n)return 2e9;
    v[x]=1;
    int ans=1e9;
    for(int i=1;i<=m;i++){
        if(c[x][i]&&!v[i]&&tim>=a[x][i])ans=min(dfs(tim+1,i),ans);
    }
    v[x]=0;
    return ans;
}
int bin(){
    int l=1,r=cnt,ans=1e9;
    while(l<r){
        int mid=l+r>>1;
        int sum=dfs(b[mid],1);
        if(sum!=2e9){
            ans=min(ans,sum);
            r=mid-1;
        }else l=mid+1;
    }
    return ans==1e9?-1:ans;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&s,&t,&ti);
        a[s][t]=ti;
        c[s][t]=1;
    }
    for(i=0;i<=1000000;i+=k)b[++cnt]=i;
    printf("%d",bin());
    return 0;
}
