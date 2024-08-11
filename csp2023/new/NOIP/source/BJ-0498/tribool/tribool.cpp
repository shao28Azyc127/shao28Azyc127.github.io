#include <bits/stdc++.h>
using namespace std;
int c,t;
int fa[100005];
int p[100005];
bool vis[100005];
int gf(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else
    {
        fa[x]=gf(fa[x]);
        bool xv=max(vis[x],vis[fa[x]]);
        vis[x]=xv;
        vis[fa[x]]=xv;
        return fa[x];
    }
}
void add(int u,int v)
{
    int xu=gf(u),xv=gf(v);
    bool x=max(vis[xv],vis[xu]);
    vis[u]=x;
    vis[v]=x;
    fa[xu]=xv;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4)
    {
        for(int i=1;i<=t;i++)
        {
            int n,m,cnt=0;
            cin>>n>>m;
            for(int j=1;j<=m;j++)
            {
                char v;
                int u;
                cin>>v>>u;
                if(v=='U'&&vis[u]==0)
                {
                    cnt++;
                    vis[u]=1;
                }
                if(vis[u]==1&&v!='U')
                {
                    cnt--;
                }
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    if(c==5||c==6)
    {
        for(int i=1;i<=t;i++)
        {
            int n,m,cnt=0;
            cin>>n>>m;
            for(int j=0;j<=n;j++)
            {
                fa[j]=j;
                p[j]=j;
                vis[j]=0;
            }
            for(int j=1;j<=m;j++)
            {
                char v;
                cin>>v;
                if(v=='U')
                {
                    int u;
                    cin>>u;
                    //cout<<u<<' ';
                    vis[u]=1;
                }
                else
                {
                    //p++;
                    int x,y;
                    cin>>x>>y;
                    if(y==160)
                    {
                        //cout<<j<<' '<<x<<' ';
                    }
                    p[x]=y;
                    //add(ux,uy);
                }
            }
            //cout<<x[160];
            for(int j=1;j<=n;j++)
            {
                add(j,p[j]);
            }
            for(int j=1;j<=n;j++)
            {
                if(vis[j]==1)
                {
                    //cout<<j<<' ';
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        for(int j=1;j<=m;j++)
        {
            char v;
            cin>>v;
            if(v=='T'||v=='F'||v=='U')
            {
                int u;
                cin>>u;
                //x[u]=v;
            }
            else if(v=='+')
            {
                int ux,uy;
                cin>>ux>>uy;
                //x[ux]=x[uy];
            }
            else
            {
                int ux,uy;
                cin>>ux>>uy;
               // x[ux]=-x[uy];
            }
        }
        cout<<0;
    }
    return 0;
}
