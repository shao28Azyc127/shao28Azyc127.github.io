//·ğ×æ±£ÓÓ
//·ğ×æ±£ÓÓ
//·ğ×æ±£ÓÓ
//·ğ×æ±£ÓÓ
//·ğ×æ±£ÓÓ
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,x;
vector<int> a[10010];
int rt[10010];
bool b[10010];
void dfs(int step,int node){
    rt[node]=min(rt[node],step);
    if(node==n){
        return;
    }
    for(int i=0;i<a[node].size();i++){
        if(b[a[node][i]]==0){
            b[a[node][i]]=1;
            dfs(step+1,a[node][i]);
            b[a[node][i]]=0;
        }

    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    memset(rt,127,sizeof(rt));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>x;
        a[u].push_back(v);
    }
    dfs(1,1);
    cout<<(int)ceil((rt[n]-1)*1.0/k)*k;
    return 0;
}
