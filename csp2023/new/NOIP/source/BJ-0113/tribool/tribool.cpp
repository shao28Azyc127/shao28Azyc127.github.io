#include<bits/stdc++.h>
using namespace std;
int head[100013],tot=0;
struct node
{
    int to,nxt,op;
}e[200026];
void add(int x,int y,int op)
{
    e[++tot].to=y; e[tot].nxt=head[x]; head[x]=tot; e[tot].op=op;
    return;
}
int a[100013],n,m,T,ans=0,c;
int dfn[100013],low[100013],bel[100013],cnt=0,dcc=0;
bool in[100013];
stack<int> st;
void tanjan(int x)
{
    dfn[x]=low[x]=++cnt; st.push(x); in[x]=true;
    for(int i=head[x];i;i=e[i].nxt)
    {
        int y=e[i].to;
        if(!dfn[y])
        {
            tanjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(in[y])
            low[x]=min(low[x],low[y]);
    }
    if(low[x]==dfn[x])
    {
        int y=-1; dcc++;
        while(y!=x)
        {
           y=st.top(); st.pop();
           in[y]=false; bel[y]=dcc;
        }
    }
    return;
}
int mk[100013];
bool dfs(int x,int val)
{
    mk[x]=val;
    for(int i=head[x];i;i=e[i].nxt)
    {
        int y=e[i].to;
        if(bel[y]!=bel[x]) continue;
     //   printf("%d->%d\n",x,y);
        if(mk[y]==0)
        {
            if(dfs(y,val*e[i].op))
                return true;
        }
        else if(mk[y]==val*e[i].op) continue;
        else return true;
    }
    return false;
}
bool vis[100013];
void cont(int x)
{
    ans++; vis[x]=true;
    for(int i=head[x];i;i=e[i].nxt)
    {
        int y=e[i].to;
        if(vis[y]) continue;
        cont(y);
    }
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));
        memset(e,0,sizeof(e)); tot=0;
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=m;i++)
        {
            char s[5]; scanf("%s",s);
            int x,y;
            if(s[0]=='+'||s[0]=='-')
            {
                scanf("%d%d",&x,&y);
                if(s[0]=='+') a[x]=a[y];
                else a[x]=-a[y];
            }
            else
            {
                scanf("%d",&x);
                if(s[0]=='T') a[x]=n+1;
                else if(s[0]=='F') a[x]=n+2;
                else a[x]=n+3;
            }
        }
        for(int i=1;i<=n;i++)
        {
           // printf("%d ",a[i]);
            if(a[i]==-i)
            {
                add(n+3,i,1);
         //       printf("%d->%d",n+3,i);
                continue;
            }
            else if(a[i]!=i)
            {
                add(abs(a[i]),i,a[i]/abs(a[i]));
             //   printf("%d->%d",abs(a[i]),i);
            }
        }
       // printf("\n");
        memset(dfn,0,sizeof(dfn)); cnt=0;
        memset(low,0,sizeof(low)); dcc=0;
        memset(bel,0,sizeof(bel)); while(!st.empty()) st.pop();
        memset(in,0,sizeof(in));
        for(int i=1;i<=n+3;i++)
        {
            mk[i]=0;
            if(dfn[i]==0) tanjan(i);
        }
   //     for(int i=1;i<=n+3;i++) printf("-- %d\n",bel[i]);
        for(int i=1;i<=n;i++)
        {
            if(mk[i]!=0) continue;
            if(dfs(i,1)) mk[i]=3;
           // printf("mk[%d]=%d\n",i,mk[i]);
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(mk[i]!=3) continue;
            cont(i);
        }
        cont(n+3);
        printf("%d\n",ans-1);
    }
    return 0;
}
