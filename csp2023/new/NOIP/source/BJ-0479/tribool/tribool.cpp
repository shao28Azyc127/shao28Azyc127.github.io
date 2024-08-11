#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N=1e5+7;
int n,m;
struct edge{
    int to,w;
};
vector<edge> v[N];
vector<int> e[N];
queue<int> q;
int du[N];
bool vis[N],f[N],isu;
int cml[N];
void dfs(int x, int s)
{
//    cout<<x<<" "<<s<<endl;
    if(vis[x])
    {
        if(s%2!=0) isu=true;
        return;
    }
    vis[x]=true;
    q.push(x);
//    bool flag=false;
    for(int i=0; i<v[x].size(); i++)
    {
        int y=v[x][i].to;
        dfs(y,s+v[x][i].w);
    }
//    if(!flag && s%2!=0) isu=true;
}
int solve(int x)
{
    if(cml[x]!=-1) return cml[x];
    cml[x]=f[x];
    if(cml[x]==1) return cml[x];
    for(int i=0; i<v[x].size(); i++)
        cml[x]=solve(v[x][i].to);
    return cml[x];
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int p,T;
    cin>>p>>T;
    while(T--)
    {
        memset(cml,-1,sizeof(cml));
        memset(f,false,sizeof(f));
        memset(vis,false,sizeof(vis));
        memset(du,0,sizeof(du));
        for(int i=1; i<=n; i++)
            v[i].clear();
        cin>>n>>m;
        for(int i=1; i<=m; i++)
        {
            char c;
            cin>>c;
            if(c=='-' || c=='+')
            {
                int x,y;
                cin>>x>>y;
                f[x]=f[y];
                if(c=='-') v[x].push_back((edge){y,1});
                else v[x].push_back((edge){y,0});
                du[y]++;
            }
            else
            {
                int x;
                cin>>x;
                if(c=='U') f[x]=true;
                else f[x]=false;
            }
        }
//        for(int i=1; i<=n; i++)
//            cout<<du[i]<<" ";
//        cout<<endl;
        for(int i=1; i<=n; i++)
            if(du[i]==0) q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            vis[x]=true;
            q.pop();
            for(int i=0; i<v[x].size(); i++)
            {
                du[v[x][i].to]--;
                if(du[v[x][i].to]==0) q.push(v[x][i].to);
            }
        }
        for(int i=1; i<=n; i++)
        {
            isu=false;
            if(!vis[i]) dfs(i,0);
            while(!q.empty())
            {
                f[q.front()]=isu;
                if(isu) cml[q.front()]=isu;
                q.pop();
            }
        }
        for(int i=1; i<=n; i++)
            cml[i]=solve(i);
        int ans=0;
        for(int i=1; i<=n; i++) ans+=cml[i];
        cout<<ans<<endl;
    }
    return 0;
}
