#include <bits/stdc++.h>
#define MAXN 400010
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1e9
using namespace std;
typedef pair<int,int> pa;
map <int,int> del[MAXN];
int C,T,n,m,ct,sum,st[MAXN],sw[4],id[MAXN]; //st:start value of each variable,sw:T/F/U
int pre[MAXN],vis[MAXN],c[MAXN],rub[MAXN],tt,ind[MAXN],od[MAXN];
int sb[MAXN],vv[MAXN]; //opposing side st/id
vector <pa> son[MAXN];
void recon(int x)
{
    del[pre[x]][x]=1;
    son[pre[x]].pb(mp(x,0));
}
queue <int> q;
int nc(int x,int op)
{
    if(c[x]==2) return c[x];
    return c[x]^op;
}
bool bfs(int ss,int col,int dd)
{
    while(q.size())
    {
        int x=q.front();
        vis[x]=0,c[x]=-1;
        q.pop();
    }
    for(int i=1;i<=tt;i++) c[rub[i]]=-1,vis[rub[i]]=0;
    tt=0;
    c[ss]=col,q.push(ss);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vv[x]=1;
        if(vis[x]) continue;
        vis[x]=1,rub[++tt]=x,sb[x]=dd;
        for(auto ty:son[x])
        {
            int y=ty.fi;
            if(del[x][y]) continue;
            int tn=nc(x,ty.se);
            if(c[y]!=-1 && c[y]!=tn) return false;
            c[y]=tn,q.push(y);
        }
    }
    return true;
}
int check(int x,int col)
{
    if(!bfs(x,col,0)) return INF;
    int cnt=0;
    for(int i=1;i<=tt;i++)
        if(c[rub[i]]==2  && rub[i]>=n+4 && rub[i]<=2*n+4) cnt++;
    return cnt;
}
int work()
{
    memset(vv,0,sizeof(vv));
    int ans=0;
    for(int i=0;i<=2;i++)
        ans+=check(sw[i],i);
    for(int i=1;i<=n;i++)
    {
        if(ind[i]) continue;
        int ta=INF;
        for(int j=0;j<=2;j++) ta=min(ta,check(st[i],j));
        ans+=ta;
    }
    for(int i=1;i<=n;i++)
        if((!vv[id[i]]) && od[i])
        {
            int ta=INF;
            for(int j=0;j<=2;j++) ta=min(ta,check(id[i],j));
            ans+=ta;
        }
    return ans;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--)
    {

        memset(c,-1,sizeof(c));
        memset(vis,0,sizeof(vis));
        memset(ind,0,sizeof(ind));
        memset(od,0,sizeof(od));
        ct=sum=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) st[i]=++ct;
        sw[0]=++ct,sw[1]=++ct,sw[2]=++ct;
        for(int i=1;i<=n;i++) id[i]=++ct;
        for(int i=1;i<=ct;i++) son[i].clear(),del[i].clear();
        for(int i=1;i<=n;i++) pre[id[i]]=st[i],son[st[i]].pb(mp(id[i],0));
        char op;
        int x,y;
        while(m--)
        {
            cin>>op;
            if(op=='T')
            {
                cin>>x;
                recon(id[x]);
                pre[id[x]]=sw[0],son[sw[0]].pb(mp(id[x],0));
            }
            else if(op=='F')
            {
                cin>>x;
                recon(id[x]);
                pre[id[x]]=sw[1],son[sw[1]].pb(mp(id[x],0));
            }
            else if(op=='U')
            {
                cin>>x;
                recon(id[x]);
                pre[id[x]]=sw[2],son[sw[2]].pb(mp(id[x],0));
            }
            else if(op=='+')
            {
                cin>>y>>x;
                recon(id[y]);
                pre[id[y]]=id[x],son[id[x]].pb(mp(id[y],0));
            }
            else
            {
                cin>>y>>x;
                recon(id[y]);
                pre[id[y]]=id[x],son[id[x]].pb(mp(id[y],1));
            }
        }
        for(int i=0;i<=3;i++) bfs(sw[i],2,++sum);
        for(int i=1;i<=n;i++) bfs(st[i],2,++sum);
        for(int i=1;i<=n;i++)
            if(sb[st[i]]!=sb[id[i]])
               son[id[i]].pb(mp(st[i],0)),ind[i]++;
        for(int i=1;i<=n;i++)
            for(auto y:son[id[i]])
                if(!del[id[i]].count(y.fi))
                    od[i]++;
        cout<<work()<<'\n';
    }
    return 0;
}
