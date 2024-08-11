#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    long long x,a;
};

long long n,m,k,ans=1e18;
vector<node> v[10010];
bool b[10010];

void dfs(long long id,long long c){
    if(id==n){
        while(c%k!=0){
            c++;
        }
        ans=min(ans,c+k);
        return ;
    }
    for(long long i=0;i<v[id].size();i++){
        if(b[v[id][i].x]==0){
            b[v[id][i].x]=1;
            dfs(v[id][i].x,max(c,v[id][i].a));
            b[v[id][i].x]=0;
        }
    }
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++){
        long long u,s,a;
        cin>>u>>s>>a;
        v[u].push_back(node{s,a});
    }
    dfs(1,0);
    if(ans==1e18){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}
