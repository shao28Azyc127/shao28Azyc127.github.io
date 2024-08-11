#include<bits/stdc++.h>
int n,m,k,xi,yi,mp[10005][10005],ans=2000000000;
using namespace std;
void dfs(int p,int t,int l){
    if(p==n&&l%k==0){
        ans=min(ans,((t-1)/k+1)*k);
    }
    else{
        for(int i = 1;i<=n;i++){
            if(mp[p][i]!=-1){
                int a=mp[p][i];
                mp[p][i]=-1;
                dfs(i,max(t+1,a+1),l+1);
                mp[p][i]=a;
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(mp,-1,sizeof(mp));
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        cin>>xi>>yi;
        cin>>mp[xi][yi];
    }
    dfs(1,0,0);
    if(ans!=2000000000)   cout<<ans;
    else   cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}