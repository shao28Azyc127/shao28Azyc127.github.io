#include<iostream>
#include<cstring>
using namespace std;

const int MXN=1000010;
int a[MXN],vis[MXN],b[MXN];
char Op[MXN];
int X[MXN],Y[MXN];
char ans[MXN];
int Mnret=1e9;

void dfs(int o,int n,int m)
{
    if(o==n)
    {
        for(int i=1;i<=n;i++) b[i]=vis[i];
        for(int i=1;i<=m;i++)
        {
            char op=Op[i];
            if(op=='U')
            {
                int x=X[i];
                // cout<<"Hey "<<x<<' '<<b[x]<<' ';
                b[x]=0;// cout<<b[x]<<endl;
            }
            else if(op=='T')
            {
                int x=X[i];
                b[x]=1;
            }
            else if(op=='F')
            {
                int x=X[i];
                b[x]=-1;
            }
            else if(op=='+')
            {
                int x,y;x=X[i];
                y=Y[i];b[x]=b[y];
            }
            else
            {
                int x,y;x=X[i];
                y=Y[i];b[x]=-b[y];
            }
        }
        int num=0;
        for(int i=1;i<=n;i++) if(vis[i]!=b[i]) return ;
        for(int i=1;i<=n;i++) if(!b[i]) num++;
        // for(int i=1;i<=n;i++) cout<<b[i]<<' '; cout<<endl;
        // for(int i=1;i<=n;i++) cout<<vis[i]<<' '; cout<<endl;
        Mnret=min(Mnret,num);return ;
    }
    vis[o+1]=1;dfs(o+1,n,m);
    vis[o+1]=0;dfs(o+1,n,m);
    vis[o+1]=-1;dfs(o+1,n,m);
}

void Solve1() 
{
    // memset(X)
    Mnret=1e9;
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        char op;cin>>op;
        Op[i]=op;
        if(op=='U')
        {
            int x;cin>>x;
            X[i]=x;
            a[x]=0;
        }
        else if(op=='T')
        {
            int x;cin>>x;
            X[i]=x;
            a[x]=1;
        }
        else if(op=='F')
        {
            int x;cin>>x;
            X[i]=x;
            a[x]=-1;
        }
        else 
        {
            int x,y;cin>>x>>y;
            X[i]=x,Y[i]=y;
            if(a[y]==0) a[x]=0;
        }
        // cout<<Op[i]<<' '<<X[i]<<' '<<Y[i]<<endl;
    }
    dfs(0,n,m);cout<<Mnret<<endl;
}

void Solve2()
{
    // memset(a,0,sizeof a);
    int n,m;cin>>n>>m;// cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++) a[i]=1;
    for(int i=1;i<=m;i++)
    {
        char op;int x;
        cin>>op>>x;
        if(op=='T') a[x]=1;
        if(op=='F') a[x]=-1;
        if(op=='U') a[x]=0;
    }int ret=0;
    for(int i=1;i<=n;i++) if(a[i]==0) ret++;
    // for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<ret<<endl;
}

void Solve3()
{
    memset(ans,0,sizeof ans);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=1;
    for(int i=1;i<=m;i++)
    {
        char op;cin>>op;
        Op[i]=op;
        if(op=='U')
        {
            int x;cin>>x;
            X[i]=x;
            a[x]=0;
        }
        else 
        {
            int x,y;cin>>x>>y;
            X[i]=x,Y[i]=y;
            if(a[y]==0) a[x]=0;
            else a[x]=1;
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++) if(a[i]==0) ret++;
    cout<<ret<<endl; 
}

void dfs3(int o)
{
    // cout<<o<<endl;
    if(abs(a[o])==o) 
    {
        if(a[o]==-o) ans[o]='U';
        else ans[o]='T';
        return ;
    }
    dfs3(abs(a[o]));
    if(a[o]<0) 
    {
        if(ans[abs(a[o])]=='T') ans[o]='F';
        if(ans[abs(a[o])]=='U') ans[o]='U';
        else ans[o]='T';
    }
    else ans[o]=ans[abs(a[o])];
}

void Solve()
{
    memset(ans,0,sizeof ans);
    memset(a,0,sizeof a);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=m;i++)
    {
        char op;cin>>op;
        if(op=='+') 
        {
            int x,y;cin>>x>>y;
            a[x]=a[y];
        }
        else if(op=='-')
        {
            int x,y;cin>>x>>y;
            a[x]=-a[y];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) continue;
        int o=i;dfs3(o);
    }
    int ret=0;
    for(int i=1;i<=n;i++) if(ans[i]=='U') ret++;
    // for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<ret<<endl; 
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--)
    {
        if(c>=1&&c<=2) Solve1();
        else if(c>=3&&c<=4) Solve2();
        else if(c>=5&&c<=6) Solve3();
        else Solve();
    }
    return 0;
}