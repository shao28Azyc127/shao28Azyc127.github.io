#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (auto i=(a);i<=(b);++i)
#define per(i,a,b) for (auto i=(a);i>=(b);--i)

#define N int(1e5+10)

int c,T;
int n,m;

struct Node
{
    int c;
    int f;
    Node operator~()
    {
        Node res=*this;
        if (c==2||c==3) res.c^=1;
        else if (c==0) res.c=-1;
        else if (c==-1) res.c=0;
        return res;
    }
    Node():c(0),f(0){}
    Node(char ch)
    {
        f=0;
        if (ch=='T') c=2;
        else if (ch=='F') c=3;
        else c=1;
    }
};
Node res[N];
int ans[N];
vector<pair<int,bool>> adj[N];

void print(int i)
{
    cerr<<i<<": ";
    if (res[i].c==0) cerr<<res[i].f;
    if (res[i].c==-1) cerr<<"-"<<res[i].f;
    if (res[i].c==1) cerr<<"U";
    if (res[i].c==2) cerr<<"T";
    if (res[i].c==3) cerr<<"F";
    cerr<<'\n';
}

int dfs(int u,int c)
{
    int cnt=1;
    if (res[u].c<=0) ans[u]=c;
    else if (res[u].c==1) ans[u]=-1;
    else ans[u]=res[u].c;
    for (auto p:adj[u]) 
    {
        if (!ans[p.first]) cnt+=dfs(p.first,ans[u]^p.second);
        if (ans[p.first]!=(ans[u]^p.second)) 
        {
            ans[u]=-1;
            // cerr<<"ERROR on "<<u<<"->>"<<p.first<<": "<< ans[p.first]<<", "<<ans[u]<<'\n';
        }
    }
    return cnt;
}

void work()
{
    cin>>n>>m;
    // cerr<<n<<','<<m<<'\n';
    rep (i,1,n) res[i].c=0,res[i].f=i,adj[i].clear();
    memset(ans,0,sizeof ans);
    
    rep (i,1,m)
    {
        char op;
        cin>>op;
        if (op=='+') 
        {
            int u,v;
            cin>>u>>v;
            res[u]=res[v];
            // print(u);
        }
        else if (op=='-')
        {
            int u,v;
            cin>>u>>v;
            res[u]=~res[v];
            // print(u);
        }
        else
        {
            int u;
            cin>>u;
            res[u]=Node(op);
            // print(u);
        }
    }
    rep (i,1,n)
    {
        if (res[i].c==0) 
        {
            adj[i].emplace_back(res[i].f,false);
            adj[res[i].f].emplace_back(i,false);
        }
        else if (res[i].c==-1)
        {
            adj[i].emplace_back(res[i].f,true);
            adj[res[i].f].emplace_back(i,true);
        }
    }
    // rep (i,1,n) print(i);
    int ans=0;
    rep (i,1,n) if (!::ans[i]&&res[i].c>0)
    {
        // cerr<<i<<'\n';
        int tmp=dfs(i,0);
        if (::ans[i]<0) 
        {
            ans+=tmp;
            // cerr<<i<<'\n';
        }
    }
    rep (i,1,n) if (!::ans[i]) 
    {
        int tmp=dfs(i,2);
        if (::ans[i]<0) 
        {
            ans+=tmp;
            // cerr<<i<<'\n';
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c>>T;
    while (T--) work();
    return 0;
}