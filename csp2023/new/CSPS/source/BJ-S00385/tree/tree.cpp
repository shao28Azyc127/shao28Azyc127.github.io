#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
struct place{
    int a,b,c;
}p[maxn];
struct node{
    int to,nxt;
}edge[maxn*2];
int head[maxn],cnt=-1;
int vis[maxn],t[maxn];
priority_queue<pair<double,int> > q;
void add(int x,int y){
    edge[++cnt].to=y; edge[cnt].nxt=head[x]; head[x]=cnt;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n; cin>>n;
    memset(head,255,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].b>>p[i].c;
    }
    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        add(x,y); add(y,x);
    }
    int last_T=0,k=0;
    q.push(make_pair(ceil(p[1].a/max(p[1].b,1)),1));
    while(!q.empty()){
        int x=q.top().second; q.pop(); k++;
        if(vis[x]) continue; vis[x]=1;
        t[x]=k+ceil(p[x].a/max(p[x].b,1))-1;
        last_T=max(last_T,t[x]);
        for(int i=head[x];i!=-1;i=edge[i].nxt){
            int y=edge[i].to;
            if(vis[y]) continue;
            q.push(make_pair(ceil(p[y].a/max(p[y].b,1)),y));
        }
    }
    cout<<last_T<<endl;
    fclose(stdin); fclose(stdout);
    return 0;
}
