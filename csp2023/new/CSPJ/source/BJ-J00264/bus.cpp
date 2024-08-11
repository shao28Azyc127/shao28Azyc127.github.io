#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;

int n,m,k;

int ans=2e9+5;

struct Node{
    int v,t;
};

vector<Node> G[N];

void dfs(int u,int fa,int timetot,int add) {
    if(u==n) {
        if(timetot%k==0) {
            ans=min(ans,timetot+(add+2)/3*3);
        }
        return ;
    }
    for(int i=0;i<G[u].size();i++) {
        Node cur=G[u][i];
        int v=cur.v,t=cur.t;
        if(v==fa) continue;
        if(timetot<t) dfs(v,u,timetot+1,max(add,t-timetot));
        else dfs(v,u,timetot+1,add);
    }
}

int main() {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        G[u].push_back({v,t});
        //maxminus=max(maxminus,(t[i]+k-1)/k);
    }
    //for(int i=1;i<=m;i++) t[i]-=maxminus*k;
    dfs(1,0,0,0);
    if(ans==2e9+5) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}
//meow