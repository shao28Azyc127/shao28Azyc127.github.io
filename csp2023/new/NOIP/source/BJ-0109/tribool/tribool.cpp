#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N=1e5+5;
int c,t;
int n,m;
int val[N],vis[N];
vector<int> vec[N];
int fa[N],mark[N],sum[N],to[N];
int bfs(int key)
{
    int i;
    queue<int> q;
    int sum=0;
    q.push(key);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        vis[temp]=1;
        sum++;
        for(i=0; i<vec[temp].size(); i++)
            if(!vis[vec[temp][i]])
                q.push(vec[temp][i]);
    }
    return sum-1;
}
int find(int key)
{
    if(key==fa[key]) return key;
    find(fa[key]);
    to[key]=(to[key]+to[fa[key]])%2;
    fa[key]=fa[fa[key]];
    return fa[key];
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    int i,j;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1; i<=n+1; i++)
            val[i]=i;
        memset(vis,0,sizeof(vis));
        for(i=1; i<=m; i++)
        {
            char op;
            cin>>op;
            if(op=='-')
            {
                int a,b;
                cin>>a>>b;
                val[a]=-val[b];
            }
            else if(op=='+')
            {
                int a,b;
                cin>>a>>b;
                val[a]=val[b];
            }
            else if(op=='T')
            {
                int temp;
                cin>>temp;
                val[temp]=n+1;
            }
            else if(op=='F')
            {
                int temp;
                cin>>temp;
                val[temp]=-(n+1);
            }
            else
            {
                int temp;
                cin>>temp;
                val[temp]=0;
            }
        }
        int ans=0;
        for(i=0; i<=n+1; i++)
            vec[i].clear();
        for(i=1; i<=n; i++)
            vec[abs(val[i])].push_back(i);
        bfs(n+1);
        ans+=bfs(0);
        for(i=1; i<=n; i++)
            fa[i]=i,to[i]=0,sum[i]=1,mark[i]=0;
        for(i=1; i<=n; i++)
            if(!vis[i])
            {
                if(find(i)==find(abs(val[i])))
                {
                    if(!((to[i]+to[abs(val[i])])%2==(val[i]<0)))
                        mark[find(i)]=1;
                }
                else
                {
                    sum[find(abs(val[i]))]+=sum[find(i)];
                    to[find(i)]=(to[i]+(val[i]<0)+to[abs(val[i])])%2;
                    fa[find(i)]=find(abs(val[i]));
                    mark[find(abs(val[i]))]|=mark[find(i)];
                }
            }
        for(i=1; i<=n; i++)
            if(!vis[i] && fa[i]==i && mark[i]==1)
                ans+=sum[i];
        cout<<ans<<endl;
    }
    return 0;
}
