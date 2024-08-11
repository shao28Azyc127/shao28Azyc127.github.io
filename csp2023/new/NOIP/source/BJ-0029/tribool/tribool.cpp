#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int sid,T,n,m,k;
//n+1:T
//-(n+1):F
//0:U
//i/-i
int a[N];
struct E{int v,op;};
vector <E> g[N],g2[N];
int In[N];
queue <int> q;
int inc[N];
void tope()
{
    for(int i=1;i<=n;i++) if(!In[i]) q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        inc[x]=0;
        for(int i=0;i<g2[x].size();i++)
        {
            int v=g2[x][i].v;
            In[v]--;
            if(!In[v]) q.push(v);
        }
    }
}
int vis[N];
int len,cir[N],ch,cnt;
int dfs(int x)
{
    int chk=0;
    cnt++;
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i].v,op=g[x][i].op;
        if(vis[v]) chk=1,ch^=op;
        else
        {
            int now=dfs(v);
            if(now) chk=1,ch^=op;
        }
    }
    if(chk) cir[++len]=x;
    return chk;
}
int ans;
void init()
{
    ans=0;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=0;i<=n+1;i++) inc[i]=1,vis[i]=0;
    for(int i=0;i<=n+1;i++) g[i].clear(),g2[i].clear(),In[i]=0;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&sid,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++)
        {
            char op;
            int x,y;
            scanf(" %c",&op);
            if('A'<=op&&op<='Z') scanf("%d",&x);
            else scanf("%d%d",&x,&y);
            if(op=='T') a[x]=n+1;
            if(op=='F') a[x]=-n-1;
            if(op=='U') a[x]=0;
            if(op=='+') a[x]=a[y];
            if(op=='-') a[x]=-a[y];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) g[0].push_back((E){i,0});
            else if(a[i]>0) g[a[i]].push_back((E){i,0}),g2[i].push_back((E){a[i],0}),In[a[i]]++;
            else g[-a[i]].push_back((E){i,1}),g2[i].push_back((E){-a[i],1}),In[-a[i]]++;
        }
        tope();
        //for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
        //for(int i=1;i<=n;i++) printf("%d ",inc[i]);printf("\n");
        len=0;ch=0;cnt=0;
        dfs(0);
        ans+=cnt-1;
        //printf("%d\n",ans);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]||!inc[i]) continue;
            len=0;ch=0;cnt=0;
            dfs(i);
            if(ch==1) ans+=cnt;
            //if(abs(a[i])!=i) printf("%d %d %d\n",ch,cnt,ans);
        }
        //printf("%d ",cnt);
        printf("%d\n",ans);
    }
    return 0;
}
