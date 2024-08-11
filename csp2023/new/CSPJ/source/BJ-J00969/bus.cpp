#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
long long n,m,k,a[N],ans=LONG_MAX;
bool p[N][N];
void dfs(long long now,long long time,long long start){
    if(now==n){
        if((time+start)%k==0) ans=time+start;
        return ;
    }
    for(long long i=2;i<=n;i++){
        if(p[now][i]&&start+time>=a[i]){
            if(time>=ans) return;
            if(i==n&&(time+start+1)%k!=0) return ;
            if(time+1>=ans) return ;
            dfs(i,++time,start);
            time--;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    long long time=0;
    for(long long i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>a[i];
        p[u][v]=true;
        time=max(time,a[i]);
    }
    for(long long i=0;i<=time;i++){
        if(i%k==0) dfs(1,0,i);
    }
    if(ans==LONG_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}
