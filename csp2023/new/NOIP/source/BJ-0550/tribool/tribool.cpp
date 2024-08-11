#include <bits/stdc++.h>

using namespace std;
int c,_t;
int f[300003];
int vis1[300003],if_u[300003];
int dfn[300003],low[300003],vis[300003],num;
int belong[300003];
int n,m;
int ans;
char op;
int tot,h[300003],tot1;
stack <int> s;
struct node{
    int v,next;
}e[900003];
void addedge(int u,int v)
{
    e[++tot].v=v;
    e[tot].next=h[u];
    h[u]=tot;
}
void bianliu(int x){
    vis1[x]=1;
    if(x<=n)
    {
        ans++;
        //printf("x=%d\n",x);
    }

    for(int i=h[x];i;i=e[i].next)
    {
        int v=e[i].v;
        if(!vis1[v])
            bianliu(v);
    }

}
void dfs(int x)
{
    //printf("dfs(%d)\n",x);
    dfn[x]=low[x]=++tot1;
    //printf("tot1=%d",tot1);
    vis[x]=1;
    s.push(x);

    for(int j=h[x];j;j=e[j].next)
    {
        int v=e[j].v;
        //printf("%d ",v);
        if(!dfn[v])
        {
            dfs(v);
            low[x]=min(low[x],low[v]);
            //printf("low[%d]=%d low[%d]=%d\n",x,low[x],v,low[v]);
        }
        if(vis[v])
        {low[x]=min(low[x],low[v]);

        }
    }
    if(low[x]==dfn[x])
    {
        num++;
        while(s.top()!=x)
        {
            int t=s.top();
            vis[t]=0;
            belong[t]=num;
            s.pop();
        }
        int t=s.top();
        vis[t]=0;
        belong[t]=num;
        s.pop();
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&_t);
    //printf("c=%d _t=%d\n",c,_t);
    while(_t--)
    {
        ans=0;
        tot1=0;
        num=0;
        tot=0;
        memset(h,0,sizeof(h));
        memset(if_u,0,sizeof(if_u));
        memset(dfn,0,sizeof(dfn));
        memset(vis1,0,sizeof(vis1));
        memset(vis,0,sizeof(vis));
        memset(belong,0,sizeof(belong));
        memset(low,0,sizeof(low));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=2*n;i++)
        {
            f[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int t1,t2;
            cin>>op;
            if(op=='T')
            {
                scanf("%d",&t1);
                f[t1]=2*n+1;
                f[t1+n]=2*n+2;
            }
            if(op=='F')
            {
                scanf("%d",&t1);
                f[t1]=2*n+2;
                f[t1+n]=2*n+1;
            }
            if(op=='U')
            {
                scanf("%d",&t1);
                f[t1]=2*n+3;
                f[t1+n]=2*n+3;
            }
            if(op=='+')
            {
                scanf("%d%d",&t1,&t2);
                f[t1]=f[t2];
                f[t1+n]=f[t2+n];
            }
            if(op=='-')
            {
                scanf("%d%d",&t1,&t2);
                f[t1]=f[t2+n];
                f[t1+n]=f[t2];
            }
        }
        for(int i=1;i<=2*n;i++)
        {
            addedge(i,f[i]);
            addedge(f[i],i);
            //printf("addedge(%d,%d)\n",i,f[i]);
            //printf("addedge(%d,%d)\n",f[i],i);
        }
        //printf("tot=%d",tot);
        //printf("\n");
        //printf("\n");


            //printf("%d\n",4);
            //for(int j=h[4];j;j=e[j].next)
            ///{

            //    printf("%d ",e[j].v);
            //}
            //printf("\n");

        //printf("\n");
        //printf("\n");
        //printf("ans=%d\n",ans);
        bianliu(2*n+3);
        //printf("ans=%d\n",ans);
        for(int i=1;i<=n*2+2;i++)
        {

            if(dfn[i]!=0) continue;
            if(vis1[i]!=0) continue;

            dfs(i);


        }
        for(int i=1;i<=n;i++)
        {
            /*printf("f[%d]=%d ",i,f[i]);
            printf("belong[%d]=%d ",i,belong[i]);
            printf("dfn[%d]=%d ",i,dfn[i]);
            printf("low[%d]=%d \n",i,low[i]);*/
            if(belong[i]==belong[i+n])
            {
                if_u[belong[i]]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if((if_u[belong[i]])&&(!vis1[i]))
            {
                vis1[i]=1;
                ans++;
            }
        }
        //for(int i=1;i<=n;i++)
        //{
//
        //    printf("vis1[%d]=%d\n",i,vis1[i]);
        //}
        printf("%d\n",ans);

    }





    return 0;
}
/*
T   2*n+1;
F   2*n+2;
U   2*n+3;

*/
