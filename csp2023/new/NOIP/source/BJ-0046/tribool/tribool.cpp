#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct Eric_cai
{
    int to,next;
};
Eric_cai EC[maxn<<1];
int head[maxn],cnt;
void add(int u,int v)
{
    EC[++cnt].to=v;
    EC[cnt].next=head[u];
    head[u]=cnt;
}
int c,T,n,m,p[maxn],ans[maxn],id[maxn],col[maxn],sum,num;
int f(int x)
{
    if(x<=n) return x+n;
    if(x>n && x<=2*n) return x-n;
    if(x==2*n+1) return 2*n+2;
    if(x==2*n+2) return 2*n+1;
    if(x==2*n+3) return 2*n+3;
}
int r(int x)
{
    if(x<=n) return x;
    if(x>n && x<=2*n) return x-n;
    return 0;
}
void dfs(int now)
{
    id[now]=num;
    for(int i=head[now];i!=0;i=EC[i].next) if(id[EC[i].to]==0) dfs(EC[i].to);
}
vector<int> g[maxn],vec;
bool check(int now,int cr)
{
    vec.push_back(now);
    bool ret=1;
    col[now]=cr;
    for(int i=0;i<g[now].size();i++)
    {
        if(col[g[now][i]]==-1) ret&=check(g[now][i],cr^1);
        ret&=(col[g[now][i]]==(col[now]^1));
    }
    return ret;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char op;
    int x,y,w;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=2*n+3;i++) p[i]=i,ans[i]=0,col[i]=-1;
        for(int i=1;i<=m;i++)
        {
            cin>>op>>x;
            if(op=='+')
            {
                cin>>y;
                p[x]=p[y];
            }
            if(op=='-')
            {
                cin>>y;
                p[x]=f(p[y]);
            }
            if(op=='T') p[x]=2*n+1;
            if(op=='F') p[x]=2*n+2;
            if(op=='U') p[x]=2*n+3;
        }
        for(int i=1;i<=n;i++)
        {
            add(p[i],i);
            add(i,p[i]);
        }
        for(int i=1;i<=2*n+3;i++)
        {
            if(id[i]!=0) continue;
            num++;
            dfs(i);
        }
        for(int i=1;i<=n;i++) g[id[i]].push_back(id[n+i]),g[id[n+i]].push_back(id[i]);
        g[id[2*n+1]].push_back(id[2*n+2]),g[id[2*n+2]].push_back(id[2*n+1]),g[id[2*n+3]].push_back(id[2*n+3]);
        for(int i=1;i<=num;i++)
        {
            if(col[i]!=-1) continue;
            vec.clear();
            if(check(i,0)==0) for(int j=0;j<vec.size();j++) ans[vec[j]]=1;
        }
        for(int i=1;i<=n;i++) sum+=(ans[id[i]]|ans[id[i+n]]);
        cout<<sum<<'\n';
        for(int i=1;i<=2*n+3;i++) g[i].clear(),col[i]=-1,p[i]=ans[i]=id[i]=head[i]=0;
        num=sum=cnt=0;
    }
    return 0;
}
