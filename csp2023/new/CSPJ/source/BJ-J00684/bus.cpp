#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 10005
#define MAXM 1000000005
ll n,m,k,sh=MAXM;
struct L{
    int a,b;
}l[MAXN][MAXN];
bool f[MAXN];
void dfs(ll now,ll lu){
    if(lu>sh){
        return ;
    }
    if(now==n){
        if(lu%k==0 and lu<sh)sh=lu;
        return ;
    }
    for(int i=1;i<=l[now][0].a;i++){
        if(lu<=l[now][i].a or f[l[now][i].b])continue;
        f[l[now][i].b]=1;
        dfs(l[now][i].b,lu+1);
        f[l[now][i].b]=0;
    }
    return ;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,a;
        cin>>u>>v>>a;
        l[u][++l[u][0].a].a=a;
        l[u][l[u][0].a].b=v;
    }
    dfs(1,k);
    if(sh!=MAXM)
        cout<<sh<<endl;
    else
        cout<<-1<<endl;
    return 0;
}