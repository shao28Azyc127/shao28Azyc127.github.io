#include<bits/stdc++.h>
#define maxn 20001
using namespace std;
int head[maxn];
struct node{
    int nxt,to,t;
}a[maxn];
struct pe{
    int now,t;
}b[100001];
int cnt;
void add(int u,int v,int t){
    a[++cnt].to=v;
    a[cnt].nxt=head[u];
    head[u]=cnt;
    a[cnt].t=t;
}
int n,m,k;
queue<pe> q;
void bfs(int s){
    q.push((pe){s,k});
    while(!q.empty()){
        pe o=q.front();
        if(o.now==n&&o.t%k==0){
            cout<<o.t<<endl;
            exit(0);
        }
        q.pop();
        for(int i=head[o.now];i;i=a[i].nxt){
            int p=a[i].to;
            if(o.t>=a[i].t){
                q.push((pe){p,o.t+1});
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        add(u,v,t);
    }
    bfs(1);
    cout<<"-1"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
