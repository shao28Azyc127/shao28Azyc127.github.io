#include<bits/stdc++.h>
struct node{
    int data,t;
};
using namespace std;
int a[1005][1005];
int n,m,k;
int bfs(int t){
    int time=t;
    node first;
    first.data=1;
    first.t=time;
    queue<node> q;
    q.push(first);
    while(!q.empty()){
        node f=q.front();
        q.pop();
        time=max(time,f.t);
        for(int i=1;i<=n;i++){
            if(f.t>a[f.data][i] && a[f.data][i]!=-1){
                node newdata;
                newdata.data=i;
                newdata.t=f.t+1;
                q.push(newdata);
            }
        }

    }
    return time;
}
int main(){
		freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int u,v,p,ans=1e9+5,cnt=-1e9-5;
    memset(a,-1,sizeof(a));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>p;
        a[u][v]=p;
        cnt=max(cnt,p);
    }
    for(int i=k;i<=cnt+1000;i+=k){
        ans=min(bfs(i),ans);
    }
    if(ans==1e9+5){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
