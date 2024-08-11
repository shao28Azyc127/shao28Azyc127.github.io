# include <bits/stdc++.h>
# define INF 0x7ffffff
using namespace std;
const int maxn = 100005;
int t, c, n , m;
int yj[maxn]; // mei ge dian de UTF
vector <int> G[maxn];
bool vis[maxn]; // biaoji
void bfs(int x)
{
    queue <int> q;
    q.push(x);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for (auto v:G[u])
        {
            yj[v] = yj[u];
            q.push(v);
        }
    }
}
int uu[1025][maxn];
bool visbb[maxn];
int cnt=0;
void dfs(int x)
{
    if (x==n+1) return ;

    for (int i=0; i<=2; ++i)
    {
        yj[x] = i;
        cnt++;
        for (int j=1; j<=n; j++)
        {
            uu[cnt][j] = yj[j];
        }
        dfs(x+1);
    }
}



void print()
{
    for (int i=1; i<=n; ++i)
    {
        cout<<yj[i]<<" ";
    }
    cout<<endl;
}
void printuu()
{
    for (int i=1; i<=cnt; ++i)
    {
        for (int j=1; j<=n; ++j)
        {
            cout<<uu[i][j]<<" ";
        }
        cout<<endl;
    }
}
int pp[1025][maxn];
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin>>c>>t;
    while (t--)
    {
        memset(yj, 0, sizeof(yj));
        memset(uu, 0, sizeof(uu));
        cin>>n>>m;
        //cout<<n<<" "<<m<<endl;

        if (c==1 || c==2)
        {
            dfs(1);

            for (int i=1; i<=cnt; i++)
            {
             for (int j=1; j<=n; ++j)
             {
                 pp[i][j] = uu[i][j];
             }
            }
            //for (int i=1; i<=cnt; ++i)
            //{
             //   for (int j=1; j<=n; ++j)
            //    {
            //        cout<<pp[i][j]<<" ";
            //    }
            //    cout<<endl;
           // }
            //cout<<"-----";
            int ans= INF;
            for (int i=1; i<=m; ++i)
            {
                string s;
                cin>>s;
                if (s=="U")
                {
                    int v;
                    cin>>v;
                    for (int j=1; j<=cnt; j++)
                    {
                        uu[j][v] = 2;
                    }
                }
                else if( s=="T")
                {
                    int v;
                    cin>>v;
                    for (int j=1; j<=cnt; ++j)
                    {
                        uu[j][v] = 1;
                    }
                }
                else if(s=="F")
                {
                    int v;
                    cin>>v;
                    for (int j=1; j<=cnt; j++)
                    {
                        uu[j][v] = 0;
                    }
                }
                else if(s=="+")
                {
                    int u, v;
                    cin>>u>>v;
                    for (int j=1; j<=cnt; j++)
                    {
                        uu[j][u] = uu[j][v];
                    }
                }
                else if(s=="-")
                {
                    int u, v;
                    cin>>u>>v;
                    for (int j=1; j<=cnt; ++j)
                    {
                        if (uu[j][v] == 2) uu[j][u] = 2;
                        else if(uu[j][v]==1) uu[j][u] = 0;
                        else uu[j][u] = 1;
                    }
                }
            }
        int flag=0;
        int ct=0;
        for (int i=1; i<=cnt; i++)
        {
            ct = 0;
            flag = 0;
            for (int j=1; j<=n; ++j)
            {
                if (uu[i][j]!=pp[i][j]) flag=1;
                if (uu[i][j] == 2)ct++;

            }
            if (!flag)ans = min(ans, ct);
        }
        //for (int i=1; i<=cnt; i++)
        //{
         //   for (int j=1; j<=n; j++)
         //   {
         //       cout<<uu[i][j]<<" ";
         //   }
        //    cout<<endl;
        //}
        cout<<ans<<endl;
        }

        if (c==3 || c==4)
        {
            for (int i=1; i<=m; ++i)
            {
                string s;
                int v;
                cin>>s>>v;
                if (s=="U")
                {
                    yj[v] = 2;
                }
                else if(s=="T")
                {
                    yj[v] = 1;
                }
                else yj[v] = 0;
                //print();
            }
            int ans=0;
            for (int i=1; i<=n; ++i)
            {
                if (yj[i]==2) ans++;
            }
            cout<<ans<<endl;
        }

        if (c==5|| c==6)
        {
            for (int i=1; i<=m; ++i)
            {
                string s;
                cin>>s;
                if (s=="U")
                {
                    int v;
                    cin>>v;
                    yj[v] = 2;
                }
                if (s=="+")
                {
                    int u, v;
                    cin>>u>>v;
                    yj[u] = yj[v];
                }
            }

            //print();
            int ans=0;
            for (int i=1; i<=n; ++i)
            {
                if (yj[i] == 2) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
