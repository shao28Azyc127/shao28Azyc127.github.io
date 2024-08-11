#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int maxn=3e5+10;
int n,m;
struct node
{
    char op;
    int x,y;
}a[maxn];
struct Val
{
    bool flag=0;
    int val,from;
}ans[maxn];
int cnt[maxn],top[maxn],id[maxn],tot=n,fir[maxn];
pii from[maxn];
bool vis[maxn];
vector<pii> edge[maxn];
int root[maxn],dis[maxn];
void init()
{
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) top[i]=i,id[i]=i,ans[i]={0,0,i},fir[i]=0;
    tot=n;
    memset(vis,0,sizeof(vis));
}
int getval(char x)
{
    if(x=='F') return 0;
    if(x=='T') return 1;
    return -1;
}
int calc(int x)
{
    if(x==-1) return -1;
    return !x;
}
int getroot(int x)
{
    if(root[x]==x) return x;
    int tmp=getroot(root[x]);
    dis[x]^=dis[root[x]];
    return root[x]=tmp;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    int T,C;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++)
        {
            cin>>a[i].op>>a[i].x;
            if(a[i].op=='-'||a[i].op=='+') cin>>a[i].y;
        }
        for(int i=1;i<=m;i++)
        {
            if(a[i].op=='-')
            {
                int tx=++tot,ty=top[a[i].y];
                top[a[i].x]=tx,id[tx]=a[i].x;
                if(!fir[a[i].x]) fir[a[i].x]=tx;
                if(!fir[a[i].y]) fir[a[i].y]=ty;
                from[tx]=mp(ty,1);
                edge[ty].push_back(mp(tx,1));
                ans[tx]=ans[ty];
                if(ans[tx].flag) ans[tx].val=calc(ans[tx].val);
                else ans[tx].val^=1;
            }
            else if(a[i].op=='+')
            {
                int tx=++tot,ty=top[a[i].y];
                top[a[i].x]=tx,id[tx]=a[i].x;
                if(!fir[a[i].x]) fir[a[i].x]=tx;
                if(!fir[a[i].y]) fir[a[i].y]=ty;
                from[tx]=mp(ty,0);
                edge[ty].push_back(mp(tx,0));
                ans[tx]=ans[ty];
            }
            else
            {
                int tx=++tot;
                top[a[i].x]=tx,id[tx]=a[i].x;
                if(!fir[a[i].x]) fir[a[i].x]=tx;
                int tmp=getval(a[i].op);
                ans[tx]={1,tmp,tx};
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(ans[top[i]].flag)
            {
                ans[i]=ans[top[i]];
                if(i==fir[i]) q.push(i);
                continue;
            }
            if(ans[top[i]].from==ans[i].from&&ans[top[i]].val!=ans[i].val)
            {
                ans[i]={1,-1,i};
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=0;i<edge[u].size();i++)
            {
                int v=edge[u][i].fi,w=edge[u][i].se;
                ans[v]=ans[u];
                if(w==1) ans[v].val=calc(ans[v].val);
                if(v==top[id[v]])
                {
                    ans[id[v]]={1,ans[v].val,id[v]};
                    q.push(id[v]);
                }
                q.push(v);
            }
        }
        for(int i=1;i<=tot;i++)
        {
            if(ans[i].flag) continue;
            root[i]=ans[i].from;
            dis[i]=ans[i].val;
        }
        int c=0;
        for(int i=1;i<=tot;i++)
        {
            if(i!=top[id[i]]) continue;
            if(ans[i].flag) continue;
            int tx=getroot(i),ty=getroot(id[i]);
            if(tx!=ty)
            {
                root[tx]=id[i];
                dis[tx]=dis[i];
                continue;
            }
            if(dis[i]!=dis[id[i]]) q.push(id[i]),ans[id[i]]={1,-1,id[i]};
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=0;i<edge[u].size();i++)
            {
                int v=edge[u][i].fi,w=edge[u][i].se;
                ans[v]=ans[u];
                if(w==1) ans[v].val=calc(ans[v].val);
                if(v==top[id[v]])
                {
                    ans[id[v]]={1,ans[v].val,id[v]};
                    q.push(id[v]);
                }
                q.push(v);
            }
        }
        for(int i=1;i<=n;i++) if(ans[i].flag&&ans[i].val==-1) c++;
        cout<<c<<endl;
        for(int i=1;i<=tot;i++) edge[i].clear();
    }
	return 0;
}
