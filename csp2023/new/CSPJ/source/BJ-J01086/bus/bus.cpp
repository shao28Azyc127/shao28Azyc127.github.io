#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
vector<int> g1[10005];
vector<int> g2[10005];
void dfs(int x,int cnt){
 //   cout<<x<<" "<<cnt<<endl;
    if(cnt>ans) return;
    if(x==n){
        if(cnt==ans){
            cout<<ans<<endl;
            exit(0);
        }
        return;
    }
    for(int i=0;i<(int)g1[x].size();i++){
        if(cnt>=g2[x][i]) dfs(g1[x][i],cnt+1);
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        ans=max(ans,a);
        g1[u].push_back(v);
        g2[u].push_back(a);
    }
    int tmp=ans+n*n;
    ans=(ans%k==0?int(ans/k)*k:int(ans/k)*k+k);
    while(ans<=tmp){
        for(int i=0;i<=ans;i+=k) dfs(1,i);
        ans+=k;
    }
    cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
