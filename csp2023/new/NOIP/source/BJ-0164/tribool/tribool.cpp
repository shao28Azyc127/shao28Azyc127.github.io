#include <bits/stdc++.h>
#define int long long
#define MAXN 100010
#define INF LONG_LONG_MAX
using namespace std;
int c,_T,n,m,x[MAXN],y[MAXN],num[MAXN],t[MAXN];
char v[MAXN];
namespace subtask1
{
    queue<int> Q;
    int vis[MAXN];
    vector<int> p[MAXN];
    void Clear1()
    {
        for(int i=1;i<=n;i++) p[i].clear();
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
    }
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>_T;
    if(c<=2)
    {
        char f[131];
        f['T']=1;f['F']=-1;f['U']=0;f['+']=1;f['-']=-1;
        while(_T--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>v[i];
                if(v[i]=='T'||v[i]=='U'||v[i]=='F') cin>>x[i];
                else cin>>x[i]>>y[i];
            }
            int tmp=1;
            for(int i=1;i<=n;i++) tmp*=3;
            int ans=INF;
            for(int S=0;S<tmp;S++)
            {
                int ttt=S;
                for(int i=1;i<=n;i++)
                {
                    int tt=ttt%3;
                    if(tt==0) num[i]=0;
                    else if(tt==1) num[i]=1;
                    else num[i]=-1;
                    ttt/=3;
                }
                //for(int i=1;i<=n;i++) cout<<num[i]<<" ";cout<<endl;
                for(int i=1;i<=n;i++) t[i]=num[i];
                for(int i=1;i<=m;i++)
                {
                    if(v[i]=='T'||v[i]=='U'||v[i]=='F')
                    {
                        num[x[i]]=f[v[i]];
                    }
                    else
                    {
                        num[x[i]]=f[v[i]]*num[y[i]];
                    }
                }
                bool flag=1;
                int cnt=0;
                for(int i=1;i<=n;i++)
                {
                    if(num[i]!=t[i])
                    {
                        flag=0;
                        break;
                    }
                    cnt+=(num[i]==0);
                }
                //for(int i=1;i<=n;i++) cout<<t[i]<<" ";cout<<endl;
                //for(int i=1;i<=n;i++) cout<<num[i]<<" ";cout<<endl;
                if(!flag) continue;
                ans=min(ans,cnt);
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    if(3<=c&&c<=4)
    {
        char f[131];
        f['T']=1;f['F']=-1;f['U']=0;f['+']=1;f['-']=-1;
        while(_T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;i++) num[i]=-2;
            for(int i=1;i<=m;i++)
            {
                cin>>v[i];
                if(v[i]=='T'||v[i]=='U'||v[i]=='F') cin>>x[i],num[x[i]]=f[v[i]];
                else cin>>x[i]>>y[i];
            }
            int ans=0;
            for(int i=1;i<=n;i++)
                if(!num[i])
                    ans++;
            cout<<ans<<'\n';
        }
        return 0;
    }//Clear
    if(5<=c&&c<=6)
    {
        //bfs
        using namespace subtask1;
        while(_T--)
        {
            Clear1();
            int ans=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>v[i];
                if(v[i]=='U')
                {
                    cin>>x[i],num[x[i]]=1;
                }
                else
                {
                    cin>>x[i]>>y[i];
                    num[x[i]]=num[y[i]];
                }
            }
for(int i=1;i<=n;i++) if(num[i]==1) ans++;
          /*  for(int i=1;i<=n;i++)
                if(num[i]==1)
                {
                    Q.push(i);
                    while(!Q.empty())
                    {
                        int u=Q.front();Q.pop();
                        for(int i=0;i<p[u].size();i++)
                        {
                            int v=p[u][i];
                            if(vis[v]) continue;
                            Q.push(v); vis[v]=1;
                        }
                    }
                }*/
            /*for(int i=1;i<=m;i++)
            {
                if(v[i]=='U') vis[x[i]]=1;
                else
                {
                    vis[x[i]]=vis[y[i]];
                }
                //for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
                //cout<<endl;
            }*/
            /*for(int i=m;i>=1;i--)
            {
                if(v[i]=='+')
                {
                        num[x[i]]=num[y[i]];
                        Q.push(x[i]);
                        vis[x[i]]=1;
                    while(!Q.empty())
                    {
                        int u=Q.front();Q.pop();
                        num[u]=num[y[i]];
                        for(int i=0;i<p[u].size();i++)
                        {
                            int v=p[u][i];
                            if(vis[v]) continue;
                            Q.push(v); vis[v]=1;
                        }
                    }
                }
                else
                {

                    Q.push(i);
                    while(!Q.empty())
                    {
                        int u=Q.front();Q.pop();
                        for(int i=0;i<p[u].size();i++)
                        {
                            int v=p[u][i];
                            if(vis[v]) continue;
                            Q.push(v); vis[v]=1;
                        }
                    }
                }
            }*/
            /*int ans=0;
            while(!Q.empty())
            {
                int u=Q.front();Q.pop();
                for(int i=0;i<p[u].size();i++)
                {
                    int v=p[u][i];
                    if(vis[v]) continue;
                    Q.push(v); vis[v]=1;
                }
            }
            for(int i=1;i<=n;i++) if(vis[i]) ans++;*/
            cout<<ans<<'\n';
        }
        return 0;
    }
    return 0;
}
/*
1 1
3 3
- 2 1
- 3 2
- 1 3
*/
