#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,a,l[1005][1005],ans=10000000000;
void dfs(ll now,ll time){
    if(now==n&&time%k==0){
        ans=min(ans,time);
        return;
    }
    for(int i=1;i<=n;i++){
        if(l[now][i]!=-1&&time>=l[now][i]){
            dfs(i,time+1);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            l[i][j]=-1;
        }
    }
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a;
        l[u][v]=a;
    }
    if(k>1){
        for(int i=1;i<=500;i++){
            dfs(1,i*k);
        }
        if(ans!=10000000000){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }else{
        dfs(1,0);
        if(ans!=10000000000){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}



