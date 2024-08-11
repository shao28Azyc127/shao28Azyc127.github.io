#include<bits/stdc++.h>
using namespace std;
struct node{
    char op;
    int x,y;
}p[100010];
int k[60000],a[20],b[20];
int n,m;
int chai(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=x%3;
        b[i]=a[i];
        if(a[i]==2) cnt++;
        x/=3;
    }
    return cnt;
}
bool judge()
{
    for(int i=1;i<=m;i++)
    {
        char op=p[i].op;
        int x=p[i].x,y=p[i].y;
        if(op=='T') a[x]=0;
        if(op=='F') a[x]=1;
        if(op=='U') a[x]=2;
        if(op=='+') a[x]=a[y];
        if(op=='-')
        {
            if(a[y]==0) a[x]=1;
            if(a[y]==1) a[x]=0;
            if(a[y]==2) a[x]=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}
int en[100010],tim[100010],ls[100010];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    cin>>c>>T;
    if(c==1||c==2)
    {
        while(T--)
        {
            int ans=100;
            cin>>n>>m;
            int maxx=1;
            for(int i=1;i<=n;i++) maxx*=3;
            for(int i=1;i<=m;i++)
            {
                char op;
                int x,y;
                cin>>op;
                if(op=='U'||op=='T'||op=='F') cin>>x,p[i]={op,x,0};
                else cin>>x>>y,p[i]={op,x,y};
            }
            for(int i=0;i<=maxx;i++)
            {
                int qaq=chai(i);
                if(judge()) ans=min(ans,qaq);
            }
            cout<<ans<<'\n';
        }
    }
    if(c==3||c==4)
    {
        while(T--)
        {
            memset(en,0,sizeof(en));
            memset(tim,0,sizeof(tim));
            int n,m,ans=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                int x;
                char op;
                cin>>op;
                if(op=='T') cin>>x,en[x]=1;
                else if(op=='F') cin>>x,en[x]=0;
                else
                {
                    cin>>x;
                    tim[x]++;
                    en[x]=2;
                }
            }
            for(int i=1;i<=n;i++) if(en[i]==2) ans++;
            cout<<ans<<'\n';
        }
    }
    if(c==5||c==6)
    {
        while(T--)
        {
            int n,m,ans=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char op;
                int x,y;
                cin>>op;
                if(op=='U') y=0;
                if(op=='U') cin>>x,tim[x]++,en[x]=1;
                else
                {
                    cin>>x>>y,en[x]=en[y],tim[x]=tim[y];
                    if(en[x]==1) tim[x]++;
                }
                p[i]={op,x,y};
            }
            for(int i=1;i<=n;i++) if(en[i]==1&&tim[i]==1) ls[i]=1;
            for(int i=1;i<=m;i++)
            {
                node qaq=p[i];
                char op=qaq.op;
                int x=qaq.x,y=qaq.y;
                if(op=='U') y=0;
                if(op=='U') tim[x]++,ls[x]=1;
                else
                {
                    ls[x]=ls[y],tim[x]=tim[y];
                    if(ls[x]==1) tim[x]++;
                }
                p[i]={op,x,y};
            }
            for(int i=1;i<=n;i++) if(ls[i]==1) ans++;
            cout<<ans<<'\n';
        }

    }
    return 0;

}

