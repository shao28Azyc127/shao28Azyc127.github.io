#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e6+5;
struct node
{
    int v,next;
}edge[N*2];
int head[N],cnt,tmp,dfn[N],low[N],n,m,ans;
void add(int x,int y)
{
    edge[++cnt]=node{y,head[x]};
    head[x]=cnt;
}
bool vis[N];
stack <int> p;
int zhi[N];
bool dd[N],FLAG=1;
bool FL[N];
void tarjan(int x)
{
    dfn[x]=low[x]=++tmp;
    vis[x]=1;
    p.push(x);
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        memset(dd,0,sizeof(dd));
        int sum=0;
        dd[x]=1;
        if(x>3*n)
        {
            //cout<<"x"<<x<<endl;
            while(!p.empty())
            {
                int tmp=p.top();

                //cout<<tmp<<endl;
                p.pop();
                if(tmp>3*n&&tmp!=x) FLAG=0;
                vis[tmp]=0;
                if(FL[tmp]==1) continue;
                if(tmp>2*n&&tmp<=3*n)
                {
                    FL[tmp]=FL[tmp-n]=FL[tmp-2*n]=1;
                    sum++;
                }
                //cout<<"sum"<<sum<<endl;
                if(tmp==x) break;
            }
            if(!FLAG) return ;
            //cout<<sum<<"sum\n";
            ans+=sum;
            return ;
        }
        //cout<<x<<endl;
        while(!p.empty())
        {
            int tmp=p.top();
            p.pop();
            vis[tmp]=0;
            dd[tmp]=1;
            if(tmp>2*n)
            {
                if(dd[tmp-n]||dd[tmp-n-n])FLAG=0;
            }
            else if(tmp>n)
            {
                if(dd[tmp+n]||dd[tmp-n])FLAG=0;
            }
            else
            {
                if(dd[tmp+n]||dd[tmp+n+n])FLAG=0;
            }
            if(tmp>2*n&&tmp<=3*n) sum++;
            if(tmp==x) break;
        }
        if(!FLAG) return ;
        ans+=sum;
    }
}
//3*n+1 T 2*n+2 F 3*n+3 U
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        while(!p.empty()) p.pop();
        cin>>n>>m;
        cnt=0;
        tmp=0;
        ans=0;
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        memset(FL,0,sizeof(FL));
        FLAG=1;
        for(int i=1;i<=n*3+3;i++) zhi[i]=i;
        for(int i=1;i<=m;i++)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='U')
            {
                int x;
                cin>>x;
                zhi[x]=zhi[3*n+3];
                zhi[n+x]=zhi[3*n+3];
                zhi[n+n+x]=zhi[3*n+3];
            }
            if(tmp=='T')
            {
                int x;
                cin>>x;
                zhi[x]=zhi[3*n+1];
                zhi[n+x]=zhi[3*n+1];
                zhi[n+n+x]=zhi[3*n+1];
            }
            if(tmp=='F')
            {
                int x;
                cin>>x;
                zhi[x]=zhi[3*n+2];
                zhi[n+x]=zhi[3*n+2];
                zhi[n+n+x]=zhi[3*n+2];
            }
            if(tmp=='+')
            {
                int x,y;
                cin>>x>>y;
                zhi[x]=zhi[y];
                zhi[x+n]=zhi[y+n];
                zhi[x+n+n]=zhi[y+n+n];
            }
            if(tmp=='-')
            {
                int x,y;
                cin>>x>>y;
                zhi[x]=zhi[y+n];
                zhi[x+n]=zhi[y];
                zhi[x+n+n]=zhi[y+n+n];
            }
        }
        for(int i=1;i<=3*n+3;i++)
        {
            add(i,zhi[i]);
            add(zhi[i],i);
            //cout<<i<<" "<<zhi[i]<<endl;
        }
        int sum=0;
        for(int i=n+3;i>=1;i--)
        {
            int tmp=2147483647;
            if(i>n)
            {
                if(!dfn[2*n+i])
                {
                    FLAG=1;
                    ans=0;
                    tarjan(2*n+i);
                    if(!FLAG) continue;
                    //cout<<ans<<endl;
                    tmp=min(tmp,ans);
                    ans=0;
                    if(tmp==2147483647) tmp=0;
                    //cout<<"tmp"<<tmp<<endl;
                    sum+=tmp;
                    //cout<<"___________________\n";
                }
                continue;
            }

            if(!dfn[i])
            {
                ans=0;
                FLAG=1;
                tarjan(i);
                if(FLAG) tmp=min(tmp,ans);
                ans=0;
            }
            if(!dfn[i+n])
            {
                ans=0;
                FLAG=1;
                tarjan(i+n);
                if(FLAG) tmp=min(tmp,ans);
                ans=0;
            }
            if(!dfn[i+n+n])
            {
                ans=0;
                FLAG=1;
                tarjan(i+n+n);
                if(FLAG) tmp=min(tmp,ans);
                ans=0;
            }
            if(tmp==2147483647) tmp=0;
            //cout<<"tmp"<<tmp<<endl;
            sum+=tmp;
        }
        cout<<sum<<endl;
    }
    return 0;
}

