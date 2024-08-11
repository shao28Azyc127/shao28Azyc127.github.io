#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
struct node{
    int to,l;
};
int ans=INT_MAX;
bool f[N];
vector<node> v[N];
void dfs(int x,int y,int z){
    if(z+y>=ans)return;
    if(x==n){
        if(y%k)return;
        if(z%k)z=z+k-(z%k);
        ans=min(ans,z+y);
    }
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i].to,p=v[x][i].l-y;
        f[to]=1;
        dfs(to,y+1,max(p,z));
        f[to]=0;
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    dfs(1,0,0);
    if(ans<INT_MAX)cout<<ans;
    else cout<<-1;
    return 0;
}
