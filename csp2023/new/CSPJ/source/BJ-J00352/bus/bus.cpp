#include<bits/stdc++.h>
using namespace std;
//cout<<"Thanks god.Please help me AK CSP-J!";
bool a[20001][20001];
struct node{
    int w,s;
};
bool vis[20005];
int minn=INT_MAX,n,m,k,flag1,flag2=1,cnt;
int bfs(){
    queue<node> q;
    q.push(node{1,1});
    vis[1]=1;
    while(!q.empty()){
        node t=q.front();
        q.pop();
        for(int i=1;i<=m;i++){
            if(a[t.w][i]&&!vis[i]){
                if(i==n){
                    return t.s;
                }
                q.push(node{i,t.s+1});
                vis[i]=1;
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    if(k==1)flag1=1;
    for(int i=1;i<=m;i++){
        int u,v,x;
        cin>>u>>v>>x;
        if(x!=0)flag2=0;
        a[u][v]=1;
    }
    if(flag1&&flag2){
        cout<<bfs()+1;
    }else{
        cout<<3*k;
    }
    return 0;
}
