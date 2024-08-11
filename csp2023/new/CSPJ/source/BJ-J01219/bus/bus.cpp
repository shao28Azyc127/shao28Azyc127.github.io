#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,k,a[10005][10005],minn=1e9;
bool b[10005];
void dfs(ll z,ll time){
    if(z==n){
        if(time%k==0) minn=min(minn,time);
        return ;
    }
    b[z]=true;
    for(int i=1;i<=n;i++){
        if(a[z][i]==1&&!b[i]){
            dfs(i,time+1);
        }
    }
    b[z]=false;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,b;
        cin>>u>>v>>b;
        a[u][v]=1;
    }
    dfs(1,0);
    if(minn==1e9) cout<<-1;
    else cout<<minn;
    return 0;
}
