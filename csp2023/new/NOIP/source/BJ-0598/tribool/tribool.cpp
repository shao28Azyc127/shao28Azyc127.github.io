#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int c,t,n,m,x,y,cnt,a[N],vis[N];
char opt;
queue<int> q;
vector<int> g[N];
struct node{
    int id,tp,ch,s;
}to[N];
int too[N],ss[N],nt;
void solve(){
    cin>>n>>m;
    for(int i = 0;i<=100000;i++){
        ss[i]=0,a[i]=-1,too[i]=0,vis[i]=0;
        g[i].clear();
    }
    for(int i = 1;i<=m;i++){
        cin>>opt>>x;
        if(opt=='+'){
            cin>>y;
            if(ss[y]==0){
                too[x]=y;
                ss[x]=1;
            }
            else if(ss[y]==1) too[x]=too[y],ss[x]=1;
            else ss[x]=2,a[x]=a[y];
        }
        else if(opt=='U'){ a[x]=2,ss[x]=2;}
        else if(opt=='F') a[x]=0,ss[x]=2;
        else a[x]=1,ss[x]=2;
     //   if(a[x]==2) cout<<i<<endl;
    }
    for(int i = 1;i<=n;i++){
        if(ss[i]==1){
            g[too[i]].push_back(i);
        }
    }
    if(c==3||c==4){
        cnt=0;
        for(int i = 1;i<=n;i++){
            if(a[i]==2) cnt++;
        }
        cout<<cnt<<endl;
        return ;
    }
    if(c==5||c==6){
        cnt=0;
        while(!q.empty()) q.pop();
        for(int i = 1;i<=n;i++){
            if(a[i]==2&&ss[i]==2) q.push(i),nt++;
        }
        while(!q.empty()){
            x=q.front();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            cnt++;
            for(int i = 0;i<g[x].size();i++){
                y=g[x][i];
                if(vis[y]) continue;
                q.push(y);
            }
        }
        cout<<cnt<<endl;
        return ;
    }
}
int main(){
   freopen("tribool.in","r",stdin);
   freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }
    return 0;
}
