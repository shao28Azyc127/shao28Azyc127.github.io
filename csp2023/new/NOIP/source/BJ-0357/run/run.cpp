#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,x,y,v,maxx=-1,cnt=0;
struct node{
   int ts,nl;
};
vector<node> g[100005];
void dfs(int bs,int nl,int lt,int ddk){
    if(nl+cnt<=maxx)return;
    if(bs==n+1){
        maxx=max(maxx,nl);
        return;
    }
    int nl2=nl;
    if(lt+1<=k){
        lt++;
        for(int i=0;i<g[bs].size();i++){
            ddk-=g[bs][i].nl;
            if(g[bs][i].ts<=lt)nl+=g[bs][i].nl;
        }
        dfs(bs+1,nl-d,lt,ddk);
        lt--;
    }
    dfs(bs+1,nl2,0,ddk);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>v;
            cnt+=v;
            g[x].push_back({y,v});
        }
        dfs(1,0,0,cnt);
        cout<<maxx<<endl;
        maxx=-1;
        for(int i=1;i<=m;i++)g[i].clear();
        cnt=0;
    }
    return 0;
}
