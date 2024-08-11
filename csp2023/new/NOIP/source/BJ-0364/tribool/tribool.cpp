#include <bits/stdc++.h>
using namespace std;

int a[100010];
int d[20][5];
int txt[30];
int n,m,ans;

int se()
{
    for(int i=1;i<=n;i++)
        txt[i]=a[i];
    for(int i=1;i<=m;i++)
    {
        if(d[i][0]==1)
            txt[d[i][1]]=1;
        else if(d[i][0]==2)
            txt[d[i][1]]=2;
        else if(d[i][0]==3)
            txt[d[i][1]]=3;
        else if(d[i][0]==4)
            txt[d[i][1]]=txt[d[i][2]];
        else if(d[i][0]==5)
        {
            if(txt[d[i][2]]==1)
                txt[d[i][1]]=1;
            else if(txt[d[i][2]]==2)
                txt[d[i][1]]=3;
            else if(txt[d[i][2]]==3)
                txt[d[i][1]]=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(txt[i]!=a[i])
            return -1;
    }
    return 0;
}

void dfs(int x,int u)
{
    if(x==(n+1))
    {
        int data=se();
        if(data==-1)
            return ;
        if(ans==-1)
            ans=u;
        else
            ans=min(ans,u);
        return ;
    }
    a[x]=1;
    dfs(x+1,u+1);
    a[x]=2;
    dfs(x+1,u);
    a[x]=3;
    dfs(x+1,u);
    return ;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==3 ||c==4)
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++)
            {
                char c;
                int x;
                scanf("%s%d",&c,&x);
                if(c=='U')
                    a[x]=1;
                else
                    a[x]=0;
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                    ans++;
            }
            printf("%d\n",ans);
        }
        return 0;
    }
    if(c==1 ||c==2)
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char c;
                cin>>c;
                if(c=='+')
                {
                    int x,y;
                    cin>>x>>y;
                    d[i][0]=4;
                    d[i][1]=x;
                    d[i][2]=y;
                }
                else if(c=='-')
                {
                    int x,y;
                    cin>>x>>y;
                    d[i][0]=5;
                    d[i][1]=x;
                    d[i][2]=y;
                }
                else
                {
                    int x;
                    cin>>x;
                    d[i][1]=x;
                    if(c=='U')
                        d[i][0]=1;
                    else if(c=='F')
                        d[i][0]=2;
                    else if(c=='T')
                        d[i][0]=3;
                }
            }
            ans=-1;
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}

