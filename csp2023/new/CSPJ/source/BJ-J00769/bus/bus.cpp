#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
struct node{
    int p,s;
}e;
vector<int>G[10010];
queue<node>q;
bool vis[10010];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,a;
        scanf("%d%d%d",&x,&y,&a);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    e.s=0;e.p=1;
    q.push(e);
    vis[1]=1;
    while(!q.empty()){
        node t=q.front();
        bool flag=0;
        for(int i=0;i<G[t.p].size();i++){
            if(vis[G[t.p][i]])continue;
            if(G[t.p][i]==n){
                flag=1;
                cout<<t.s+1;
                break;
            }
            node tt;
            tt.p=G[t.p][i];
            tt.s=t.s+1;
            q.push(tt);
            vis[G[t.p][i]]=1;
        }
        if(flag)break;
        q.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
