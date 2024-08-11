#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005],v[10005],u[10005];
int ans=10000005;
int sz(double x){
    double t=int(x);
    if((x-t)!=0){
        return int(x+1);
    }else{
        return int(x);
    }
}
void dfs(int x,int num){
    if(x>=n){
        ans=min(num,ans);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(a[x][i]>=0&&a[x][i]<=num){
            dfs(i,num+1);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int minn=1000005;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        int t;
        cin>>v[i]>>u[i]>>t;
        a[v[i]][u[i]]=t;
        minn=min(minn,t);
    }
    minn=minn-(minn%k);
    for(int i=1;i<=m;i++){
        a[v[i]][u[i]]-=minn;
    }
    dfs(1,0);
    if(minn==0){
        minn+=k;
    }
    cout<<sz(double(ans+minn)/k)*k<<endl;
    return 0;
}
