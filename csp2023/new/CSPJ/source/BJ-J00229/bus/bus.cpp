#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
long long ans=1000000000000001;
vector<int> v[10001],a[10001];
void dfs(long long t,int node){
    if(node==n&&t%k==0){
        ans=min(ans,t);
        return ;
    }
    else if(node==n) return ;
    if(t>=ans) return;
    for(int i=0;i<v[node].size();i++){
        if((long long)(a[node][i])<=t) dfs(t+1,v[node][i]);
    }
    return ;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int s,e,t;
        scanf("%d%d%d",&s,&e,&t);
        v[s].push_back(e);
        a[s].push_back(t);
    }
    dfs(k,1);
    if(ans!=1000000000000001) printf("%lld",ans);
    else printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}