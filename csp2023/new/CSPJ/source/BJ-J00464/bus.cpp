#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[20005],v[20005],a[20005],mp[10005][10005],kf[10005][10005];
int ans=INT_MAX;
void dfs(int st,int tm){
    if(st==n){
        if(tm<ans&&tm%k==0){
            ans=tm;
            return ;
        }
    }
    for(int i=1;i<=n;i++){
        if(mp[st][i]!=0&&kf[st][i]<=tm){
            dfs(i,tm+1);
        }else if(mp[st][i]!=0&&kf[st][i]>tm){
            if((kf[st][i]-tm)%k==0){
                dfs(i,tm+1+(kf[st][i]-tm));
            }else{
                dfs(i,tm+1+((kf[st][i]-tm)/k+1)*k);
            }
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        mp[u[i]][v[i]]=1;
        kf[u[i]][v[i]]=a[i];
    }
    dfs(1,0);
    if(ans==INT_MAX){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
